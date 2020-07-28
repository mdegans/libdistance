# Deepstream meson.build

This folder can be included as a subdir in a meson project to provide DeepStream dependencies. Modifications may be necessary if a library is not found. To modify, see example in this folder's meson.build re: `nvds_meta` and `nvdsgst_meta`). Check under `ds_libdir` and add as necessary, removing the suffix and prefix from the missing library as needed (eg. `libnvbuf_fdmap.so` -> `nvbuf_fdmap`).

Ideally, a pkg-config or .cmake would be included with DeepStream itself but sadly this is not the case.