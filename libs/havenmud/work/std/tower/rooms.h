#include <terrain.h>

#define TP    	this_player()
#define TO	this_object()
#define NAME    query_cap_name()
#define PRON	query_pronoun()
#define OBJ	query_objective()
#define POSS 	query_possessive()
#define RSP(x)	restore_spell_points(x)
#define KAHN    "/domains/hyperborea/areas/tower"
#define ROOMS   KAHN + "/rooms"
#define CRITS   KAHN + "/critters"
#define WPNS    KAHN + "/weapons"
#define TRSR    KAHN + "/treasure"
#define ARMR    KAHN + "/armour"
#define TOWER   KAHN + "/rooms"
#define FOREST  KAHN + "/forest"
#define CAVERN	KAHN + "/cavern"
#define ENV(x)	environment(x)
#define SCHOOL  "/players/duuktsaryth/school/school.lpc"
#define SCDIR   "/players/duuktsaryth/school"
#define DUNG    "/players/duuktsaryth/area/dungeon"
#define DOBJ    "/players/duuktsaryth/area/dungeon/obj"
#define DNPC    "/players/duuktsaryth/area/dungeon/npc"
