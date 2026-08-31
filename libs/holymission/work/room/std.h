/* DONT EVEN THINK OF USING THIS ANY FURTHER !!!! 030793 Llort */

inherit "room/clean_up";

#define EXTRA_INIT
#define EXTRA_RESET
#define EXTRA_LONG
#define EXTRA_MOVE1
#define EXTRA_MOVE2
#define EXTRA_MOVE3
#define EXTRA_MOVE4

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
	return SH;\
    return "dark room";\
}\
\
init() {\
    add_action("move1", DIR);\
    EXTRA_INIT\
}\
\
move1() {\
    EXTRA_MOVE1\
    move(DIR);\
    return 1;\
}\
move(str) {\
    if (str==DIR) {\
	this_player()->move_player(DIR+"#"+DEST);\
	return 1;\
    }\
    return 0;\
}\
\
long(str) {\
    if (set_light(0) == 0){\
       write("It is dark.\n");\
       return;\
    }\
    EXTRA_LONG\
    write(LO);\
    write("    The only obvious exit is " + DIR + ".\n");\
}

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
	return SH;\
    return "dark room";\
}\
\
init() {\
    add_action("move1", DIR1);\
    add_action("move2", DIR2);\
    EXTRA_INIT\
}\
\
move1() {\
    EXTRA_MOVE1\
    move(DIR1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    move(DIR2);\
    return 1;\
}\
\
move(str) {\
   switch(str) {\
   case DIR1 : { this_player()->move_player(DIR1+"#"+DEST1); return 1; }\
   case DIR2 : { this_player()->move_player(DIR2+"#"+DEST2); return 1; }\
   }\
   return 0;\
}\
\
long(str) {\
    if (set_light(0) == 0){\
       write("It is dark.\n");\
       return;\
    }\
    EXTRA_LONG\
    write(LO);\
    write("There are two obvious exits, " + DIR1 + " and " + DIR2 + ".\n");\
}

#define THREE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, SH, LO, LIGHT)\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
	return SH;\
    return "dark room";\
}\
\
init() {\
    add_action("move1", DIR1);\
    add_action("move2", DIR2);\
    add_action("move3", DIR3);\
    EXTRA_INIT\
}\
\
move1() {\
    EXTRA_MOVE1\
    move(DIR1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    move(DIR2);\
    return 1;\
}\
\
move3() {\
    EXTRA_MOVE3\
    move(DIR3);\
    return 1;\
}\
\
move(str) {\
   switch(str) {\
   case DIR1 : { this_player()->move_player(DIR1+"#"+DEST1); return 1; }\
   case DIR2 : { this_player()->move_player(DIR2+"#"+DEST2); return 1; }\
   case DIR3 : { this_player()->move_player(DIR3+"#"+DEST3); return 1; }\
   }\
   return 0;\
}\
\
long(str) {\
    if (set_light(0) == 0){\
       write("It is dark.\n");\
       return;\
    }\
    EXTRA_LONG\
    write(LO);\
    write("There are three obvious exits, " + DIR1 + ", " + DIR2 +\
	  " and " + DIR3 + ".\n");\
}

#define FOUR_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, SH, LO, LIGHT)\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
	return SH;\
    return "dark room";\
}\
\
init() {\
    add_action("move1", DIR1);\
    add_action("move2", DIR2);\
    add_action("move3", DIR3);\
    add_action("move4", DIR4);\
    EXTRA_INIT\
}\
\
move1() {\
    EXTRA_MOVE1\
    move(DIR1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    move(DIR2);\
    return 1;\
}\
\
move3() {\
    EXTRA_MOVE3\
    move(DIR3);\
    return 1;\
}\
\
move4() {\
    EXTRA_MOVE4\
    move(DIR4);\
    return 1;\
}\
\
move(str) {\
    switch(str) {\
    case DIR1 : { this_player()->move_player(DIR1+"#"+DEST1); return 1; }\
    case DIR2 : { this_player()->move_player(DIR2+"#"+DEST2); return 1; }\
    case DIR3 : { this_player()->move_player(DIR3+"#"+DEST3); return 1; }\
    case DIR4 : { this_player()->move_player(DIR4+"#"+DEST4); return 1; }\
    }\
    return 0;\
}\
\
long(str) {\
    if (set_light(0) == 0){\
       write("It is dark.\n");\
       return;\
    }\
    EXTRA_LONG\
    write(LO);\
    write("There are four obvious exits, " + DIR1 + ", " + DIR2 + ", " +\
	  DIR3 + " and " + DIR4 + ".\n");\
}
