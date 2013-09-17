FILE(REMOVE_RECURSE
  "ldscript"
  "CMakeFiles/drpreload.dir/unix/preload.c.o"
  "CMakeFiles/drpreload.dir/config.c.o"
  "CMakeFiles/drpreload.dir/unix/os.c.o"
  "CMakeFiles/drpreload.dir/x86/x86.asm.o"
  "../lib64/release/libdrpreload.pdb"
  "../lib64/release/libdrpreload.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang ASM C)
  INCLUDE(CMakeFiles/drpreload.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
