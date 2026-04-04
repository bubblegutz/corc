project('context', 'c')  

build_tests = get_variable('BUILD_TESTS', 'true') == 'true'

system = host_machine.system()  

cross_cc = get_variable('CC', '')
cross_target = ''
  
if cross_cc.contains('aarch64')
  cross_target = 'aarch64'  
elif cross_cc.contains('arm')  
  cross_target = 'arm'  
elif cross_cc.contains('x86_64')  
  cross_target = 'x86_64'  
endif  
  
if cross_target != ''  
  cpu = cross_target  
else  
  cpu = build_machine.cpu()  
endif  

arch = ''  
if cpu == 'x86_64' or cpu == 'amd64'  
  arch = 'x86_64'  
elif cpu == 'i386' or cpu == 'i686'  
  arch = 'i386'  
elif cpu == 'aarch64' or cpu == 'arm64'  
  arch = 'arm64'  
elif cpu == 'arm'  
  arch = 'arm'  
elif cpu == 'ppc64' or cpu == 'powerpc64'  
  arch = 'ppc64'  
elif cpu == 'ppc' or cpu == 'powerpc'  
  arch = 'ppc32'  
elif cpu == 'mips64'  
  arch = 'mips64'  
elif cpu == 'mips'  
  arch = 'mips32'  
elif cpu == 'riscv64'  
  arch = 'riscv64'  
elif cpu == 's390x'  
  arch = 's390x'  
else  
  error('Unsupported architecture: ' + cpu)  
endif  
  
binary = ''  
abi = ''  
if system == 'linux'  
  binary = 'elf'  
  abi = 'sysv'  
  if arch == 'arm' or arch == 'arm64'  
    abi = 'aapcs'  
  endif  
elif system == 'darwin'  
  binary = 'macho'  
  abi = 'sysv'  
elif system == 'freebsd' or system == 'netbsd' or system == 'openbsd'  
  binary = 'elf'  
  abi = 'sysv'  
elif system == 'windows' or system == 'cygwin'  
  binary = 'pe'  
  abi = 'ms'  
else  
  error('Unsupported OS: ' + system)  
endif  
  
assembler = 'gas'  
suffix = '.S'  
if system == 'windows' or system == 'cygwin'  
  assembler = 'masm'  
  suffix = '.asm'  
endif  
  
platform_suffix = arch + '_' + abi + '_' + binary + '_' + assembler + suffix  

if platform_suffix == ''  
  error('Unsupported platform: ' + system + ' ' + arch)  
endif

asm_files = [  
  'asm/make_' + platform_suffix,  
  'asm/jump_' + platform_suffix,  
  'asm/ontop_' + platform_suffix  
]  
  
context_lib = static_library(  
  'context',  
  asm_files,  
  install: true  
)
 
context_dep = declare_dependency(  
  link_with: context_lib,  
  include_directories: include_directories('..'),  
)  

# unity 
# ---------- muon-friendly tests block ----------
# Edit test_items to list every test source and its executable name.
test_items = [
  ['tests/context_test.c', 'context_test'],
  # ['tests/other_test.c', 'other_test'],
]

if not meson.is_subproject() and build_tests
  # Unity static library
  unity_files = [
    'tests/unity/unity.c',
    'tests/unity/unity.h',
    'tests/unity/unity_internals.h'
  ]
  unity_lib = static_library('unity', unity_files, install: false)
  unity_dep = declare_dependency(link_with: unity_lib, include_directories: include_directories('tests'))

  test_exes = []
  test_names = []
  test_paths = []

  # Build each test executable and record its name + expected built path
  foreach item : test_items
    src = item[0]
    name = item[1]
    exe = executable(
      name,
      src,
      dependencies: [context_dep, unity_dep],
      include_directories: include_directories(meson.source_root(), 'tests'),
      install: false
    )
    test_exes += exe
    test_names += name
    # Construct expected binary path under Meson build root
    # On Unix-like systems Meson places executables at meson.build_root() + '/' + name
    test_paths += meson.build_root() + '/' + name
  endforeach

  # Register tests with meson test() so "meson test" still works
  foreach i : range(0, test_exes.length())
    test(test_names[i], test_exes[i], timeout: 120, suite: 'unit')
  endforeach

  manifest_entries = []
  foreach i : range(0, test_names.length())
    entry = '{\"name\":\"' + test_names[i] + '\",\"cmd\":[\"' + test_paths[i] + '\"]}'
    manifest_entries += entry
  endforeach

  # Concatenate into JSON array without using join()
  manifest_json = '['
  foreach i : range(0, manifest_entries.length())
    if i > 0
      manifest_json = manifest_json + ','
    endif
    manifest_json = manifest_json + manifest_entries[i]
  endforeach
  manifest_json = manifest_json + ']'

  # manifest filename (single name, no slashes)
  manifest_fname = 'muon-tests.json'
  manifest_path = meson.build_root() + '/' + manifest_fname

  write_meson_manifest = custom_target(
    'write-muon-manifest',
    output: manifest_fname,
    command: [
      'sh', '-c',
      'cat > "$1" << \'EOF\'\n' + manifest_json + '\nEOF',
      manifest_path
    ],
    build_by_default: false,
    install: false
  )

  custom_target(
    'muon-run',
    output: 'muon-run.txt',
    depends: [write_meson_manifest],
    command: [
      'sh', '-c',
      'if command -v muon >/dev/null 2>&1; then muon test --manifest ' + manifest_path + '; else echo "muon not found" >/dev/stderr; exit 2; fi'
    ],
    build_by_default: false
  )
endif
# ---------- end muon-friendly tests block ----------
