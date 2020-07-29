incdir = include_directories('../include')

sources = [
  'BaseFilter.cpp',
  'DistanceFilter.cpp',
  'FileMetaBroker.cpp',
  'PayloadBroker.cpp',
  'ProtoPayloadFilter.cpp',
  'PyPayloadBroker.cpp',
]

# libdistanceproto
distanceproto_dep = dependency('distanceproto',
  version: '>= 0.4.0',
  required: false,
)
if not distanceproto_dep.found()
  distanceproto_proj = subproject('distanceproto')
  distanceproto_dep = distanceproto_proj.get_variable('distanceproto_dep')
endif

deps = [
  dependency('gstreamer-1.0'),
  deepstream_deps,
  distanceproto_dep,
]

libdistance = library(meson.project_name(), sources,
  version: meson.project_version(),
  dependencies: deps,
  include_directories: [incdir, ds_includes],
  install: true,
)

distance_dep = declare_dependency(
  link_with: libdistance,
  include_directories: [incdir],
  dependencies: deps,
)

pkg = import('pkgconfig')
distance_pc = pkg.generate(libdistance,
  description: package_description,
  url: package_uri,
  # for consistency with existing cmake install:
  install_dir: get_option('datadir') / 'pkgconfig'
)