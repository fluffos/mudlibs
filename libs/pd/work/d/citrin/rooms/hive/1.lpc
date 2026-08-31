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
      "of the combs.");
    set_items(([
      ]));
    set_exits(([
	"out":ROOMS"22",
	"north":HIVE"4",
	"east":HIVE"2",
	"west":HIVE"3",
      ]));
    set_pre_exit_functions( ({"north"}), ({"north"}) );
}

int north() {
    if(random(2)) {
	write("The way north is covered by too much honey to "
	  "go that way right now.\n");
	return 0;
    }
    write("You barely make it through the honey.\n");
    return 1;
}

