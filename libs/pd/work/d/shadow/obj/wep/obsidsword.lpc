#include <std.h>
#include <shadow.h>

inherit WEAPON;

void create() {
  ::create();

  set("id",({"sword","obsidian sword","obsidian"}));
  set_name("sword");
  set_short("an %^BOLD%^%^BLACK%^Obsidian%^RESET%^ Sword%^RESET%^");
  set("long","The sword has a dull luster which seems to suck in all the light.");
  set_weight(28);
    set_curr_value("gold", 90);
  set_wc(8);
  set_type("blade");
  set_wield("The darkness of the blade deepens, sucking in the light.");
  set_decay_rate(1000);
}

int query_auto_load() {
  if (this_player()->query_level() > 18)
  return 1;
}
