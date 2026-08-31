#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("hammer");
   set_short("a heavy sledgehammer");
   set_long("A three foot sledgehammer with a heave metal end. The "
     "sledgehammer would make a fierce weapon.");
   set_weight(21);
   set_id(({ "hammer", "sledgehammer" }));
   set_wc(6);
   set_type("blunt");
   set_value(250);
}

int query_auto_load() {
   if (this_player()->query_level() >= 23) return 0;
}
