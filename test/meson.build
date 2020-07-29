ext = '.cpp'
basenames = [
  'FileMetaBroker',
  'Queue'
]

# googletest subproject stuff
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

# this is needed for std::filesystem
cpp_fs_dep = cc.find_library('stdc++fs')

foreach basename : basenames
  test_file = files('test_' + basename + ext)
  exe = executable('test_' + basename, test_file,
    dependencies: [gtest_dep, cpp_fs_dep, deps],
    include_directories: [incdir, ds_includes],
    link_with: libdistance,
  )
  test('test ' + basename + ext, exe)
endforeach