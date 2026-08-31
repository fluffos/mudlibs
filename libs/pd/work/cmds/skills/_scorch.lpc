#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
void help() {
  write("Syntax: <scorch [(living)]>\n"
  "This spell sends a powerful burst of flame against the caster's enemy."
  );
}
int spell() {
  object o;
  o = this_player();
  if (!o) return 0;
  if (o->query_level() < 10) return 0;
  if (o->query_subclass() != "pyromancer")  return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_scorch(string str) {
  object tp, ob;
  int attack, wisdom, skip, which, i;
  string what;
  object *inv;
  if (!spell()) {
    write("What?\n");
    return 1;
  }
  tp = this_player();
  if(tp->query_ghost()) {
    /*notify_fail("Your voice is hollow.\n"); */
    return 0;
  }
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if(environment(tp)->query_property("no magic")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  if((int)tp->query_mp() < 50) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }
  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Scorch who?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }
  if(ob==tp) {
    return notify_fail("That would not be very wise.");
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 2, ({ "pyromancy", "magic attack" }),
   ({ "intelligence" }) );
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  if(attack < 1)
    return notify_fail("Your spell fails.\n");
  write("%^BOLD%^%^RED%^You sc%^RESET%^%^BOLD%^o%^RED%^rch your enemy!%^RESET%^");
  tell_room(environment(tp), "%^BOLD%^%^RED%^An increadible heat fills the "
   +"room as flame sc%^RESET%^%^BOLD%^o%^RED%^rches "
   +(string)ob->query_cap_name()+"!%^RESET%^", 
   ({ ob, tp }));
  tell_object(ob, "%^BOLD%^%^RED%^"+tp->query_cap_name()+
   " sc%^RESET%^%^BOLD%^o%^RED%^rches you!%^RESET%^");
  ob->do_damage("target", attack, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
  tp->add_skill_points("pyromancy", attack/30 + 2);
  tp->add_mp(-BALANCE3_D->get_cost(attack, 2, "mp"));
  tp->set_magic_round();
  return 1;
}
