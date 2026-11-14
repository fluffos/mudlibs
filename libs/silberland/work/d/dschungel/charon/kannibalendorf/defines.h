#include "/d/dschungel/def.h"
#include "defines.h"
#include <moredef.h>

#define MAGIERNAME "charon"
#define QUESTERZ   "feyaria"

#define KANNIBALEN_DORF(x)    ("/d/dschungel/charon/kannibalendorf/"+x)
#define KD_ROOM(x)            KANNIBALEN_DORF("room/"+x)
#define KD_NPC(x)             KANNIBALEN_DORF("npc/"+x)
#define KD_OBJ(x)             KANNIBALEN_DORF("obj/"+x)
#define KD_WEAPON(x)          KANNIBALEN_DORF("weapon/"+x)


/*** Questspezifische Defines ***/
#define KANNIBALENDORFQUEST    "1000 Qualen im Dorf der Kannibalen"
#define KANNIBALENDORFQUESTLOG "/log/quests/kannibalendorf"
#define KANNIBALENDORFQUESTLOG2 KANNIBALEN_DORF("log/kannibalendorf.log")

#define KDQ_BOLZENSCHNEIDER_GEFUNDEN 0x01
#define KDQ_CAROLINA_BEFREIT         0x02
#define KDQ_HAARE_ABGESCHNITTEN      0x04

#define KDQSTRING ([0x01: "Bolzenschneider gefunden", \
                    0x02: "Carolina befreit",\
                    0x04: "Haare des Waechters abgeschnitten",\
                    ])
                    
#define DBM(x) if(find_player(QUESTERZ))   tell_object(find_player(QUESTERZ),x);

#ifndef DB
#define DB(x) if (find_player(MAGIERNAME)) tell_object(find_player(MAGIERNAME),x);
#endif                 
