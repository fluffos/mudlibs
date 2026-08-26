// warehouse.c
// This is the central shop storeroom. All shops have access to the contents
// of this room unless it that access is removed.
// Keep this room stocked with mundane general stuff like torches and basic
// swords and armor. Most general purpose shops will want to keep access to
// it, while specialty shops will want to get rid of it.
// Created by Mobydick@TMI-2, 8-25-92

#define NUM_OBJ 6
#define OBJ_LIST ({ "/obj/torch", \
		    "/obj/torch", \
		    "/obj/axe", \
		    "/obj/dagger", \
		    "/obj/dagger", \
	 	    "/obj/sword", \
		})

#include <mudlib.h>

inherit ROOM ;

object *ob ;

void reset() ;

void create() {
	::create() ;
	ob = allocate(NUM_OBJ) ;
	seteuid(getuid()) ;
	set ("short", "Central shop storeroom") ;
	set ("long", "This is the room where objects that are available for sale at all general\n" +
	"purpose stores are kept. No Players!\n") ;
	set ("light", 1) ;
	reset() ;
}

void reset() {

	int i ;

        if (!ob)
		return;

	for (i=0;i<NUM_OBJ;i++) {
		if (!ob[i] || environment(ob[i])!=this_object()) {
			ob[i] = clone_object(OBJ_LIST[i]) ;
			ob[i]->move(this_object()) ;
		}
	}
}

// We don't want this to clean up or an error will occur if the shop tries
// to refer to it.

int clean_up() { return 0; }
