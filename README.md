# Meson Project
You need meson version 0.56 because I use the substring function. Install with pip:
~~~
pip3 install -Iv meson==0.56
~~~
## Folder structure
- linker_script
- scripts (helper scripts)
- src
    * example_folder
        * include
        * src
        * test (holds test runner and tests)
        * meson.build (meson file for this subdirectory)
    * main.c (main for the embedded target)
- subprojects (holds subprojects that meson clones from git)
    * packagefiles (holds patches and meson file for subprojects)
- cross.build (cross compile information)
- meson.build (root meson file)

## Build folders
We need a build folder for the embedded target
~~~
meson --cross-file=cross.build build
~~~
and one for the tests that are executed on the host machine
~~~
meson test_build
~~~
## Build targets
Since it doesn't make sense to compile tests with the compiler for the embedded controller and the other way around for the embedded firmware, the meson files prevent you from running targets in the wrong build folder

### Embedded targets
~~~
meson compile -C build target_name
~~~
target_names:
* bin (binary)
* size (.size file that holds size of binary)
* dis (disassembly)
* flash (flash controller)
* check (check with cppcheck)
* check_misra (check with misra rules)
* puncover (stack-analyse tool)
* bloaty (shows size of elf sections)
### Test targets
~~~
meson compile -C test_build target_name
~~~
target_names:
* <folder_name\>_tests (execute tests in that subfolder)
* <folder_name\>_coverage_report (generate test coverage report with gcov)
## Subprojects
Subprojects are used to include external libraries (for example Unity for testing). Meson can clone them from git automatically.
#### Wrap file
To do that it need a .wrap file in the subprojects folder. The file contains the git url, the patch_directory and other config information
#### patch folder
In case the project cannot be built by meson or we need to change some files in the project we use the packagefiles folder. In here we place files to add or to replace and meson will just copy/overwrite them in the cloned repository
## gdb
I have not found a way to invoke the gdb command within meson because the gdb-session is closed imediately if gdb is started as a run_target/custom_target in meson
~~~
gdb-multiarch ./build/firmware.elf -x scripts/gdb_script
~~~
## LTO decission
I have decided to disable LTO because of this:

https://interrupt.memfault.com/blog/best-and-worst-gcc-clang-compiler-flags

Might need to enable it if i run into performance issues

## Links to used Tools
* cppcheck: https://github.com/danmar/cppcheck
* puncover https://github.com/HBehrens/puncover
* bloaty https://github.com/google/bloaty
* Unity https://github.com/ThrowTheSwitch/Unity
* Lcov https://github.com/linux-test-project/lcov
* st-flash: https://github.com/stlink-org/stlink