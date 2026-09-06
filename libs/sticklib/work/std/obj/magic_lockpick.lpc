// Magic Lockpick
// This one can sometimes be found at the following locations:
//  - The ettin in the sewers ( /areas/sewers/npc/ettin.c )
//  - The treasury in the crypt ( /areas/sewers/crypt/treasury.c )
//  - Baranov the white dragon ( /areas/faraway/npc/baranov.c )
//
// It is unique and handles its own uniqueness. It has a random
// chance of being genuine.
// 
#include <treasure.h>
#include <daemons.h>

status is_genuine;

void
create_treasure()
{
    UNIQUE_D->create_unique(object_name(this_object()), 2 );
    if ( !random(3)
      && UNIQUE_D->query_unique(object_name(this_object())))
    {
	UNIQUE_D->add_unique(object_name(this_object()),this_object());
	is_genuine = 1;
	set_name("lockpick");
	set_id(({"lockpick", "lock pick", "pick", "glowing" }));
	set_short("A glowing lockpick");
	set_long(
	  "This is a very rare, and illegal, item to open doors with. This\
 one glows with a strange blue light.");
	set_value(500);
    }
    else
    {
	is_genuine = 0;
	set_name("bauble");
	set_id(({"bauble", "golden bauble" }));
	set_short("A golden bauble");
	set_long(
	  "This is a pretty golden bauble. It doesn't appear useful\
 for anything except possibly as a gift.");
	set_value(200);
    }
    set_weight(1);
}

status get() { return 1; }
status query_thief_item() { return is_genuine; }
