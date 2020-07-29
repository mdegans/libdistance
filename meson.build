# source of truth for package info 
# (changing these changes config_meson.h and many other things)
project('distance', ['cpp'],
  version: run_command(
    'head', '-n', '1', files('VERSION'),
  ).stdout().strip(),
  meson_version: '>= 0.55.0',
  license : 'LGPL',
  default_options: [
    'warning_level=2',  # -Wall
  ]
)

gst_api_version = '1.0'
package_name = 'distance'
package_long_name = package_name + '-' + gst_api_version
package_description = 'core library for gst-distance'
package_version = meson.project_version()
package_author = 'Michael de Gans'
package_email = 'michael.john.degans@gmail.com'
package_uri = 'https://github.com/mdegans/libdistance'

# get the cpp compiler
cc = meson.get_compiler('cpp')

# extra cflags:
add_project_arguments(
  # '-Wall',  # implied by warning_level above
  '-Wshadow',
  '-Werror',
  '-fno-exceptions',
  language : 'cpp'
)

# include subdirs
subdir('deepstream')
subdir('src')
subdir('test')
