#define HOME "players/qclxxiv/"
inherit "players/qclxxiv/leaf5/qroom";

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
/* REGION is needed because reg_gen is used to gen. area */
#define REGION "/players/qclxxiv/leaf5/"

/* derived rooms MUST provide a ....EXIT (or reset())
// derived rooms MAY provide an extra_reset() in which case the next 2 line:
// #undef EXTRA_RESET.
// #define EXTRA_RESET extra_reset(arg);
// should be placed somewhere on top of the derived file.
*/
#define EXTRA_INIT
#define EXTRA_LONG

/* added macros */

#define PLACE_IN_ROOM(OBJNAME, FILNAME)\
OBJNAME = place_in_room(OBJNAME,FILNAME,this_object());
		
#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_room(OBJNAME,FILNAME,this_object());

#define MAKE_IN_ROOM(FILNAME)\
make_in_room(FILNAME,this_object());

#define MAKE_IN_THIS(FILNAME)\
make_in_room(FILNAME,this_object());

/* room.h macros */

#define NO_EXIT(SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT); short_desc = SH;\
    long_desc = LO; } EXTRA_RESET }\

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT); short_desc = SH;\
    long_desc = LO; dest_dir = ({ DEST, DIR }); } EXTRA_RESET }\

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2 }); } EXTRA_RESET }\

#define THREE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3 }); } EXTRA_RESET }\

#define FOUR_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4 }); }\
    EXTRA_RESET }\

#define FIVE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5 }); }\
    EXTRA_RESET }\

