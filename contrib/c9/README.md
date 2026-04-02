# c9

NOTE (2022-06-27): the library's (yep, it's going to be a library)
API is getting completely revamped, and examples are being added.
Use either an older version, or expect API breakage.

A lightweight library for implmeneting 9p clients and servers in C.

This is 9p client and server implementation which aims to be correct,
small and secure, targetting mainly low-resource MCUs.

`proto.[ch]`: lowest level of the library, contains nothing but
(de)serealization of the protocol messages and tag (de)allocation.

`fs.h`: higher level, blocking file API based on POSIX.

`fs9p.[ch]`: blocking file API implementation for 9p - having a
context created with `proto.[ch]` one can use POSIX-like file API to
work with a remote filesystem.

Goals:

* portability: zero external dependencies, no POSIX, just C
* no dynamic memory allocation
* security: no crashes due to incoming data
