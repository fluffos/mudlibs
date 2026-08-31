#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("whip");
   set_short("a three pronged whip");
   set_long("A long, black leather whip. There are three prongs "
     "extended from the leather handle. At the end of each prong is "
     "a silver razorblade.");
   set_weight(7);
   set_id(({ "whip", "three pronged whip" }));
   set_wc(6);
   set_type("flail");
   set_value(350);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 0;
}
