#define PATH                "/players/uglymouth/recoding/sherman/"
#define ROOM_DIR            PATH + "room/"
#define ITEM_DIR            PATH + "item/"
#define MON_DIR             PATH + "monster/"
#define AREA_DAEMON_FILE    PATH + "area_d.lpc"
#define AREA_DAEMON         find_object( AREA_DAEMON_FILE )
#define GEN_GRAVE           ROOM_DIR + "gengrave"
#define GEN_VAMPIRE         MON_DIR + "genvamp"

#define TP                  this_player()
#define TPSHORTN            TP->query_short_name()
#define TPPRN               TP->query_pronoun()
#define TPPOS               TP->query_possessive()
