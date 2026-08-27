#include "path.h"
inherit "/std/item-shop";

object cont;

void setup()
{
  mixed *data;
  int i;
  object ob;

  set_zone("smithy");
  set_light(60);
	set_short("Cromach's smithy");
	set_long("You are in cromach's smithy. "+
		"A small cramped room with a large roaring fire blazing in "+
		"the center of the room.  There are various assorted smithy "+
		"tools scattered around the fire and hanging on the walls. "+
		"You can \"list\" the items for sale and \"buy\" them.\n");
        add_property("smithy", 1);
	add_exit("south", ROOM+"wall19", "door");
	add_exit("east", ROOM+"market1", "door");

	add_item("fire", "A roaring fire blazing in the center of the room. "+
									 "It is a coal fire built inside a stone walled "+
									 "well like thing.\n");
	add_item("tools", "You know, smithy tools, forks, pokers that sort of "+
										"thing.\n");
	add_armor("leather",0);
	add_armor("small wooden shield",0);
	add_armor("medium wooden shield",0);
	add_armor("studded leather",0);
	add_armor("ringmail",0);
	add_weapon("knife",0);
	add_weapon("short sword",0);
	add_weapon("dagger",0);
	add_weapon("mace",0);
}
