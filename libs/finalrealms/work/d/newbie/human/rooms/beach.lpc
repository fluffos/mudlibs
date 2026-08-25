#include "path.h"
inherit "/std/outside";
object *monsters;
string *monlist = ({"crab","snake","seal"});
string mon;

create()
{
   ::create();
    set_short("Isle of Havmand: Beach.");
    set_night_long("\nIsle of Havmand : Beach\n\n"
    "   Little flecks of light reflect off the sand and water at night, even when "
    "there is no obvious light source.  The waves pound against the shore and "
    "your feet crunch as you walk across the sand. "
    "\n\n");
    add_item("sand","Soft, fine white sand covers the beach. When you try to "
    "pick some up, it trickles warmly through your fingers. \n");
    add_item(({"water","waves","surf","sea"}),"Waves race into the shore and "
    "retreat again, their white peaks foaming as they hit the beach. \n");
    add_feel("sand","The sand feels gritty, but warm as it runs through your "
    "fingers.\n");
    add_sound(({"waves","surf"}),"You hear the rythmic pounding of the surf."
   "\n");
    add_sound("crunch","As you move across the sand, your feet make a "
    "crunching noise.\n");
    add_feel("water","The water feels warm to touch.\n");
    add_sound("birds","You can hear the sounnd of seabirds calling.\n");
    add_smell("air","The smell of salt is very strong in the air.\n");
      add_property("no_undead",1);


    if(random(BEACH_ANIMAL) == 0)
    {
        monsters = allocate(random(BEACH_ANIMAL_MAX)+1);
    }
    mon = CHARS+monlist[random(sizeof(monlist))];

   this_object()->setup();
   reset();
}
void reset()
{
    int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
         if(!monsters[i])
         {
                monsters[i] = new(mon);
                monsters[i]->move(this_object());
        }
    }
}
void dest_me()
{
    int i;
    for(i = 0; i < sizeof(monsters); i++)
    {
        if(monsters[i]) monsters[i]->dest_me();
    }
    monsters = 0;
    ::dest_me();
}


