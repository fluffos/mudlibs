/* added query_std_() stuff [verte] 7.25.03 */
/* 03/21/06 Earwax: added query_dest_dir() stuff */
inherit "room/clean.c";
#define EXTRA_INIT
#define EXTRA_RESET
#define EXTRA_LONG
#define EXTRA_MOVE1
#define EXTRA_MOVE2
#define EXTRA_MOVE3
#define EXTRA_MOVE4

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
query_std_dir1() { return DIR; }\
query_std_dest1() { return DEST; }\
query_dest_dir() { return ({ DEST, DIR }); }\
\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
        return SH+" ["+DIR+"]";\
    return "dark room";\
}\
\
init() {\
    add_action("move", DIR);\
    EXTRA_INIT\
}\
\
move() {\
    EXTRA_MOVE1\
    call_other(this_player(), "move_player", DIR + "#" +DEST);\
    return 1;\
}\
\
long(str) {\
    if(!present("dark_sight_object", this_player())) if(set_light(0) == 0) {\
       write("It is dark.\n");\
       return;\
    }\
    EXTRA_LONG\
    write(LO);\
    write("    The only obvious exit is " + DIR + ".\n");\
}

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
query_std_dir1() { return DIR1; }\
query_std_dir2() { return DIR2; }\
\
query_std_dest1() { return DEST1; }\
query_std_dest2() { return DEST2; }\
\
query_dest_dir() { return ({ DEST1, DIR1, DEST2, DIR2 }); }\
\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
        return SH+" ["+DIR1+","+DIR2+"]";\
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
    call_other(this_player(), "move_player", DIR1 + "#" + DEST1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    call_other(this_player(), "move_player", DIR2 + "#" + DEST2);\
    return 1;\
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
query_std_dir1() { return DIR1; }\
query_std_dir2() { return DIR2; }\
query_std_dir3() { return DIR3; }\
\
query_std_dest1() { return DEST1; }\
query_std_dest2() { return DEST2; }\
query_std_dest3() { return DEST3; }\
\
query_dest_dir() { return ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3 }); }\
\
reset(arg) { EXTRA_RESET if (arg) return; set_light(LIGHT); }\
short() {\
    if (set_light(0))\
        return SH+" ["+DIR1+","+DIR2+","+DIR3+"]";\
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
    call_other(this_player(), "move_player", DIR1 + "#" + DEST1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    call_other(this_player(), "move_player", DIR2 + "#" + DEST2);\
    return 1;\
}\
\
move3() {\
    EXTRA_MOVE3\
    call_other(this_player(), "move_player", DIR3 + "#" + DEST3);\
    return 1;\
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
        return SH+" ["+DIR1+","+DIR2+","+DIR3+","+DIR4+"]";\
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
    call_other(this_player(), "move_player", DIR1 + "#" + DEST1);\
    return 1;\
}\
\
move2() {\
    EXTRA_MOVE2\
    call_other(this_player(), "move_player", DIR2 + "#" + DEST2);\
    return 1;\
}\
\
move3() {\
    EXTRA_MOVE3\
    call_other(this_player(), "move_player", DIR3 + "#" + DEST3);\
    return 1;\
}\
\
move4() {\
    EXTRA_MOVE4\
    call_other(this_player(), "move_player", DIR4 + "#" + DEST4);\
    return 1;\
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
}\
\
query_dest_dir() { return ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4 }); }\
query_std_dir1() { return DIR1; }\
query_std_dir2() { return DIR2; }\
query_std_dir3() { return DIR3; }\
query_std_dir4() { return DIR4; }\
\
query_std_dest1() { return DEST1; }\
query_std_dest2() { return DEST2; }\
query_std_dest3() { return DEST3; }\
query_std_dest4() { return DEST4; }
