
/* Defines fuer Hoehlenquest
** Thor@SilberLand    
** 18-04-1997 
*/

#include "/d/gebirge/def.h"

#define HQUEST(x) GEBIRGE("thor/hoehlenquest/")x
#define HOEHLE(x) HQUEST("room/hoehle/")+x
#define LAB(x) HQUEST("labyrinth/")+x
#define TROPFST(x) HQUEST("room/tropfstein/")+x
#define LAVA(x) HQUEST("room/lavasee/")+x
#define OBJ(x) HQUEST("obj/")+x
#define NPC(x) HQUEST("npc/")+x 
#define WEAPON(x) HQUEST("weapon/")+x
#define ARMOUR(x) HQUEST("armour/")+x
#define SYMBOLMASTER HQUEST("master/symbolmaster.lpc")
#define SYMB_INSERT HQUEST("saves/players")
#define TPORTMASTER HQUEST("master/tportmaster.lpc")
#define TELEPORTER HQUEST("saves/teleport")

#define T_LOAD ((TP->QueryProp(P_TOTAL_WEIGHT)) - (TP->QueryProp(P_WEIGHT)))
#define MAX_T_LOAD 25000
#define P_LOST "verschuettet"
#define P_JUMP "sprungort"
