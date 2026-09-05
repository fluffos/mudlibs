#ifndef _sys_who_h
#define _sys_who_h

#define WHO_MODE_PARSER_CLASS "<who_mode>"

#define WHO_MODE_EXTRA_BRIEF  "extra brief"
#define WHO_MODE_BRIEF        "brief"
#define WHO_MODE_SHORT        "short"
#define WHO_MODE_VERBOSE      "verbose"

#define WHO_MODES ({ \
                     WHO_MODE_EXTRA_BRIEF, \
                     WHO_MODE_BRIEF,       \
                     WHO_MODE_SHORT,       \
                     WHO_MODE_VERBOSE      \
                  })

#endif

