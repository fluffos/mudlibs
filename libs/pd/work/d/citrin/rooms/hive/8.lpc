//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a bee hive");
    set_short("a bee hive");
    set_long("Honey drips from the sides of the hive.  The floor "
      "is covered with thick bee mucus.  An occasional bee passes "
      "by carrying pollen back to the combs.  Larvae are in most "
      "of the combs.  A throne sits in the middle of the room "
      "with the high queen bee sitting upon it.");
    set_items(([
      ]));
    set_exits(([
	"down":HIVE"5",
      ]));
}

void reset() {
    ::reset();
    if(!present("queen bee")) 
	new(MON"queenbee")->move(this_object());
}


