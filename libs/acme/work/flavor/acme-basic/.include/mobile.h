#ifndef _MOBILE_H
#define _MOBILE_H

#define MUFFLED_MOVE              0x01
#define FOLLOW                    0x02
#define NO_FOLLOW                 0x04
#define CMD_FOLLOW                0x08
#define FORCE_TELEPORT            0x10
#define SUPPRESS_ERRORS           0x20
#define SUPPRESS_LOOK             0x40

#define DEFAULT_EXIT_MSGOUT       "%y leaves %d."
#define DEFAULT_EXIT_MSGIN        "%y arrives."
#define DEFAULT_ZONE_MSGOUT       "%y leaves %d."
#define DEFAULT_ZONE_MSGIN        "%y arrives."
#define DEFAULT_TELEPORT_MSGOUT   "%y disappears in a puff of smoke."
#define DEFAULT_TELEPORT_MSGIN    "%y appears in a puff of smoke."

#define DEFAULT_VERB              "move"

#define FMT_NEWLINE     ({ 0, "\n", ({ }) })
#define FMT_DIRECTION   ({ 0, "%s", ({ ''dir }) })
#define FMT_VERB        ({ 0, "%s", ({ ({ #'||, ''verb, DEFAULT_VERB }) }) })
#define FMT_DISPLAY     ({ 0, "%s", ({ ({ #'get_display, ''who }) }) })

#define MOBILE_MESSAGE ([  \
  'n' : FMT_NEWLINE,       \
  'd' : FMT_DIRECTION,     \
  'v' : FMT_VERB,          \
  'y' : FMT_DISPLAY        \
])

#endif  // _MOBILE_H
