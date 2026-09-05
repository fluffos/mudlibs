#ifndef _EXPAND_OBJECT_H
#define _EXPAND_OBJECT_H

#define MATCH_DETAIL      0x01
#define UPDATE_CONTEXT    0x02
#define LIMIT_ONE         0x04
#define MATCH_BLUEPRINTS  0x08
#define IGNORE_CLONES     0x10
#define STALE_CLONES      0x20

#define COLLAPSIBLE       ([ "me", "here", "living", "users" ])

#define OB_TARGET         0
#define OB_ID             1
#define OB_DETAIL         2

#define CONTEXT_DELIM     "."
#define SPEC_DELIM        ","
#define OPEN_GROUP        "("
#define CLOSE_GROUP       ")"

#endif  // _EXPAND_OBJECT_H
