#include "path.h"
inherit "/std/outside";
object *monsters;
string mon;

create()
{
   ::create();
    set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.");
    set_night_long("\nIsle of Havmand: Pirate Camp.\n"
    "   All you can see is dark shapes against a darker background. There seem "
    "to be small dwellings built under the trees, but you can't see any details "
    "in the darkness. "
    "\n\n");
    add_property("no_undead",1);
    monsters = allocate(random(PIRATES));
   this_object()->setup();
   reset();

}
void reset()
{
    int i;
    if(monsters)
    {
        for(i = 0; i < sizeof(monsters); i++)
        {
            if(!monsters[i])
            {
                monsters[i] = new(CHARS+"pmice");
                monsters[i]->move(this_object());
            }
        }
    }
}
void dest_me()
{
    int i;
    if(monsters)
    {
   for(i = 0; i < sizeof(monsters); i++)
        if(monsters[i]) monsters[i]->dest_me();
    }
    ::dest_me();
}
