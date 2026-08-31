#include <std.h>
#include <illuminati.h>

inherit OBJECT;
void create() {
 ::create();
   set_name("seal");
   set_short("Seal of the Illuminati");
   set_long("A stone seal depicting the Tower of Light.");
   set_weight(1);
   set_curr_value("gold", 150);
   set_id(({ "seal", "illuminati seal", "seal of tirun" }));
   set_property("magic item", ({"break"}) );
}

void init() {
 ::init();
   add_action("crack", "break");
}

int crack(string str) {
    object tp;
    tp = this_player();
   if (tp->query_guild() != "illuminati") return 0;
   if (str != "seal") return 0;
   if (environment(tp)->query_property("no teleport")) return notify_fail("You cannot do that here.\n");
   if (tp->query_current_attacker()) return notify_fail("You cannot do that in battle!\n");
   if (tp->query_arena()) return notify_fail("You cannot do that in the arena!");
   write("%^YELLOW%^Mystical energies engulf you!\n%^RESET%^");
   tell_room(environment(tp), "%^YELLOW%^Mystical energies engulf "+this_player()->query_cap_name()+"!\n%^RESET%^", ({ this_player() }));
   remove_action("crack", "break");
   call_out("goingalready", 6, tp);
   return 1;
}

int goingalready(object tp) {
    int sps;
    write("\n%^YELLOW%^You appear in the Illuminati Hall!\n%^RESET%^");
    message("info", "%^YELLOW%^"+tp->query_cap_name()+" vanishes from sight!%^RESET%^", environment(tp), tp);
    if((sps = this_player()->query_sp()) < 0)
      this_player()->set_sp(20);
    this_player()->move_player(ILROOM"newhall", "in a flash of light!");
    this_player()->set_sp(sps);
    this_object()->remove();
    return 1;
}
int query_auto_load() {
    if(this_player()->query_guild() == "illuminati")
      return 1;
    return 0;
}
