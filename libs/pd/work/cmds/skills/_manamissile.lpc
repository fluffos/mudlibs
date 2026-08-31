//      _pillar.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <manamissile [(living)]>\n"
   "The more mature Wizard can modify the ancient "
   "magic missile spell into a more powerful and "
   "lethal attack.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 30) return 0;
  if (tp->query_skill("wizardry") < 178) return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_manamissile(string str) {
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

  if((int)tp->query_mp() < 25) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Focus your power on whom?");

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

  //    attack = attack * 1.1;

  if(attack < 10) attack = 10 + random(5);

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^ORANGE%^You focus all of your %^YELLOW%^e%^WHITE%^n%^YELLOW%^e%^WHITE%^r%^YELLOW%^g%^WHITE%^y%^RESET%^%^ORANGE%^ "+
   "into a small %^MAGENTA%^b%^CYAN%^a%^MAGENTA%^l%^CYAN%^l%^RESET%^%^ORANGE%^ "+
   "at your waist, shape it into a %^BOLD%^%^BLACK%^spike%^RESET%^%^ORANGE%^, and hurl it at " 
   +ob->query_cap_name()+ "!");

  message("room","%^ORANGE%^" +tp->query_cap_name()+ 
   " creates a %^MAGENTA%^b%^CYAN%^a%^MAGENTA%^l%^CYAN%^l of %^YELLOW%^e%^WHITE%^n%^YELLOW%^e%^WHITE%^r%^YELLOW%^g%^WHITE%^y%^RESET%^%^ORANGE%^ around " 
   +tp->query_possessive()+   
   " waist, shapes it into a %^BOLD%^%^BLACK%^spike%^RESET%^%^ORANGE%^, and hurls it at " 
   +ob->query_cap_name()+ "!"
   , environment(tp), ({tp,ob}));            

  message("ob", "%^ORANGE%^" +tp->query_cap_name()+ " creates a %^MAGENTA%^b%^CYAN%^a%^MAGENTA%^l%^CYAN%^l of %^YELLOW%^e%^WHITE%^n%^YELLOW%^e%^WHITE%^r%^YELLOW%^g%^WHITE%^y%^RESET%^%^ORANGE%^ around " 
   +tp->query_possessive()+ 
   " waist, shapes it into a %^BOLD%^%^BLACK%^spike%^RESET%^%^ORANGE%^, and hurls it at you!",ob);

  ob->do_damage("target", attack, DAMAGE_MAGIC, 0, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("wizardry", attack/20 + 2);    

  tp->add_mp(-BALANCE3_D->get_cost(attack, 3, "mp"));

  tp->set_magic_round();

  return 1;
}
