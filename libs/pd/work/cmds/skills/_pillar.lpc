//      _pillar.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <pillar [(living)]>\n"
   "The wizard will focus all of their energy "
   "on their target, causing a pillar of pure energy "
   "to surround them.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 20) return 0;
  if (tp->query_skill("wizardry") < 118) return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_pillar(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;

  if (!spell()) {
    return 0;
  }

  tp = this_player();

  if(tp->query_ghost()) {
    notify_fail("You emit a ghostly moan.\n");
    return 0;
  }

  if (tp->query_busy())
    return notify_fail("You are too busy to cast this spell.\n");

  if(environment(tp)->query_property("no magic")
   || environment(tp)->query_property("no attack")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }

  if((int)tp->query_mp() < 20) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Surround who with energy?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("You look silly.\n");
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
  attack = BALANCE3_D->get_damage( tp, ob, 2, ({ "magic attack", "wizardry", "wizardry" }),
   ({ "intelligence", "wisdom", "intelligence" }), ({"wizardry", "conjuring"}) );

  attack = attack;

  if(attack < 1) attack = 1;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^ORANGE%^You bring your hands together, and focus all your %^YELLOW%^e%^BOLD%^%^CYAN%^n%^YELLOW%^e%^BOLD%^%^CYAN%^r%^YELLOW%^g%^BOLD%^%^CYAN%^y%^RESET%^%^ORANGE%^ on " 
   +ob->query_cap_name()+
   ", creating a large %^BOLD%^%^WHITE%^pillar%^RESET%^%^ORANGE%^ of %^YELLOW%^light%^RESET%^%^ORANGE%^ all around them!");

  message("room","%^ORANGE%^" +tp->query_cap_name()+ " slaps " +tp->query_possessive()+   
   " hands together and watches as " +ob->query_cap_name()+ 
   " is surrounded by a %^BOLD%^%^WHITE%^pillar%^RESET%^%^ORANGE%^ of %^YELLOW%^light%^RESET%^%^ORANGE%^!"
   , environment(tp), ({tp,ob}));            

  message("ob", "%^ORANGE%^" +tp->query_cap_name()+ " slaps " +tp->query_possessive()+ 
   " hands together and looks at you, suddenly you find yourself surrounded by %^BOLD%^%^WHITE%^light%^RESET%^%^ORANGE%^!",ob);

  ob->do_damage("target", attack, DAMAGE_MAGIC, 0, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("wizardry", attack/20 + 2);    

  tp->add_mp(-BALANCE3_D->get_cost(attack, 2, "mp"));

  tp->set_magic_round();

  return 1;
}
