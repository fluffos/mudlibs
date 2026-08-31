#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("knife");
   set_short("a runic dagger");
   set_long("A ritual dagger of some sort, the twisted, curved blade has many "
     "glowing white runes written on the blade blade. The entire knife seems "
     "to glow dimly with an evil power.");
   set_weight(9);
   set_id(({ "knife", "dagger", "runic dagger" }));
   set_wc(7);
   set_type("knife");
   set_value(250);
}

int query_auto_load() {
   if (this_player()->query_skill("knife") >= 55) return 0;
}
