#define ROOM(x) "/d/gebirge/monimor/room/"+x
#include <defines.h>

#define SSH(x) SetProp(P_INT_SHORT,x)
#define SLO(x) SetProp(P_INT_LONG,break_string(x,78))
#define KLAMM(x) "/d/gebirge/monimor/room/"+x
#define HOEHLE(x) "/d/gebirge/monimor/room/hoehle/"+x
#define MORKAS(x) "/d/gebirge/monimor/morkas/room/"+x
#define LO(x) "/d/gebirge/monimor/log/"+x
#define MONPC(x) "/d/gebirge/monimor/morkas/npc/"+x
#define NPC(x) "/d/gebirge/monimor/npc/"+x
#define TRN(x) "/d/gebirge/monimor/transport/"+x
#define QUESTOB(x) "/d/gebirge/monimor/morkas/questobj/"+x
#define MOOB(x) "/d/gebirge/monimor/morkas/obj/"+x
#define OBJ(x) "/d/gebirge/monimor/obj/"+x
#define ENV(x) environment(x)
#define ME this_object()
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(this_object());
#define CLONEOB(x) clone_object(x)
#define CLONE(x,y) clone_object(x)->move(y);
#define TP this_player()
#define TPN this_player()->name()
#define TPTMO(x) this_player()->move(MORKAS(x),M_GO)
#define TPM(x) this_player()->move(ROOM(x),M_GO)
#define TO this_object()
#define bs( x ) break_string( x, 78 )
#define BS(x) break_string(x,78)

#define LOG(x) "/d/gebirge/monimor/log/"+x
#define SEE(x) "/d/gebirge/monimor/room/see/"+x
