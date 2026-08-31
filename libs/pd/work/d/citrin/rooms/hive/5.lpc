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
	"southwest":HIVE"6",
	"up":HIVE"8",
      ]));
    set_pre_exit_functions( ({"up"}), ({"go_up"}) );
}

void reset() {
    int i;
    ::reset();
    i = random(6);
    if(i == 0) i = 1;
    if(!present("guardian bee")) {
	new(MON"guardbee")->move(this_object());
	new(MON"guardbee")->move(this_object());
    }
}

int go_up() {
    if(present("guardian bee")) {
	write("One of the guardian bees stop you.\n");
	return 0;
    }
    return 1;
}

