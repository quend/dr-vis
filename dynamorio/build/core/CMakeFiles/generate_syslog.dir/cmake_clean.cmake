FILE(REMOVE_RECURSE
  "ldscript"
  "CMakeFiles/generate_syslog"
  "../event_strings.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/generate_syslog.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
