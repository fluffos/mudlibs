#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("amulet");
    set("id", ({"amulet", "symbol", "holy symbol of lathandar"}) );
    set_short("Holy Symbol of Lathander");
    set_long("This is a golden amulet of what appears "
      "to be a sun rising over the mountains.  It says along the "
      "base 'There is always another "
      "morning' and in the sun the tiny "
      "words 'In the dawn, beauty reigns, "
      "and the way is clearer.'  No evil hands "
      "could ever touch this sacred object.");
    set_type("amulet");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "starratiel")
	return 1;
}

