#define OBJ "/players/whisky/guild/obj/"
#define MONST "/players/whisky/guild/monster/"
#define PATH "/players/whisky/guild/room/"
#define E environment
#define TP   this_player()
#define MONK "guild/master"->query_number("monk")
#define ADV  "guild/master"->query_number("adventurer") 
#define RAUS (TP->query_guild()!=MONK && TP->query_guild()!=ADV && TP->query_level()>10 && !present("pentagram",TP) && !TP->query_npc() && !TP->query_wizard())
#define WO "leaves the guild#players/whisky/meadow/room/m9"
