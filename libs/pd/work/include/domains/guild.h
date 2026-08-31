#ifndef __GUILD_H_
#define __GUILD_H_
#ifndef __DAEMONS_H_
#include <daemons.h>
#endif

#define SQUIRE 1
#define MEMBER 1
#define COUNCIL 1
#define LEADER 1
#define GUILD_VERSION  "4.3.1"

#define VALID_POSITIONS ({ "squire", \
                            "member", \
                           "council", \
                           "leader", \
                         })

#define MAIN ({ "escobar", \
"abraxas", \
"yun", \
"enska", \
              })
#define MASTER ({ "daos", \
                  "whit", \
                  "stormbringer", \
                  "vian", \
                  "nulvect", \
                  "amun", \
                })

#define VALID_GUILDS ({"knightsofvalor", \
                        "darksoul", \
                        "forsaken", \
                        "unholy", \
                       })

#define SAVE "/d/guilds/save/"

#define ROOM "/std/guild/guild"
#define ROOMS "/d/guilds/"
#define ALL "/d/guilds/"
#define SCORPIO "/d/guilds/scorpio/"
#define AoD "/d/guilds/AoD/"
#define KNIGHTSOFVALOR "/d/guilds/knightsofvalor/"
#define ILLUMINATI "/d/guilds/illuminati/"
#define ACHERON "/d/guilds/acheron/"
#define CHOSEN "/d/guilds/chosen/"
#define DARKSOUL "/d/guilds/darksoul/"
#define UNHOLY "/d/guilds/unholy/"
#define FORSAKEN "/d/guilds/forsaken/"
#define BLACKFORCE "/d/guilds/blackforce/"
#define VORTICON "/d/guilds/vorticon/"
#define LASTSAINTS "/d/guilds/lastsaints/"
#define BLACKSAILS "/d/guilds/blacksails/"

#define GROOM "/wizards/amun/builders/guilds/rooms/"
#define GMOB "/wizards/amun/builders/guilds/mobs/"
#define GWEP "/wizards/amun/builders/guilds/weapons/"
#define GARM "/wizards/amun/builders/guilds/armour/"
#define GOBJ "/wizards/amun/builders/guilds/objects/" 
#define DAE "/d/coach/daemons/"
#define SERVER "/wizards/amun/builders/guilds/server"

#endif
