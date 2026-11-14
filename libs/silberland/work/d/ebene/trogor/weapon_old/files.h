#define HOME(x) "/d/ebene/trogor"+x
#define CLONEME(x) clone_object(x)->move(ME)
#define XX(x) if (!is_clone(this_object())) return   
#define ROOM(x) ("/d/ebene/trogor/room/")+x
#define WEG(x) ("/d/ebene/trogor/weg/")+x
#define OBJ(x) ("/d/ebene/trogor/obj/")+x
#define WEAPON(x) "/d/ebene/trogor/weapon/"+x
#define ARMOUR(x) "/d/ebene/trogor/armour/"+x
#define NPC(x) ("/d/ebene/trogor/npc/")+x

#define TK(x) if(find_player("trogor"))tell_object(find_player("trogor"),x)

#define bs( x ) break_string( x, 78 )

#include <defines.h>
#include <moredef.h>

