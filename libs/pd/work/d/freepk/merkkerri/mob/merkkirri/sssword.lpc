#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"sword", "sharp steel sword", "sharp sword", "steel sword"}));
set_name("sword");
set_short("a sharp steel sword");
set_long("This is a plain sword made of steel.  It has razor sharp edges and
the blade itself is slightly wider than most swords.");
set_weight(16);
set_curr_value("gold",75);
set_wc(11);
set_ac(1);
set_type("blade");
}

int query_auto_load() {
  if(this_player()->query_level() < 45) return 0;
  return 1;

}
