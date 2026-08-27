#include "path.h"
inherit "/std/room";
object booklet;

void setup()
{
        set_short("Elfen Kitchen.");

        set_long("This is the well used kitchen of your family home. "
                "There is a large wood burning stove with a pile of "
                "wood at one side of it. There is a large cupboard which "
                "is closed. There is a table in the centre of the room which "
                "you remember having many a good home cooked meal. There "
                "is a single door to the west.\n");

        add_property("no_undead",1); set_light(70); 

        add_item("stove", "This is an old fashioned stove which looks like it "
                "hasn't been used for many years. This is as clean as your "
                "mother left it still though.\n");

        add_item("wood", "The wood is good solid, slow burning wood, which is actually "
                "past it's best because it is slightly damp.\n");

        add_item("cupboard", "This is a large cupboard used to store food in.\n");

        add_item("table", "This is a large square table where you regulary ate.\n");
        add_exit("west", PATH+"elf", "door");


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

        



