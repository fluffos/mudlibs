#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("skean");
   set_short("a razor sharp skean");
   set_long("The skean is a very sharp, very deadly, dagger. The "
     "blade of the skean has been sharpened on both sides to an "
     "increadibly sharp edge.");
   set_weight(6);
   set_id(({ "skean", "dagger", "knife" }));
   set_wc(5);
   set_type("knife");
   set_value(160);
}

int query_auto_load() {
   if (this_player()->query_level() >= 19) return 0;
}
