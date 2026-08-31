//      _fireball.c
//      Mage ability
//      Written 131092 by Descartes of Borg
#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
void help() {
  message("help",
   "Syntax: <fireball [living]>\n\n"
   "This spell sends a ball of fire flying towards the target.",
   this_player() );
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "pyromancer") return 0;
  if (tp->query_level() < 4) return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_fireball(string str) {
  object tp, ob;
  int attack, wisdom, skip, which, i;
  string what, *strengths, *weaknesses;
  object *inv;
  if (!spell()) {
    notify_fail("What?\n");
    return 0;
  }
  tp = this_player();
  if(tp->query_ghost()) {
    notify_fail("Your voice is hollow.\n");
    return 0;
  }
  if(environment(tp)->query_property("no magic") || environment(tp)->query_property("no attack")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if((int)tp->query_mp() < 20) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }
  if(!str) {
    ob = (object)tp->query_current_attacker();
    if(!ob) {
      notify_fail("Fireball what?\n");
      return 0;
    }
  }
  else {
    ob = present(str, environment(this_player()));
    if(!ob) {
      notify_fail("Fireball what?\n");
      return 0;
    }
  }
  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }
  if(ob == tp) {
    notify_fail("Not a very bright thing to do.\n");
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query_property("no magic")) {
    notify_fail(sprintf("%s is immune to your magic.\n",
      ob->query_cap_name()));
    return 0;
  }
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "pyromancy", "magic attack" }),
   ({ "intelligence", "intelligence", "wisdom" }) );
  attack = attack*3/4;
  if(attack < 1) attack = 1;
  write("%^RED%^%^BOLD%^You cast a f%^YELLOW%^ir%^RED%^eb%^YELLOW%^al%^RED%^l at "+
   (string)ob->query_cap_name()+".");
  tell_room(environment(tp), "%^RED%^%^BOLD%^"+tp->query_cap_name()+
   " casts a f%^YELLOW%^ir%^RED%^eb%^YELLOW%^al%^RED%^l at "+(string)ob->query_cap_name()+".", 
   ({ ob, tp }));
  tell_object(ob, "%^RED%^%^BOLD%^"+tp->query_cap_name()+
   " casts a f%^YELLOW%^ir%^RED%^eb%^YELLOW%^al%^RED%^l at you.");
  ob->do_damage("target", attack, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
  tp->set_magic_round();
  tp->add_skill_points("magic attack", random(20));
  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));
  return 1;
}
