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
  version: '0.3.2',
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

libdscore = library(meson.project_name(), sources,
  dependencies: deps,
  include_directories: [incdir, ds_includes],
  install: true,
)