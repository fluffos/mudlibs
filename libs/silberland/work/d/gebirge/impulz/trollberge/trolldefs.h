// Include-File fuer die Trollberge
// by Impulz

#define P_ENEMYLIST "enemylist"

#ifndef __TROLLDEFS_H__
#define __TROLLDEFS_H__

#ifndef TI
#define TI(x) if (find_player("impulz")) tell_object(find_player("impulz"),x)
#endif

#ifndef TROLLBERGE
#define TROLLBERGE(x) "/d/gebirge/impulz/trollberge/"+x
#endif

#ifndef ROOM
#define ROOM(x) TROLLBERGE("room/")+x
#endif

#ifndef NPC
#define NPC(x) TROLLBERGE("npc/")+x
#endif

#ifndef OBJ
#define OBJ(x) TROLLBERGE("obj/")+x
#endif

#endif