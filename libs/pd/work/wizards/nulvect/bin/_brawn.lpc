
#include <std.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 RES+"%^ORANGE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define BRAWN_PROP "brawn_abil_wait"
#define BRAWN_WAIT 20

#define RAGE_OB_ID "rage_ob_id"

inherit DAEMON;

object *who=({});

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "berserker" &&
      tp->query_skill("defense") >= 21*5 &&
      tp->query_skill("rage") >= 21*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <brawn>\n\n"
    "A berserker can call upon his enormous strength and rage "
    "to increase his ability to take hits.",
    this_player() );
}

int can_cast(object tp) {
  int *tmp;

  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're a bit too dead to be flexing your muscles.");

  if (sizeof(tmp=tp->query(BRAWN_PROP)) && tmp[0]+BRAWN_WAIT > time())
    FAIL("Your body isn't ready again so soon.");
  
  return 1;
}

int cmd_brawn(string str) {
  object tp=this_player();
  object env=environment(tp);
  int rounds, def, cost;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  def = tp->query_stats("constitution")*3;
  def += tp->query_stats("strength")*1.5;

  rounds = tp->query_skill("rage")/26;
  if (rounds < 5) rounds=5;
  
  cost = rounds*3.2;

  if (tp->query_sp() < cost)
    FAIL("You're too tired.");

  tp->add_sp(-cost);
  tp->set_disable();

  tp->set(BRAWN_PROP, ({ time()+rounds*2, def }) );
  tp->add_skill_bonus("defense", def);
  who += ({ tp });
  set_heart_beat(1);

  message("info", "You fl"+COL+"ex"+RES+" your "
                  "m"+COL2+"us"+COL+"cl"+RES+"es and prepare "
                  "to take some "+COL2+"bl"+COL+"o"+RES+"ws!", tp);
  message("info", tp->query_cap_name()+" fl"+COL+"ex"+RES+"es "+
                  tp->query_possessive()+" m"+COL2+"us"+COL+"cl"+RES+"es "
                  "and looks more imposing!", env, tp);

  tp->add_skill_points("rage", 30);
  
  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    int *tmp;
    if (!p) {
      who -= ({ p });
      continue;
    }
    tmp = p->query(BRAWN_PROP);
    
    if (time() >= tmp[0] || (present(RAGE_OB_ID, p) && random(100) < 10)) {
      p->add_skill_bonus("defense", -tmp[1]);
      who -= ({ p });
      message("info", "You let your muscles relax again.", p);
      message("info", p->query_cap_name()+" seems to relax.", environment(p), p);
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

