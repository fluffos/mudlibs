#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^RED%^"
#define TYPE "knife"
#define WCMOD 11
#define SKILLS ({ TYPE, TYPE, "attack" })
#define SKMORE ({ "ferocity", "discipline", "murder", "entertainment" })
#define DWMOD 3
#define STATS ({ "strength", "dexterity", "dexterity" })
#define EXTRA ({ "strength", "dexterity" })
#define SPMOD 13.8
#define VERBLOW ([ \
  "my" : "scrape", \
  "your" : "scrapes", \
  "their" : "scrapes", \
])
#define VERBHIGH ([ \
  "my" : "stab", \
  "your" : "stabs", \
  "their" : "stabs", \
])

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

void extra_hit(object tp, object tgt, int rank, 
               int dmg, object w, string limb);
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
    "Syntax: <stab [whom]>\n\n"
    "A basic attack with a knife. Anyone with sufficient skill can learn this, "
    "The quality of the knife is important.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("Stab whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tp == tgt)
    FAIL("That would hurt.");

  if (tp->query_rest_type())
    FAIL("You must stand up first.");

  if (tp->query_riding())
    FAIL("You cannot stab effectively while riding.");

  if (!sizeof(weps))
    FAIL("You need to use "+a_or_an(TYPE)+" "+TYPE+" for that.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_mystab(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  string wep, limb;
  string *skills;
  int cost, dmg, rank, wc, tmp;
  float tmpf;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  if (tp->query_skill("attack") >= 40) {
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

  tmp = rank*230;
  if (dmg > tmp)
    dmg = tmp+tp->query_level();

  tmpf = dmg/45.0;
  if (tmpf < 1.5) tmpf = 1.5;
  cost = SPMOD*log(tmpf);

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

  limb = tgt->return_target_limb();

  if (dmg < 15)
    do_messages("miss", tp, tgt, rank, weps[0], limb);
  else {
    do_messages("hit", tp, tgt, rank, weps[0], limb);
    tgt->do_damage(limb, dmg);
    extra_hit(tp, tgt, rank, dmg, weps[0], limb);
  }
  
  return 1;
}

void extra_hit(object tp, object tgt, int rank, int dmg, object w, string limb) {
  int bodydam, tmp;
  string wep = w->query_name();
  
  if (userp(tgt))
    tmp = 5;
  else
    tmp = tgt->query_level()*5;

  bodydam = dmg/tmp;

  tgt->heal_limb(limb, -bodydam);

  if (rank == 3 && tp->query_alignment() < -1*random(2500)) {
    message("combat", "You twist the "+wep+" hard!", tp);
    message("combat", tp->query_cap_name()+" twists the "+wep+" hard!",
      environment(tp), tp);
    tgt->do_damage(limb, dmg/9);
  }
    
}

void do_messages(string what, object tp, object tgt, int rank, object w, string limb) {
  mapping verb;
  string mymsg, yourmsg, theirmsg;
  string wep = w->query_name();

  if (rank == 1) verb = VERBLOW;
  else verb = VERBHIGH;
  
  switch (what) {

  case "miss":
    mymsg = "You lunge at "+tgt->query_cap_name()+
            " with your "+wep+", but miss.";
    yourmsg = tp->query_cap_name()+" lunges at you with "+
              tp->query_possessive()+" "+wep+", but misses.";
    theirmsg = tp->query_cap_name()+" lunges at "+
               tgt->query_cap_name()+" with "+
               tp->query_possessive()+" "+wep+", but misses.";
  break;

  case "hit":
    mymsg = "You lunge at "+tgt->query_cap_name()+" and "+
            COL+verb["my"]+RES+" "+tgt->query_possessive()+
            " "+limb+"!";
    yourmsg = tp->query_cap_name()+" lunges at you and "+
              COL+verb["your"]+RES+" your "+limb+"!";
    theirmsg = tp->query_cap_name()+" lunges at "+tgt->query_cap_name()+
               " and "+COL+verb["their"]+RES+" "+tgt->query_possessive()+
               " "+limb+"!";
  break;

  }

  message("combat", mymsg, tp);
  message("combat", yourmsg, tgt);
  message("combat", theirmsg, environment(tp), ({ tp, tgt }) );
  
}
