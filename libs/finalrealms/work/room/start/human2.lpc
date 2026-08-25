#include "path.h"
inherit "/std/room";
object booklet;

void setup()
{
        set_short("Kitchen");

        set_long("  You appear to be in a kitchen, it has various cooking "
                "utensils scattered across a large wooden table. There is "
                "a large wood burining stove in the corner and a pile of "
                "wood stacked next ot it. There is a small sink on the "
                "east wall, above the sink is a small window. There is a "
                "big cupboard on the west wall which looks like it is used "
                "for storing food.\n");
                                                       
        add_property("no_undead",1); set_light(100); 

        add_item("cupboard", "The doors to the cupboard are closed maybe "
                "you could search it.\n");

        add_item("stove", "This looks like any ordinary stove. The door "
                "is closed.\n");

        add_item("sink", "This sink looks very dirty and you would think "
                "someone would clean the pans.\n");
        
        add_item("wood", "The wood is just ordinary rough cut firewood.\n");
        
        add_item("window", "The view from the window is a large expanse of "
                "open fields.\n");

        add_item("utensils", "These are just a collection of normal cooking "
                "utensils.\n");

        add_exit("north", PATH+"human","door");
}

void reset()
{
  if(!sizeof(find_match("booklet", this_object())))
  {
    booklet = clone_object(BOOK);
    booklet->move(this_object());
  }
} /* void reset */

void dest_me ()
{
  if (booklet) 
    booklet->dest_me();
} /* dest_me */
