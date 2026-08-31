//  _burn.c
//      Mage ability
//      Written 15194 by Bohemund
//      base upon _missile.c
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
void help() {
  write("Syntax: <burn [(living)]>\n"
   "This spells causes your opponents body heat to rise, thereby causing "
   "spontanious combustion.\n");
}
int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "pyromancer" && tp->query_level() >= 2)
    return 1;
  return 0;
}
string type() { return "attack"; }
int cmd_burn(string str) {
  object tp, ob;
  int attack, wisdom, skip, which, i, x;
  string what, oi;
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
  if (this_player()->query_busy())
    return notify_fail("You are busy.\n");
  if(environment(tp)->query_property("no magic")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  if((int)tp->query_mp() < 15+ random(10)) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }
  if(!str) {
    ob = (object)tp->query_current_attacker();
    if(!ob) {
      notify_fail("Burn what?\n");
      return 0;
    }
  }
  else {
    ob = present(str, environment(tp));
    if(!ob) {
      notify_fail("Burn what?\n");
      return 0;
    }
  }
  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }
  if(ob==tp) {
    notify_fail("Not an incredibly intelligent idea.\n");
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query_property("no magic")) {
    notify_fail(sprintf("%s is immune to such magic.\n",
      ob->query_cap_name()));
    return 0;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "pyromancy", "magic attack" }),
   ({ "intelligence" }) );
  attack = attack*2/3;
  if(attack < 1) attack = 1;
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }
  write("%^BOLD%^%^RED%^You attempt to burn your opponent!%^RESET%^");
  tell_room(environment(tp), "%^RED%^%^BOLD%^"+(string)ob->query_cap_name()+
   " screams in agony as "+ob->query_title_gender()+
   " skin begins to smoke!\n%^RESET%^", ({ ob, tp }));
  tell_object(ob, "%^RED%^%^BOLD%^"+tp->query_cap_name()+
   " burns you!%^RESET%^");
  ob->do_damage("random", attack, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
  tp->set_magic_round();
  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));
  if (ob && ob->query_hp() < -1) {
    if ((string)ob->query_gender() == "male") {
      oi = "his";
    } else oi = "her";
    tell_room(environment(tp), "%^BOLD%^%^RED%^"+
     (string)ob->query_cap_name()+
     " releases a piercing scream as "+
     oi+
     " body bursts into flames!%^RESET%^", ({ ob }));
  }
  return 1;
}
