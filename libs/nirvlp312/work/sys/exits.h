#ifndef _exits_h
#define _exits_h

  /* flags */
#define EXIT_INVISIBLE          1
#define EXIT_VISIBLE_IF_OPEN    2
#define EXIT_LONGER_THAN_VERB   4
#define EXIT_VISIBLE_ON_MAP     8
#define EXIT_INVISIBLE_ON_MAP   16

  /* indices of the mapping */
#define EXIT_DEST               0
#define EXIT_HOOK               1
#define EXIT_FLAGS              2
#define EXIT_DIR                3

#define EXIT_TYPE_DOOR          "door"
#define EXIT_TYPE_WINDOW        "window"

#endif
