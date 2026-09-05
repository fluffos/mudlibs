#define TP  this_player()
#define TO  this_object()
#define TL  tell_object
#define TR  tell_room
#define ENV environment
#define ENVTP ENV(TP)
#define MO  move_object
#define CO clone_object
#define QN query_name()
#define RN query_real_name()
#define CAP capitalize
#define logwiz ""
#define msg (ctime()[4..15]+" "+ctime()[20..23]+" "+CAP((string)TP->RN)+" -> ")
