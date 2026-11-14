#include "../def.h"
#include "../directions.h"
#include <defines.h>
#include <moredef.h>

#define HOME(x) GEBIRGE("angrox/")+x
#define PlayerAlign this_player()->QueryProp(P_ALIGN)
#define PlayerGender this_player()->QueryProp(P_GENDER)
#define LOG(x) HOME("log/")+x
#define ROOM(x) HOME("room/")+x
#define CONNECT(x) ROOM("connect/")+x
#define EBENE1(x) ROOM("ebene1/")+x
#define EBENE2(x) ROOM("ebene2/")+x
#define EBENE3(x) ROOM("ebene3/")+x
#define EBENE4(x) ROOM("ebene4/")+x
#define ARMOUR(x) HOME("armour/")+x
#define WEAPON(x) HOME("weapon/")+x
#define OBJ(x) HOME("obj/")+x
#define NPC(x) HOME("npc/")+x
#define LOGFILE "angrox/bergwerk.log"
#define bs(x) BS(x)
