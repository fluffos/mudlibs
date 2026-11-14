#include "/d/gebirge/def.h"
#define bs( x ) break_string( x, 78 )
#define HOME(x) GEBIRGE("angrox/4elem/")+x
#define ROOM(x) HOME("room/")+x
#define OBJ(x) HOME("obj/")+x
#define OBJ2(x) OBJ("obj/")+x
#define WEAP(x) OBJ("weapon/")+x

#define ARMO(x) OBJ("armour/")+x
#define NPC(x) HOME("npc/")+x
#define WEG(x) ROOM("weg/")+x
#define STADT(x) ROOM("stadt/")+x
#define WALD(x) ROOM("wald/")+x
#define HOEHLE(x) ROOM("hoehle/")+x
#define LOG(x) HOME("log/")+x

#define SW_Q_ITEM "\nerdequest"
#define W_Q_ITEM "\nwindquest"
#define NO_QUEST  "\nnoquest"
#define B_MAL "\nbrandmal"
#define SECHSECK "\nsechseck"
#define P_SECHSECK_STEIN "secheckstein"
#define WIND_QUEST "Cailleac'h's Harfe"
#define WIND_LOG "/log/quests/4elem_wind"
#define QUESTMASTER HOME("std/qm")
#define QUESTMASTERLOG LOG("quest_forbidden")

#define W_QUEST_START 0
#define W_ENTER_TOWN 1
#define W_GET_STONE1 2
#define W_GET_STONE2 3
#define W_GET_KEY 4
#define W_VISIT_HOUSE_1 5
#define W_VISIT_HOUSE_2 6
#define W_GET_CUBE 7
#define W_GET_ORB 8
#define W_PUT_CUBE 9
#define W_PUT_ORB 10
#define W_KILL_GUARDIAN 11
