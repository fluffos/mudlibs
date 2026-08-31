#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

string type() { return "attack"; }

int cmd_implode(string str) {
  object tp=this_player();
  object ob;
  int damage;
  
  if (!spell()) {
    return 0;
  }
  if (tp->query_disable()) return 1;
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack")) {
    message("info","You cannot cast that here.",tp);
    return 1; 
  }
  if (!str) ob=tp->query_current_attacker();
  if (!ob && !ob=present(str,environment(tp))) {
    message("info","You don't see that here.",tp);
    return 1;
  }
  if (!living(ob)) {
    message("info","That is not alive.",tp);
    return 1;
  }
  if(tp->query_ghost())
    return notify_fail("Your voice is hollow.\n");
  if (!tp->kill_ob(ob)) {
    message("info","That cannot be attacked by you yet.",tp);
    return 1;
  }
  if (tp == ob) {
    message("info","Boom, you're dead.",tp);
    return 1;
  }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }

  damage=BALANCE_D->get_damage( tp, ob, 4, ({ "magic attack", "wizardry" }),
                                   ({ "wisdom" }), ({ "wisdom", "intelligence" }) );

  if (tp->query_mp() < 80) {
    message("info","Too low on magic power.", tp);
    return 1;
  }
  tp->add_mp(-damage/6);

  message("info","%^BOLD%^A huge sphere of %^YELLOW%^pure magic%^RESET%^%^BOLD%^ "
    "constricts around you!%^RESET%^", ob);
  message("info","%^BOLD%^A huge sphere of %^YELLOW%^pure magic%^RESET%^%^BOLD%^ "
    "constricts tightly around "+ob->query_cap_name()+"!%^RESET%^",environment(ob),ob);

  tp->set_magic_round(1);
  tp->set_disable();
  tp->set_casting(damage);
  tp->add_skill_points("magic attack",damage/25);
  return 1;
}

void help() {
    write("Syntax: <implode [(living)]>\n"
        "This spells creates a sphere of concentrated magical energy "
        "around a single opponent, causing them great harm.\n");
}

int spell() {
  object tp=this_player();
if(tp->query_subclass() == "wizard") return 0;
  if (tp->query_subclass() == "wizard" &&
      tp->query_level() >= 50 &&
      tp->query_skill("wizardry") >= 290) return 1;
  return 0;
}
