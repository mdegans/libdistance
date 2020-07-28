incdir = include_directories('../include')
sources = [
  'BaseFilter.cpp',
  'DistanceFilter.cpp',
  'FileMetaBroker.cpp',
  'PayloadBroker.cpp',
  'ProtoPayloadFilter.cpp',
  'PyPayloadBroker.cpp',
]

deps = [
  dependency('gstreamer-1.0'),
  deepstream_deps,
  libdistanceproto_dep,
]

libdscore = library(meson.project_name(), sources,
  dependencies: deps,
  include_directories: [incdir, ds_includes],
  link_with: libdistanceproto,
  install: true,
)