//      _pillar.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <manabolt [(living)]>\n"
   "A strong wizard can combine their energy with "
   "the energy of the sky to bring down a powerful "
   "bolt of energy upon their enemies.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 45) return 0;
  if (tp->query_skill("wizardry") < 268) return 0;
  if(wizardp(this_player()) ) return 1;

  return 1;
}
string type() { return "attack"; }
int cmd_manabolt(string str) {
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

  if(tp->query_casting()) return notify_fail("You are already casting a spell!");

  if((int)tp->query_mp() < 35) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Bring the energy down on whom?");

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
  attack = BALANCE3_D->get_damage( tp, ob, 3, ({ "magic attack", "wizardry", "wizardry" }),
   ({ "intelligence", "wisdom", "intelligence" }), ({"wizardry", "magic attack", "conjuring"}) );

  attack = attack * 1.1;

  if(attack < 1) attack = 1;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^ORANGE%^You raise your hands into the air, creating a large %^BOLD%^%^WHITE%^pillar%^RESET%^%^ORANGE%^ of %^CYAN%^%^BOLD%^energy%^RESET%^%^ORANGE%^ all around you that reaches into the %^BOLD%^%^BLUE%^sky%^RESET%^%^ORANGE%^.\n");
  write("%^ORANGE%^A powerful %^YELLOW%^bolt%^RESET%^%^ORANGE%^ of pure %^CYAN%^%^BOLD%^energy%^RESET%^%^ORANGE%^ streaks from the sky and %^BOLD%^%^RED%^strikes%^RESET%^%^ORANGE%^ " +ob->query_cap_name()+ " with horrific force!");

  message("room","%^ORANGE%^" +tp->query_cap_name()+ 
   " raises " 
   +tp->query_possessive()+   
   " hands into the air and creates a large %^BOLD%^%^WHITE%^pillar%^RESET%^%^ORANGE%^ of %^CYAN%^%^BOLD%^energy%^RESET%^%^ORANGE%^ around " 
   +tp->query_objective()+ "self, and within seconds a huge %^YELLOW%^bolt%^RESET%^%^ORANGE%^ of energy streaks down from the %^BOLD%^%^BLUE%^sky%^RESET%^%^ORANGE%^ and %^BOLD%^%^RED%^strikes%^RESET%^%^ORANGE%^ "
   +ob->query_cap_name()+"!"
   , environment(tp), ({tp,ob}));            

  message("room","%^ORANGE%^" +tp->query_cap_name()+ 
   " raises " 
   +tp->query_possessive()+   
   " hands into the air and creates a large %^BOLD%^%^WHITE%^pillar%^RESET%^%^ORANGE%^ of %^CYAN%^%^BOLD%^energy%^RESET%^%^ORANGE%^ around " 
   +tp->query_objective()+ "self, and within seconds a huge %^YELLOW%^bolt%^RESET%^%^ORANGE%^ of energy streaks down from the %^BOLD%^%^BLUE%^sky%^RESET%^%^ORANGE%^ and %^BOLD%^%^RED%^strikes%^RESET%^%^ORANGE%^ you!"
   , ob);     

  ob->do_damage("target", attack, DAMAGE_MAGIC, 0, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("wizardry", attack/20 + 2);    

  tp->add_mp(-BALANCE3_D->get_cost(attack, 3, "mp"));

  tp->set_magic_round();

  return 1;
}
