#include "unity/unity.h"  
#include "include.h"  
#include <stdlib.h>  
#include <string.h>  
  
#define STACK_SIZE (64 * 1024)  
  
// Test data structures  
typedef struct {  
    int value;  
    const char* message;  
} test_data_t;  
  
// Global test variables  
static fcontext_t child_ctx;  
static void *test_stack;  
static test_data_t test_data;  
  
// Unity framework functions  
void setUp(void) {  
    test_stack = malloc(STACK_SIZE);  
    TEST_ASSERT_NOT_NULL(test_stack);  
    test_data.value = 0;  
    test_data.message = "initial";  
}  
  
void tearDown(void) {  
    if (test_stack) {  
        free(test_stack);  
        test_stack = NULL;  
    }  
}  
  
// Simple context function that modifies data and returns  
void simple_context_function(transfer_t t) {  
    test_data_t *data = (test_data_t*)t.data;  
    data->value = 42;  
    data->message = "modified";  
      
    // Jump back to main context  
    jump_fcontext(t.fctx, data);  
}  
  
// Test basic context switching with data modification  
void test_context_data_modification(void) {  
    // Initialize test data  
    test_data.value = 0;  
    test_data.message = "initial";  
      
    // Create context  
    child_ctx = make_fcontext(  
        (char*)test_stack + STACK_SIZE,  
        STACK_SIZE,  
        simple_context_function  
    );  
      
    TEST_ASSERT_NOT_NULL(child_ctx);  
      
    // Jump to context and get modified data back  
    transfer_t result = jump_fcontext(child_ctx, &test_data);  
      
    // Verify data was modified  
    test_data_t *returned_data = (test_data_t*)result.data;  
    TEST_ASSERT_EQUAL_INT(42, returned_data->value);  
    TEST_ASSERT_EQUAL_STRING("modified", returned_data->message);  
}  
  
// Context function that demonstrates multiple switches  
void multi_switch_context(transfer_t t) {  
    test_data_t *data = (test_data_t*)t.data;  
      
    // First switch - set initial value  
    data->value = 10;  
    jump_fcontext(t.fctx, data);  
      
    // Second switch - modify value  
    data->value = 20;  
    jump_fcontext(t.fctx, data);  
      
    // Third switch - final value  
    data->value = 30;  
    jump_fcontext(t.fctx, data);  
}  
  
// Test multiple context switches  
void test_multiple_context_switches(void) {  
    test_data.value = 0;  
      
    // Create context  
    child_ctx = make_fcontext(  
        (char*)test_stack + STACK_SIZE,  
        STACK_SIZE,  
        multi_switch_context  
    );  
      
    // First switch  
    transfer_t result1 = jump_fcontext(child_ctx, &test_data);  
    TEST_ASSERT_EQUAL_INT(10, test_data.value);  
      
    // Second switch  
    transfer_t result2 = jump_fcontext(result1.fctx, &test_data);  
    TEST_ASSERT_EQUAL_INT(20, test_data.value);  
      
    // Third switch  
    jump_fcontext(result2.fctx, &test_data);  
    TEST_ASSERT_EQUAL_INT(30, test_data.value);  
}  
  
// Callback function for ontop test  
transfer_t ontop_callback(transfer_t t) {  
    test_data_t *data = (test_data_t*)t.data;  
    data->value = data->value * 2;  
    return t;  
}  
  
// Test ontop functionality  
void test_ontop_transformation(void) {  
    test_data.value = 5;  
      
    // Create context  
    child_ctx = make_fcontext(  
        (char*)test_stack + STACK_SIZE,  
        STACK_SIZE,  
        simple_context_function  
    );  
      
    // Jump to context first  
    transfer_t result1 = jump_fcontext(child_ctx, &test_data);  
    TEST_ASSERT_EQUAL_INT(42, test_data.value);  
      
    // Use ontop to transform data  
    test_data.value = 5; // Reset  
    ontop_fcontext(result1.fctx, &test_data, ontop_callback);
      
    // Verify transformation  
    TEST_ASSERT_EQUAL_INT(10, test_data.value);  
}

typedef struct {
    int operation;
    int operand1;
    int operand2;
    int result;
} math_operation_t;

  typedef struct {
      char* message;
      int length;
  } string_data_t;

static fcontext_t worker_ctx;
static void *worker_stack;
static math_operation_t math_op;
static string_data_t string_data;
static int calculation_result = 0;

void math_worker(transfer_t t) {
    math_operation_t* op = (math_operation_t*)t.data;
    switch (op->operation) {
        case 0: // ADD
            op->result = op->operand1 + op->operand2;
            break;
        case 1: // MULTIPLY
            op->result = op->operand1 * op->operand2;
            break;
        case 2: // SUBTRACT
            op->result = op->operand1 - op->operand2;
            break;
    }
     calculation_result = op->result;
     jump_fcontext(t.fctx, &op->result);
 }
 
 void string_worker(transfer_t t) {
     string_data_t* data = (string_data_t*)t.data;
     if (strcmp(data->message, "hello") == 0) {
         data->message = "world";
         data->length = 5;
     } else {
         data->message = "processed_data";
         data->length = 15;
     }
     jump_fcontext(t.fctx, data);
 }

// transfer_t ontop_callback(transfer_t t) {
//     math_operation_t* op = (math_operation_t*)t.data;
//     op->operand1 *= 2;
//     op->operand2 *= 2;
//     return t;
// }
 
void test_arithmetic_operations(void) {
    math_op.operation = 0; // ADD
    math_op.operand1 = 10;
    math_op.operand2 = 32;

    worker_ctx = make_fcontext(
        (char*)worker_stack + STACK_SIZE,
        STACK_SIZE,
        math_worker
    );

    transfer_t result = jump_fcontext(worker_ctx, &math_op);
    TEST_ASSERT_EQUAL_INT(42, *(int*)result.data);
    TEST_ASSERT_EQUAL_INT(42, calculation_result);
}
        
  
int main(void) {  
    UNITY_BEGIN();  
      
    RUN_TEST(test_context_data_modification);  
//    RUN_TEST(test_multiple_context_switches);  
    RUN_TEST(test_ontop_transformation);  
    RUN_TEST(test_arithmetic_operations);       
    return UNITY_END();  
}
