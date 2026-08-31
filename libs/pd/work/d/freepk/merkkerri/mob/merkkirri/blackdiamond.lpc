//	/obj/bag.c
//	from the Nightmare mudlib
//	a simple bag
//	created for the TMI distribution mudlib
//	by Truilkan 20 April 1992

inherit "/std/bag_logic";

void create() {
  ::create();
set_id(({"diamond", "black diamond"}));
set_name("diamond");
set("short", "a %^BOLD%^%^BLACK%^Black Diamond%^RESET%^");
set_weight(12);
set("long", "This is a black diamond of immense size.  You could easily sell it for a hefty price.\n");
set_curr_value("gold",150);
 set_max_internal_encumbrance(5000);
}

int query_auto_load() {
  if(this_player()->query_level() < 5) return 0;
  return 1;
}
