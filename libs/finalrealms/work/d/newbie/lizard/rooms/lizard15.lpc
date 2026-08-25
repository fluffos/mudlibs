/* Added by Galvin 95-05-06 */
#include "path.h"
inherit ROOM+"baseroom";

object b_lizard,hider;

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     You have come to a small clearing in the swamp. A clay hut is "
         "leaning against a huge gnarled tree and in front of the hut there "
         "is a small fire sparkling under a big cauldron. A bit to the left "
         "of the fire a small altar is standing. A quick glance inside the "
         "hut reveals nothing besides a straw bed and a rough wooden table. "
         "This place is almost free from the persistent mist and the ground "
         "is dry and free from vegetation. \n\n");
add_property("no_undead",1);
add_item("tree", "This must be one of the largest and oldest trees in the "
         "whole swamp. It's covered with swampmoss but lack the vines that "
         "are so common around here. Leaning against the tree is a small "
         "clay hut. \n\n");
add_item("ground", "It's dry and free from vegetation. A lot of footprints "
         "can be seen around here. \n\n");
add_item("footprints", "It looks like lizard-men footprints. \n\n");
add_item("hut", "It's small, made of clay and very old. \n\n");
add_item("altar", "A small stone altar dedicated to the Great swamp god.\n\n");
add_item("fire", "The fire is eating hungrily through a couple of logs. \n\n");
add_item("table", "A rough wooden table that has seen it's better days. \n\n");
add_item("bed", "A dirty lump of straw. You would rather sleep standing than "
         "use this. \n\n");
add_item("stew", "A dark stew with black floating shapes in it. \n\n");
add_item("shapes", "Mmmm, it's your favourite stew. Boiled black lizard.\n\n");
add_item("cauldron", "The cauldron is old-looking and a dark stew is "
         "boiling in it. \n\n");
add_exit("east",SWAMP +"lizard16","room");
}
void init ()     {
add_action("do_eat", "eat");
  ::init();
} /* init () */
int do_eat(string str)    {
  if(str == "stew")
    {
     if(b_lizard && environment(b_lizard) == hider)
       {
        write("As you approach the cauldron a black lizard jumps out of the "
              "stew! \n\n");
        say(this_player()->query_cap_name() + " approaches the cauldron and "
              "is jumped by a black lizard. \n\n");
        b_lizard->move(this_object());
        b_lizard->attack_ob(this_player());
        ::init();
        return 1;
       }
        else
        write("You eat a delicious stew. \n\n");
        ::init();
        return 1;
     }
      return 0;
}

void reset()
  {
  if (!hider)
    {
      hider = clone_object("/std/container");
      hider->reset_get();
    }
  if (!b_lizard)
    {
       b_lizard = clone_object("/d/newbie/lizard/npcs/b_lizard");
      b_lizard->move(hider);
    }
} /* reset */

void dest_me()
  {
    if(hider)
      hider->dest_me();
    if(b_lizard)
      b_lizard->dest_me();
    ::dest_me();
  } /* dest_me */
