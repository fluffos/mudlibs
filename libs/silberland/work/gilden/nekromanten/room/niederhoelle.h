#include "../nekro.h"

#ifdef DB
#undef DB
#endif
#define DB(x) if (find_player("cirion")) tell_object(find_player("cirion"),x+"\n")

#ifdef ROOM
#undef ROOM
#endif
#define ROOM "/gilden/nekromanten/room/niederhoelle"

/* way the player has wandered */
#define P_LOWER_HELL "lower_hell"

#define V_COMPILER ROOM"/virtual_compiler"

/* four directions */
#define DIRECTIONS ({"norden","osten","sueden","westen"})

/* the different rooms of the lower hell */
#define EBENE         "ebene"
#define KUESTENNAEHE  "kuestennaehe"
#define KUESTE        "kueste"

/* the landscape and its directions */
#define LANDSCAPE ([EBENE:\
                      ({30,30,-30,-30});\
                      ({KUESTENNAEHE,EBENE,EBENE,EBENE}),\
                    KUESTENNAEHE:\
                      ({45,30,31,-30});\
                      ({KUESTE,KUESTENNAEHE,EBENE,KUESTENNAEHE}),\
                    KUESTE:\
                      ({46,30,46,-30});\
                      ({0,KUESTE,KUESTENNAEHE,KUESTE})\
                  ])
