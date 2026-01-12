# compile_commands.json
*更改 Preset 后, 需要将目标(build 路径下) compile_commands.json "拷贝" 一份*
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