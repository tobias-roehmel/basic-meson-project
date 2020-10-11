project('libopencm3_stm32f4 dep', 'c')

r = run_command('make', env: {'PREFIX': '/home/tobi/Downloads/gcc-arm-none-eabi-9-2019-q4-major-x86_64-linux/gcc-arm-none-eabi-9-2019-q4-major/bin/arm-none-eabi-'}, check: false)

message(r.stderr())

cc = meson.get_compiler('c')
libopencm3_stm32f4_dep = declare_dependency(
  dependencies : cc.find_library('libopencm3_stm32f4', dirs: '@0@/lib'.format(meson.current_source_dir())),
  include_directories : include_directories('include')
  )
