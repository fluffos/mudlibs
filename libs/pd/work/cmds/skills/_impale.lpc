#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
#include <effect_cl.h>

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define TYPE "projectile"
#define WCMOD 6
#define SKILLS ({ TYPE, TYPE, "attack" })
#define SKMORE ({ "discipline", "valor" })
#define DWMOD 4
#define STATS ({ "strength", "dexterity" })
#define EXTRA ({ "strength", "dexterity" })
#define SPMOD 15.5
#define VERBLOW ([ \
  "my" : "pierce", \
  "your" : "pierces", \
  "their" : "pierces", \
])
#define VERBHIGH ([ \
  "my" : "impale", \
  "your" : "impales", \
  "their" : "impales", \
])

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void extra_hit(object tp, object tgt, int rank, 
               int dmg, object w, string limb, int focus);
void do_messages(string what, object tp, object tgt,
                 int rank, object wep, string limb);

int abil() {
  object tp = this_player();
  if (tp && tp->query_skill(TYPE) >= 20)
    return 1;
  return 0;
}

string type() { return "weapon"; }

void help() {
  message("help",
    "Syntax: <impale [whom]>\n\n"
    "A simple spear move, this attack aims primarily at your foe's torso. "
    "Anyone with sufficient skill can learn this. ",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Impale whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would hurt.");

  if (tp->query_rest_type())
    FAIL("You must stand up first.");

  if (!sizeof(weps))
    FAIL("You need to use "+a_or_an(TYPE)+" "+TYPE+" for that.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_impale(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  string wep, limb;
  string *skills;
  int cost, dmg, rank, wc, tmp;
  float tmpf;
  class Effect check;
  int focus;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  focus = ((check = tp->query_effect("focus")) && check->misc[0] == TYPE);

  if (tp->query_skill("attack") >= 40) {
    if (focus && tp->query_skill(TYPE) >= 240) rank = 4;
    if (tp->query_skill(TYPE) >= 160) rank = 3;
    else if (tp->query_skill(TYPE) >= 75) rank = 2;
    else rank = 1;
  }
  else rank = 1;

  // --- skills ---
  skills = SKILLS;

  if (sizeof(tp->query_wielded()) > 1) {
    for (int i = 0; i < DWMOD; i++)
      skills += ({ "double wielding" });
  }

  if (tp->query_riding())
    skills += ({ "riding" });

  tmp = 0;
  if (tp->query_subclass() == "kataan") tmp = 1;
  foreach (string sk in SKMORE)
    if (tp->skill_exists(sk)) {
      skills += ({ sk });
      tmp = 1;
    }
  // this makes this abil weaker by looking for a skill that doesn't exist
  if (!tmp)
    skills += ({ "" });
  // --- end skills ---


  dmg = BALANCE3_D->get_damage(tp, tgt, rank, skills, STATS, EXTRA );

  tmp = rank*310;
  if (dmg > tmp)
    dmg = tmp+tp->query_level();

  /*
  tmpf = dmg/45.0;
  if (tmpf < 1.5) tmpf = 1.5;
  cost = SPMOD*log(tmpf);
  */
  cost = BALANCE3_D->get_cost(dmg, rank, "sp");

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  weps = sort_array(weps,
    (: $1->query_wc() < $2->query_wc() ? $1 : $2 :)
  );

  wc = weps[0]->query_wc();

  switch (rank) {
  case 1:
    wc = 0;
  break;
  case 2:
    wc /= 2;
  break;
  }

  dmg += wc*WCMOD;

  if (random(100) < 60)
    limb = tgt->query_torso();
  else
    limb = tgt->return_target_limb();

  if (dmg < 15)
    do_messages("miss", tp, tgt, rank, weps[0], limb);
  else {
    do_messages("hit", tp, tgt, rank, weps[0], limb);
    tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
    extra_hit(tp, tgt, rank, dmg, weps[0], limb, focus);
  }
  
  return 1;
}

void extra_hit(object tp, object tgt, int rank, int dmg, object w, string limb, int focus) {
  string wep = remove_article(w->query_name());
  int extradmg = random(dmg/10) + focus*(dmg/10);

  if (focus || rank >= 3) {

    message("combat", "You push the "+wep+" in deeper before pulling it out.", tp);
    message("combat", tp->query_cap_name()+" pushes the "+wep+" in deeper "
                      "before pulling it out.", environment(tp), tp);
    tgt->do_damage(limb, extradmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, DAMAGE_NO_SEVER, tp);
  }
  
}

void do_messages(string what, object tp, object tgt, int rank, object w, string limb) {
  mapping verb;
  string mymsg, yourmsg, theirmsg;
  string wep = remove_article(w->query_name());

  if (rank == 1) verb = VERBLOW;
  else verb = VERBHIGH;
  
  switch (what) {

  case "miss":
    mymsg = "You miss your attempt to "+verb["my"]+" "+
            tgt->query_cap_name()+" with your "+wep+".";
    yourmsg = tp->query_cap_name()+" misses an attempt to "+
              verb["my"]+" you with "+tp->query_possessive()+
              " "+wep+".";
    theirmsg = tp->query_cap_name()+" misses an attempt to "+
               verb["my"]+" "+tgt->query_cap_name()+" with "+
               tp->query_possessive()+" "+wep+".";
  break;

  case "hit":
    mymsg = "You "+COL+verb["my"]+RES+
            " "+tgt->query_cap_name()+" with your "+wep+"!";
    yourmsg = tp->query_cap_name()+" "+COL+verb["your"]+RES+
              " you with "+tp->query_possessive()+" "+wep+"!";
    theirmsg = tp->query_cap_name()+" "+COL+verb["their"]+RES+
               " "+tgt->query_cap_name()+" with "+
               tp->query_possessive()+" "+wep+"!";
  break;

  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  message("combat", theirmsg, environment(tp), ({ tp, tgt }) );
  
}
