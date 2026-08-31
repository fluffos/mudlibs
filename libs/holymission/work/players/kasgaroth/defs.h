#define PATH      "/players/kasgaroth/"
#define ROOM       PATH + "room/"
#define OBJS       PATH + "obj/"
#define MONS       PATH + "monster/"
#define WEAP       PATH + "weapons/"
#define PALACE     PATH + "palace/"
#define GARDEN     PALACE + "garden/"
#define POISON     PATH + "guild/poison/"

#define TP         this_player()
#define TO         this_object()
#define CAP        capitalize
#define E          environment
#define MOVE       move_object
#define MOVEP      this_player()->move_player
#define NF         notify_fail
