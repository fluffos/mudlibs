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
	"west":HIVE"1",
      ]));
}

void reset() {
    int i, x, count;
    object *all;
    ::reset();
    i = random(10);
    x = sizeof(all = all_inventory(this_object()));
    while(x--) {
	if(all[x]->id("worker bee")) count++;
    }
    x = (10-count);
    while(x--) {
	new(MON"workerbee")->move(this_object());
    }
}

