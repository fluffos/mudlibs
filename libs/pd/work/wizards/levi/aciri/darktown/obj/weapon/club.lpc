#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("club");
   set_short("a small club");
   set_long("The small club can be wielded with a single hand. It "
     "is not really a club at all, but rather a strong oval shaped "
     "bag filled with lead pellets.");
   set_weight(12);
   set_id(({ "club" }));
   set_wc(6);
   set_type("blunt");
   set_value(150);
}

int query_auto_load() {
   if (this_player()->query_skill("blunt") >= 20) return 3;
}
