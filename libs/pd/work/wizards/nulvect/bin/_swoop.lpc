
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^ORANGE%^"
#define SWOOP "%^BOLD%^%^WHITE%^s%^CYAN%^w%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^p%^RESET%^"
#define SWOOPS "%^BOLD%^%^WHITE%^s%^CYAN%^w%^RESET%^%^CYAN%^o%^RESET%^o%^BOLD%^%^BLUE%^p%^RESET%^%^BLUE%^s%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp &&
      (tp->query_class() == "dragon" && tp->query_level() >= 12) ||
      (tp->query_class() == "vampire" &&
       tp->query_skill("attack") >= to_int(20*5.5) &&
       tp->query_skill("flying") >= 20*4) )
          return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <swoop [who]>\n\n"
    "This is the ability to fly around your prey until you see an opening, "
    "then swoop down and claw at him, causing extreme damage.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You swoop right through your foe.");

  if (!tgt)
    FAIL("Swoop at whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("That's impossible.");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_swoop(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string *skills;
  int dmg, cost, rank;
  int miss = 0;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  skills = ({ "attack", "flying", "flying" });

  if (tp->query_class() == "vampire")
    skills += ({ "ferocity" });
  else
    skills += ({ "claw", "claw" });

  rank = 2+random(2);

  dmg = BALANCE3_D->get_damage(tp, tgt, rank, skills,
    ({ "dexterity" }), ({ "strength" }) );

  dmg *= 2.5;

  cost = dmg / 9.2;

  message("combat", "You circle your foe, preparing "
                    "to attack "+tgt->query_objective()+"!", tp);
  message("combat", tp->query_cap_name()+" circles in the air.", env, tp);

  if (tp->query_stats("dexterity")*3 + tp->query_skill("flying")*3/2 <
      tgt->query_stats("dexterity")*3 + tgt->query_skill("defense")*2/3 + tgt->query_skill("agility")/3)
        miss = 1;

  tp->set_magic_round(2);
  tp->add_sp(-(cost/3));
  tp->add_skill_bonus("defense", tp->query_base_skill("flying"), 2);

  call_out("finish_swoop", 2, ({ tp, tgt, dmg, cost, miss, rank }) );

  return 1;
}

void finish_swoop(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  int dmg = args[2];
  int cost = args[3];
  int miss = args[4];
  int rank = args[5];
  object env;
  string verb;

  if (!tp || !(env = environment(tp))) return;

  if (!tgt || environment(tgt) != env) {
    message("combat", "Your prey has eluded you!", tp);
    return;
  }

  if (!tp->kill_ob(tgt)) {
    message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
    return;
  }

  if (miss) {
    cost = cost/2;
    message("combat", "You swoop down, clawing at "+tgt->query_cap_name()+
                      ", but "+tgt->query_subjective()+" avoids your claws!", tp);
    message("combat", tp->query_cap_name()+" swoops down at you, but you avoid "+
                      tp->query_possessive()+" claws!", tgt);
    message("combat", tp->query_cap_name()+" swoops down at "+tgt->query_cap_name()+
                      " but misses the attack.", env, ({ tp, tgt }) );
  }
  else {
    switch (rank) {
      case 2: verb = "rip"; break;
      default: verb = "tear"; break;
    }
    message("combat", "You "+SWOOP+" down and "+COL+verb+RES+
                      " into "+tgt->query_cap_name()+" with your claws!", tp);
    message("combat", tp->query_cap_name()+" "+SWOOPS+" down and "+COL+verb+"s"+RES+
                      " into you with "+tp->query_possessive()+" claws!", tgt);
    message("combat", tp->query_cap_name()+" "+SWOOPS+" down and "+COL+verb+"s"+RES+
                      " into "+tgt->query_cap_name()+" with "+
                      tp->query_possessive()+" claws!", env, ({ tp, tgt }) );
    tgt->do_damage(tgt->return_target_limb(), dmg);
  }

  tp->add_sp(-(cost*2/3));
  tp->add_skill_points("flying", dmg/20);

}
