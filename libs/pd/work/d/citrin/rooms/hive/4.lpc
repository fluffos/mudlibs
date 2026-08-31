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
	"northeast":HIVE"7",
	"northwest":HIVE"6",
	"south":HIVE"1",
      ]));
}

void reset() {
    int i;
    ::reset();
    i = random(3);
    if(i == 0) i = 1;
    if(!present("hive keeper")) 
	new(MON"hivekeeper")->move(this_object());
    if(!present("slave bee"))
	while(i--) {
	    new(MON"slavebee")->move(this_object());
	}
}

