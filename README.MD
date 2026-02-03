# compile_commands.json
*以下情况需要将目标 (build 路径下) compile_commands.json "拷贝" 一份*
- 更改 Preset 后
- 增加了新的 include_directory
- 
```bash
# linux 
# linux-clang-debug -- preset name
python3 SyCC.py --preset linux-clang-debug
```

```powershell
# pwsh
# windows-msvc-debug -- preset name
python SyCC.py --preset windows-msvc-debug
```

如果是 linux 平台, 则根据自己的配置设置根 CMakeLists.txt 中 GLFW_BUILD_X11 变量的值