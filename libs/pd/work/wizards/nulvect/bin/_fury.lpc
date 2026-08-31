
#include <std.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^RED%^"
#define COL2 RES+"%^ORANGE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define FURY_PROP "fury_abil_info"
#define FURY_TIME 50
#define FURY_WAIT 130

inherit DAEMON;

object *who = ({});

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "berserker" &&
      tp->query_skill("rage") >= 33*6 &&
      tp->query_skill("ferocity") >= 33*5)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <fury>\n\n"
    "When significantly wounded, a berserker can let his adrenaline "
    "pour out, making him stronger and giving a temporary boost to "
    "his health, allowing him to finish off his opponent. "
    "Once it wears off, though, he could die from lack of blood if "
    "the adrenaline was all that was keeping him alive.",
    this_player() );
}

int can_cast(object tp) {

  mixed arr;

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("It's too late, you're already dead.");

  if (sizeof(arr=tp->query(FURY_PROP)) && arr[0]+FURY_WAIT > time())
    FAIL("You can't throw yourself into a fury again so soon.");

  if (percent(tp->query_hp(),tp->query_max_hp()) > 60)
    FAIL("You haven't endured enough pain yet.");

  if (!sizeof(tp->query_attackers()))
    FAIL("You are not fighting anybody!");
  
  return 1;
}

int cmd_fury(string str) {
  object tp=this_player();
  object env=environment(tp);
  int rage;
  int strength, hp;

  if (!abil()) return 0;

  tp->clean_up_attackers();

  if (!can_cast(tp)) return 0;

  rage = tp->query_skill("rage")-33*6;
  
  strength = tp->query_base_stats("strength")/5;
  strength += rage/7;
  if (strength > 20)
    strength = 20+(strength-20)/2;

  hp = tp->query_base_stats("constitution")*4.8;
  hp += rage/2;
  if (hp > 500)
    hp = 500+(hp-500)/2;

  tp->add_stat_bonus("strength", strength);
  tp->set_max_hp(tp->query_max_hp()+hp);
  tp->add_hp(hp);
  tp->set(FURY_PROP, ({ time()+FURY_TIME, strength, hp }) );
  who += ({ tp });
  set_heart_beat(3);

  switch (random(3)) {
    case 0:
      message("info", "Your "+
                      COL+"b"+COL2+"l"+COL+"oo"+COL2+"d"+RES+
                      " p"+COL2+"ou"+COL+"nd"+RES+"s in your "+
                      COL2+"e"+COL+"ar"+COL2+"s"+RES+"!", tp);
    break;
    case 1:
      message("info", "Your body "+
                      COL+"s"+COL2+"ur"+COL+"g"+COL2+"e"+COL+"s"+RES+
                      " with new"+COL2+"fo"+COL+"un"+RES+"d "
                      "str"+COL+"en"+COL2+"gth"+RES+"!", tp);
    break;
    case 2:
      message("info", "Adrenaline "
                      "co"+COL+"ur"+RES+"ses "+
                      COL2+"thr"+RES+"ou"+COL+"gh"+RES+" you!", tp);
    break;
  }
  
  message("info", tp->query_cap_name()+" seems to "+
                  COL2+"g"+COL+"ai"+COL2+"n "
                  "st"+COL+"re"+COL2+"ng"+COL+"th"+RES+
                  " suddenly!", env, tp);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    mixed arr;
    if (!p || sizeof(arr = p->query(FURY_PROP)) < 3)
      who -= ({ p });
    else if (arr[0] < time()) {
      p->add_stat_bonus("strength", -arr[1]);
      p->add_hp(-arr[2]);
      p->fix_vital_bonus();
      p->set_disable();
      p->set(FURY_PROP, 0);
      who -= ({ p });
      message("info", "Your adrenaline fury wears off.", p);
      message("info", p->query_cap_name()+"'s fury wears off.", environment(p), p);
      // do this so the user dies if hp < 0 now
      p->heart_beat();
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}

