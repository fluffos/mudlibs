// bag.c
// A simple bag.
// Originally written by Truilkan 92/04/20.
// Updated to mudlib 0.9 by Mobydick, 10-14-92.
// This bag cannot be closed or locked. For an example of a container which
// can be both closed and locked, see /obj/chest.c.

#include <mudlib.h>

inherit CONTAINER ;

void create()
{
    ::create();
    set("id", ({"the bag", "a bag", "bag"}));
    set("short", "a bag");
// Containers have two long descriptions: one for open and one for closed.
// If a container can't be closed it doesn't need to set the closed one.
    set_open_long ("This is a small cloth bag that you could put things in.\n");
    set("bulk", 30);
    set ("mass", 15) ;
// Capacity is the total amount of mass than can be put in the bag, and
// volume is the total amount of bulk that can be put in.
    set ("capacity", 100) ;
    set ("volume", 25) ;
    set ("value", ({ 5, "silver" }) ) ;
}
