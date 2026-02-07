# .clangd
更换平台后需要`compile_commands.json`所在的路径, 如下

`CompilationDatabase: ./build/Windows/windows-msvc-debug`

如果是 linux 平台, 则根据自己的配置设置根 CMakeLists.txt 中 GLFW_BUILD_X11 变量的值