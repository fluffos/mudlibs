#include <std.h>;
#include <purgatory.h>;

inherit QUIVER;

void create() {
  ::create();

  set_name("quiver");
  set("id", ({ "quiver" }) );
  set("short", "%^BOLD%^%^BLACK%^Obsidian quiver%^RESET%^");
  set("long", "A dark quiver embedded with Osidian rocks, it looks like it will hold quite a few arrows.");
  set_type("quiver");
  set_ac(2);
  set_limbs( ({ "torso" }) );
  set_weight(15);
    set_curr_value("gold", 40+random(120));
}

int query_auto_load() {
  if (this_player()->query_level() > 30)
  return 1;
}
