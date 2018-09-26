# @Author: Sebastian Poeplau <Poeplau>, Giovanni Camurati <Camurati>
# @Date:   22-September-2018
# @Email:  poeplau@eurecom.fr, camurati@eurecom.fr
# @Filename: meson.build
# @Last modified by:   Camurati
# @Last modified time: 22-September-2018
# @License: GPLv3

project('python_hel', 'cpp', default_options: ['cpp_std=c++11'])

compiler = meson.get_compiler('cpp')
ntl = compiler.find_library('ntl')
gmp = compiler.find_library('gmp')

aes_type = get_option('aes_type')
if aes_type == 'aes_simple'
  aes_src = 'hel_lib/aes.cpp'
  aes = static_library('aes',
                       'hel_lib/aes.cpp')
elif aes_type == 'aes_ni'
  extra_args = ['-msse2', '-msse', '-march=native', '-maes']
  aes = static_library('aes',
                       'aes_ni/aes_ni.cpp',
                       cpp_args: extra_args)
endif

hel = library('hel',
              'hel_wrapper/hel_wrapper.cpp',
              'hel_lib/hel_execute.cpp',
              'hel_lib/hel_enum.cpp',
              'hel_lib/hel_histo.cpp',
              'hel_lib/hel_init.cpp',
              'hel_lib/hel_util.cpp',
              'hel_lib/scores_example.cpp',
              'hel_lib/scores_example_data.cpp',
              dependencies: [ntl, gmp],
              link_with: aes,
              install: true)

executable('hel_example',
           'hel_lib/main_example.cpp',
           dependencies: [ntl, gmp],
           link_with: hel)
