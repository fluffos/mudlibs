//      _pillar.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <manablast [(living)]>\n"
   "A powerful wizard can release their true "
   "energy potential and force thier power onto "
   "their target causing great harm.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_skill("wizardry") < 60*6) return 0;

  return 1;
}
string type() { return "attack"; }
int cmd_manablast(string str) {
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

  if((int)tp->query_mp() < 45) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Throw your power at whom?");

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
  attack = BALANCE3_D->get_damage( tp, ob, 4, ({ "magic attack", "wizardry", "wizardry" }),
   ({ "intelligence", "wisdom", "intelligence" }), ({"wizardry", "magic attack", "conjuring"}) );

  attack = attack * 1.2;

  if(attack < 10) attack = 10 + random(5);

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^ORANGE%^You %^RED%^flex%^ORANGE%^ all of your %^CYAN%^muscles%^ORANGE%^ and focus on "+ob->query_cap_name()+
   ", you release all of your %^BOLD%^%^CYAN%^e%^WHITE%^n%^CYAN%^e%^WHITE%^r%^CYAN%^g%^WHITE%^y%^RESET%^%^ORANGE%^ in every direction and send it flying at "
   +ob->query_cap_name()+ " %^BOLD%^%^RED%^p%^RESET%^%^RED%^e%^BOLD%^%^RED%^l%^RESET%^%^RED%^t%^BOLD%^%^RED%^i%^RESET%^%^RED%^n%^BOLD%^%^RED%^g%^RESET%^%^ORANGE%^ " +ob->query_objective()+ " from all directions!");

  message("room","%^ORANGE%^" +tp->query_cap_name()+ 
   " seems to %^RED%^focus%^ORANGE%^ on " +ob->query_cap_name()+ " when a %^BOLD%^%^CYAN%^c%^WHITE%^l%^CYAN%^o%^WHITE%^u%^CYAN%^d %^WHITE%^o%^CYAN%^f %^WHITE%^e%^CYAN%^n%^WHITE%^e%^CYAN%^r%^WHITE%^g%^CYAN%^y%^RESET%^%^ORANGE%^ comes flying out from "
   +tp->query_objective()+   
   " and rushes at " 
   +ob->query_cap_name()+ " %^BOLD%^%^RED%^violently%^RESET%^ %^RED%^c%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^RESET%^%^ORANGE%^ into " +ob->query_objective()+ "!"
   , environment(tp), ({tp,ob}));            

  message("room","%^ORANGE%^" +tp->query_cap_name()+ 
   " seems to %^RED%^focus%^ORANGE%^ on you when a %^BOLD%^%^CYAN%^c%^WHITE%^l%^CYAN%^o%^WHITE%^u%^CYAN%^d %^WHITE%^o%^CYAN%^f %^WHITE%^e%^CYAN%^n%^WHITE%^e%^CYAN%^r%^WHITE%^g%^CYAN%^y%^RESET%^%^ORANGE%^ comes flying out from "
   +tp->query_objective()+   
   " and rushes toward you " 
   + "%^BOLD%^%^RED%^violently%^RESET%^ %^RED%^c%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g%^RESET%^%^ORANGE%^ into you!"
   , ob);    

  ob->do_damage("target", attack, DAMAGE_MAGIC, 0, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("wizardry", attack/20 + 2);    

  tp->add_mp(-BALANCE3_D->get_cost(attack, 4, "mp"));

  tp->set_magic_round();

  return 1;
}

