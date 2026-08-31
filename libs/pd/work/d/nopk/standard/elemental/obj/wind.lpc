// a dungeonware.net production
// special for air elemental

#include <std.h>

#include <elemental.h>

inherit OBJECT;

void create() {
 ::create();
   set_name("wind");
   set_short("");
   set_id(({ "wind" }));
   set_long("");
   set_value(0);
   set_property("no steal", 1);
}

void init() {
 ::init();
   add_action("Wind", "wind");
}

int Wind(string str) {
    object ob;   
    int amount;
  
    if(this_player()->is_player()) remove();
    ob = this_player()->query_current_attacker();
    amount = 30 + random(30);
    ob->do_damage(amount);
    tell_object(ob, "%^BOLD%^%^CYAN%^The elemental sends a blast of wind into your stomach!%^RESET%^");
    tell_room(environment(this_player()), "%^BOLD%^%^CYAN%^The elemental sends a gust of wind into "+ob->query_cap_name()+"!%^RESET%^", ({ ob }));
    return 1;
}
