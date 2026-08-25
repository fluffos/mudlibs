#include "path.h"
inherit "/std/room";
object booklet,chainmail;

void setup()
{

        set_short("Trolls Cave");
        set_long("This is a large cave with a largish entrance to the "
                "North and and a smaller seemingly disused entrance to "
                "the South. In the room is a Pile of bones, a small  "
                "fire and a mouldy head. There are no stools strong "
                "enough to hold you which explains why there aren't any. "
                "By the fire is a small taterred booklet, possibly the "
                "next fire lighter. There is a pile of blankets in one "
                "but apart from that the room seems bare.\n");
                
        add_property("no_undead",1); set_light(100); 

        add_item("Cave", "This is a stone carved cave.\n");

        add_item("Bones", "These seem to be of Goblioid type, possibly an orc's.\n");

        add_item("Head" ,"Hmm, well it's a human head but it's green...must've gone "
                 "off. Looks tasty you think.\n");

        add_item("Blankets", "These are large and worn, but may keep you warm..\n");

        add_alias("cave", "Cave");
        add_alias("lair", "Cave");
        add_alias("bones", "Bones");
        add_alias("head", "Head");
        add_alias("blankets", "Blankets");
        add_exit("leave", "/d/ss/daggerford/ladyluck", "door");
        add_exit("north", PATH+"troll2", "door");

}

void reset()
{
  if(!sizeof(find_match("booklet", this_object())))
  {
    booklet = clone_object(BOOK);
    booklet->move(this_object());
  }
} /* void reset */

void dest_me()
{
  if (booklet) booklet->dest_me();
  if (chainmail) chainmail->dest_me();
  ::dest_me();
}

int do_search(string str)
{
   if (!chainmail)
   {
    chainmail=clone_object("/d/ss/baseobs/chainmail");
    chainmail->move(this_player());
    write("You find a Large Chainmail suit.  It  "
              "is well rusted and worn, but may be of some use.\n");
    tell_room(environment(this_player()), "searches arround and finds a "
                  "rusted chainmail.\n", (this_player()));
    return 1;
   }
   notify_fail("You find nothing of interest");
   tell_room(environment(this_player()), "scrambles arround for no "
         "apparent reason", (this_player()));
   return 0;
}


void add_equipment()
  {
  object boo;

  boo = clone_object("/baseobs/weapon/spear");
  boo->move(this_object());

  /* You can use boo for all the equipment..*/
  boo = clone_object("/baseobs/armour/cloak");
  boo->move(this_object());
  return;
}    

