#include "path.h"

inherit "/std/shop";

void setup() {
  set_short("Korbus street shop");
  set_long("You are in Korbus street shop off the market.  The shiny "+
	 "counter to your north has many interesting objects on display "+
	 "behind it.  Type \"list\" to get a list of the wonderful objects "+
	 "\"browse\" to look at your object before you buy it, \"value\" "+
	"to value your object before you \"sell\" it and of course \"buy\" "+
	"to buy your wonderous object.\n");
	set_light(60);
	add_exit("west", ROOM+"market2", "door");
	set_store_room(ROOM+"store2");
  add_item("counter", "A display counter for the wares of the shop.  Use the "+
    "command \"list\" to get a list of what they are.\n");
  add_item("object", "Use \"list\" to get a list of what is for sale.\n");
  add_alias("objects", "object");
}
