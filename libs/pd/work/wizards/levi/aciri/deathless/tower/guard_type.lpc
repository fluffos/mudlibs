#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_level(64);
   set_auto(30);
   set_properties(([ "no bump" : 1 ]));
   set_race("guardian");
   set_body_type("human");
}

int stop_up() {
   write(capitalize(this_object()->query_name())+" stops you from going "
	"up.");
   return 1;
}

void init() {
 ::init();
   add_action("stop_up", "up");
}
