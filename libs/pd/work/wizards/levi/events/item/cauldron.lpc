inherit "/std/bag_logic";

void create() {
set_id(({"cauldron", "wicked cauldron"}));
set_name("cauldron");
set("short", "%^BOLD%^%^BLACK%^G%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^shama%^RESET%^%^ORANGE%^'s %^BLACK%^%^BOLD%^Wick%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^d C%^RESET%^%^ORANGE%^au%^BOLD%^%^BLACK%^ldr%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^");
set_weight(300);
set("long", "This huge, black iron cauldron is large and could probably hold a good deal of contents.\n");
set_curr_value("gold",90);
 set_max_internal_encumbrance(5000);
}

int query_auto_load() {
  if(this_player()->query_level() < 5) return 0;
  return 1;
}
