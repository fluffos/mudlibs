inherit "room/room";

#define EXTRA_RESET
#define EXTRA_INIT

#define ZERO_EXIT(SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT); short_desc = SH;\
    long_desc = LO; dest_dir = ({ }); } EXTRA_RESET }

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT); short_desc = SH;\
    long_desc = LO; dest_dir = ({ DEST, DIR }); } EXTRA_RESET }

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2 }); } EXTRA_RESET }


#define THREE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3 }); } EXTRA_RESET }


#define FOUR_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4 }); }\
    EXTRA_RESET }

#define FIVE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5 }); }\
    EXTRA_RESET }

#define SIX_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6 }); }\
    EXTRA_RESET }
	
#define SEVEN_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7 }); }\
    EXTRA_RESET }

#define EIGHT_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, DEST8, DIR8, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, DEST8, DIR8 }); }\
    EXTRA_RESET }

#define NINE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, DEST8, DIR8, DEST9, DIR9, SH, LO, LIGHT)\
reset(arg) { if (!arg) { set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, DEST5, DIR5, DEST6, DIR6, DEST7, DIR7, DEST8, DIR8, DEST9, DIR9 }); }\
    EXTRA_RESET }

#define ALL_N_EXIT(DEST, DESTN, DIRN, SH, LO, LIGHT)\
  reset(arg) { if (!arg) { set_light(LIGHT);\
  short_desc = SH; long_desc = LO;\
  dest_dir = ({ DEST, "north", DEST, "south", DEST, "west", DEST, "east", DEST, "northwest", DEST, "northeast", DEST, "southeast", DEST, "southwest", DESTN, DIRN }); }\
EXTRA_RESET }

special_init() {
    EXTRA_INIT
}
