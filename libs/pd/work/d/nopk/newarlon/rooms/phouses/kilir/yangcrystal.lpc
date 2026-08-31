#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("crystal");
   set_short("%^RED%^D%^BOLD%^a%^MAGENTA%^r%^RESET%^%^MAGENTA%^k %^RED%^Cr%^BOLD%^y%^MAGENTA%^st%^RESET%^%^MAGENTA%^al%^RESET%^");
   set_long("As you look over the crystal you hear the souls of the fallen plead for their release.  The Haunting sounds soon turn into screams and drown out all sounds of life around you.  You grip your heart feeling unnatural sorrow.");
   set_weight(3);
   set_type("necklace");
   set_limbs(({"head"}));
   set_ac(1);
   set_id(({ "crystal", "dark crystal", "yangcrystal" }));
   set_property("magic item", ({"shatter"}) );
}
void init() {
 ::init();
   add_action("shat", "shatter");
}
int shat(string str) {
    object tp;
    tp = this_player();
   if (str != "crystal") return 0;
   if (environment(tp)->query_property("no teleport")) return notify_fail("You cannot do that here.\n");
   if (tp->query_current_attacker()) return notify_fail("You cannot do that in battle!\n");
   if (tp->query_arena()) return notify_fail("You cannot do that in the arena!");
   if (tp->query_ghost()) return notify_fail("You cannot use that as a ghost.");
   write("%^BOLD%^%^MAGENTA%^The shards of crystal on the ground begin to spin around you as you start to vanish.\n");
   tell_room(environment(tp), "%^BOLD%^%^MAGENTA%^Shards of crystal start spinning around "+this_player()->query_cap_name()+"!\n", ({ this_player() }));
   call_out("goingalready", 6, tp);
   return 1;
}
int goingalready(object tp) {
    int sps;
    if (!tp) return 0;
    if (tp->query_ghost()) {
      message("system","The energies fail to transport your ethereal being.",tp);
      return 0;
    }
    write("\n%^BOLD%^%^MAGENTA%^Your crystal reforms itself as you appear in your room.\n");
    message("info", "%^BOLD%^%^MAGENTA%^"+tp->query_cap_name()+" vanishes from sight!", environment(tp), tp);
    if((sps = this_player()->query_sp()) < 0)
      this_player()->set_sp(20); this_player()->move_player("/d/nopk/newarlon/rooms/phouses/kilir/yang", "in a flash of light!");
    this_player()->set_sp(sps);
    return 1;
}
int query_auto_load() {return 1;}
