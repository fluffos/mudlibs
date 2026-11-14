inherit "room/room";

#define EXTRA_RESET

#define ONE_EXIT(DEST, DIR, SH, LO, LIGHT)\
reset(arg) { ::reset(arg); EXTRA_RESET if (arg) return; set_light(LIGHT);\
    short_desc = SH; long_desc = LO; dest_dir = ({ DEST, DIR }); }

#define TWO_EXIT(DEST1, DIR1, DEST2, DIR2, SH, LO, LIGHT)\
reset(arg) { ::reset(arg); EXTRA_RESET if (arg) return; set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2 }); }


#define THREE_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, SH, LO, LIGHT)\
reset(arg) { ::reset(arg); EXTRA_RESET if (arg) return; set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3 }); }


#define FOUR_EXIT(DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4, SH, LO, LIGHT)\
reset(arg) { ::reset(arg); EXTRA_RESET if (arg) return; set_light(LIGHT);\
    short_desc = SH; long_desc = LO;\
    dest_dir = ({ DEST1, DIR1, DEST2, DIR2, DEST3, DIR3, DEST4, DIR4 }); }
