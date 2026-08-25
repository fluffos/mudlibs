// AGENTS.md conversion note: this must stay an angle-bracket include --
// it resolves via the configured include path to the DIFFERENT file
// /include/virtual.h (which defines VIRTUAL_NAME_PROP etc.), not to
// itself. convert_lib.sh's "local angle-bracket -> quoted" heuristic
// mis-converted this to a literal self-include (this file and
// /include/virtual.h happen to share a basename), causing
// "#include nested too deeply". Reverted to the original angle-bracket
// form.
#include <virtual.h>

#define SERVER "/global/virtual/server"

#define LOAD   1
#define CLONE  2
