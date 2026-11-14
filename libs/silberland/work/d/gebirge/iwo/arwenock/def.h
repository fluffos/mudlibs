/*
 * Master defines fuer Arwenock
 *
 * Iwo@SL
 *
 */

#define REGION "gebirge"
#define APATH "/d/gebirge/iwo/arwenock/"
#define ALOG APATH "log/"
#define ROOM APATH "room/"
#define NPC APATH "npc/"
#define OBJ APATH "obj/"
#define ARMOUR APATH "armour/"
#define WEAPON APATH "weapon/"
#define AMASTER APATH "master/master"
#define TMASTER APATH "master/tangram.lpc"

#define CAVEPATH APATH "cave"

#define CAVEMASTER APATH "cave/master/master"

#define CAVEMAP APATH "/cave/map.lpc"

#define STADT "Arwenock"

#define STDWEG ROOM "std/weg.lpc"
#define STDROOM ROOM "std/room"
#define STDNPC NPC "std/npc"
#define STDMNPC NPC "std/mnpc"

#define TORE (["Haupttor": 1; ROOM "room_B-04", ])

#define EVENT_ARKENS 30

#define DOORS_LOCKED 0

#define TMI(x) if(find_player("iwo")) tell_object(find_player("iwo"), break_string(x, 78, "ARWENOCK: "))

// by PROtheG
#define CLOSURE(x) #'x

// by -Crea-

#define BS(x) break_string(x, 78)
#define TO this_object()
#define TP this_player()
#define TI this_interactive()
#define TIPO this_interactive()||previous_object()
#define ENV(x) environment(x)
#define CAP(x) capitalize(x)



