/*
  !!! No new code that uses std.h is accepted !!!
  Remade this file 5.6-92   --Val
*/
inherit "/room/room";

#define EXTRA_RESET
#define EXTRA_INIT
#define EXTRA_LONG
#define EXTRA_MOVE1
#define EXTRA_MOVE2
#define EXTRA_MOVE3
#define EXTRA_MOVE4

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
reset(arg) {\
    ::reset(arg);\
    if(!arg) { set_outdoors(1);\
	set_light(LIGHT); short_desc = SH;\
        long_desc = LO; dest_dir = ({ DEST, DIR }); }\
    EXTRA_RESET\
}\
init() { ::init(); EXTRA_INIT }\
long(str) { EXTRA_LONG ::long(str); }\
move(str) { EXTRA_MOVE1 return ::move(str); }

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
reset(arg) {\
    ::reset(arg);\
    if(!arg) { set_outdoors(1);\
	set_light(LIGHT); short_desc = SH;\
        long_desc = LO; dest_dir = ({ DEST1, DIR1, DEST2, DIR2 }); }\
    EXTRA_RESET\
}\
init() { ::init(); EXTRA_INIT }\
long(str) { EXTRA_LONG ::long(str); }\
move(str) { switch(query_verb()) {\
    case DIR1: EXTRA_MOVE1  break;\
    default: EXTRA_MOVE2  break;\
    } return ::move(str);\
}

#define THREE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, SH, LO, LIGHT)\
reset(arg) {\
    ::reset(arg);\
    if(!arg) { set_outdoors(1); set_light(LIGHT); short_desc = SH;\
        long_desc = LO; dest_dir = ({ DEST1,DIR1,DEST2,DIR2,DEST3,DIR3 }); }\
    EXTRA_RESET\
}\
init() { ::init(); EXTRA_INIT }\
long(str) { EXTRA_LONG ::long(str); }\
move(str) { switch(query_verb()) {\
    case DIR1: EXTRA_MOVE1  break;\
    case DIR2: EXTRA_MOVE2  break;\
    default: EXTRA_MOVE3  break;\
    }  return ::move(str);\
}

#define FOUR_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, SH, LO, LIGHT)\
reset(arg) {\
    ::reset(arg);\
    if(!arg) { set_outdoors(1); set_light(LIGHT); short_desc = SH;\
        long_desc = LO;\
        dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4 }); }\
    EXTRA_RESET\
}\
init() { ::init(); EXTRA_INIT }\
long(str) { EXTRA_LONG ::long(str); }\
move(str) { switch(query_verb()) {\
    case DIR1: EXTRA_MOVE1  break;\
    case DIR2: EXTRA_MOVE2  break;\
    case DIR3: EXTRA_MOVE3  break;\
    default: EXTRA_MOVE4  break;\
    } return ::move(str);\
}
