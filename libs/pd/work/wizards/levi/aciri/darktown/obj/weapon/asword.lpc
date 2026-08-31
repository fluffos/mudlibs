#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("blade");
   set_short("thin blade of gilded steel");
   set_long("The thin blade of gilded steel was crafted as thin and "
     "wide as a shortsword, but as long as a longsword. It is "
     "designed for the speed the larger swords can never have.");
   set_weight(8);
   set_id(({ "blade", "sword", "gilded blade" }));
   set_wc(7);
   set_type("blade");
   set_value(150);
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 3; }
