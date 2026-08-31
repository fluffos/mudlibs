//      Written by Nightshade

#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_chainlightning(string str) {
  object tp, ob, pois, env;
  object *all=({});
  int dam, dmg, i;
  string party, name;
  tp = this_player();
  if(!spell())
    return 0;
  env = environment(this_player());
  name = "0";
  if (ob && !living(ob))
    return notify_fail("You do not see that here.\n");
  if(tp->query_ghost()) {
    notify_fail("Your magic is with your corpse.\n");
    return 0;
  }
  if (environment(this_player())->query_property("no attack") ||
   environment(this_player())->query_property("no magic")) {
    write("Greater powers prevent your malice.");
    return 1;
  }
  if (tp->query_busy()) {
    notify_fail("You are too busy to do that!\n");
    return 0;
  }
  if (tp->query_mp() < 80) {
    write("You do not have the energy.");
    return 1;
  }
  tp->clean_up_attackers();
  all = all_inventory(environment(this_player()));
  i = sizeof(all);
  write("%^BOLD%^%^YELLOW%^A golden arc of lightning cracks between your wings.%^RESET%^");

  while (i--) {
    if (this_player()->query_party())
      party = this_player()->query_party();
    else party = "AdkIl898-FL00Jn-neInfe_ron";
    if (!all[i]) continue;
    if(all[i]->query_party() == party) continue;
    if (environment(tp) != environment(all[i])){
      write("%^RESET%^%^BOLD%^"+all[i]->query_cap_name()+" has evaded the lightning.");
      continue;
    } 
    if (!all[i])
      continue;
    if (!all[i]->is_living()) continue;
    dam = BALANCE3_D->get_damage( tp, all[i], 3, ({ "wizardry", "magic attack" }), ({ "intelligence","intelligence","wisdom" }),
     ({ "magic attack" }) );
    dam = dam * (80 + random(40)) / 100;
    if(dam < 1) {
      write("%^RESET%^%^BOLD%^Your lightning crackles and fizzles.%^RESET%^");
      say("%^RESET%^%^BOLD%^"+tp->query_cap_name()+"'s lightning crackles and fizzles.%^RESET%^");
      continue;
    }
    if (!all[i]->query_ghost() && all[i] != this_player() && !wizardp(all[i])) {
      if(!this_player()->kill_ob(all[i])) {
        write(all[i]->query_cap_name()+" can't be attacked by you yet.");
        continue;
      }
      if(name == "0") {
        write("%^RESET%^%^BOLD%^Lightning shoots forth into "+all[i]->query_cap_name()+", shocking them badly!%^RESET%^");
        say("%^RESET%^%^BOLD%^Lightning shoots from "+this_player()->query_cap_name()+" into "+all[i]->query_cap_name()+", shocking them badly!%^RESET%^", all[i]);
        message("info", "%^RESET%^%^BOLD%^Lightning shoots from "+this_player()->query_cap_name()+" into you, shocking you badly!%^RESET%^", all[i]);
      }
      else {
        write("%^RESET%^%^BOLD%^The lightning shoots from "+name+" into "+all[i]->query_cap_name()+", shocking them badly!%^RESET%^");
        say("%^RESET%^%^BOLD%^Lightning shoots from "+name+" into "+all[i]->query_cap_name()+", shocking them badly!%^RESET%^", all[i]);
        message("info", "%^RESET%^%^BOLD%^Lightning shoots from "+name+" into you, shocking you badly!%^RESET%^", all[i]);
      }
      name = all[i]->query_cap_name();
      all[i]->do_damage("random", dam, DAMAGE_MAGIC | DAMAGE_LIGHTNING, DAMAGE_NO_SEVER, this_player());
      this_player()->add_mp(-(BALANCE3_D->get_cost(dam, 3, "mp")*75/100));
      if(all[i]->query_hp() < 1) all[i]->heart_beat();
    }
  }
  tp->add_skill_points("wizardry", dam/20);
  tp->set_magic_round();
  return 1;
}

int spell() {
  object o;
  o = this_player();
  if (!o) return 0;
  if (o->query_subclass() != "black") return 0;
  if (o->query_skill("wizardry") < 90) return 0;
  if (o->query_level() < 20) return 0;
  return 1;
}

void help() {
  write("Syntax: <chainlightning>");
  write(@END
Black dragons are able to release a stream of
lightning that can bounce to different targets.
END);
}
