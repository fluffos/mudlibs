
#include <std.h>
#include <rest.h>
#include <daemons.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"
#define TORPOR_PROP "torpor_spell_data"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int torpor_heal(object tp);
void torpor_severed(object tp);

object *who = ({});
// the keys are necromancy skill requirements,
// first array element is a functional to test whether to do this one or not,
// second element is a functional to run or a string function name to call
mapping healings = ([
  30 : ({
    (: $1->query_stupor() :), (: $1->set_stupor(0) :)
  }),
  70 : ({
    (: $1->query_blind() :), (: $1->set_blind(0) :)
  }),
  110 : ({
    (: sizeof($1->query_crippled()) :),
    (: $1->remove_crippled($1->query_crippled()[random(sizeof($1->query_crippled()))] ) :)
  }),
  150 : ({
    (: sizeof($1->query_severed_limbs()) :), "torpor_severed"
  }),
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_class() == "vampire")
    return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <torpor>\n\n"
    "This is the vampiric ability to sink into a deep sleep "
    "to regenerate. Vampires must awaken naturally from this state. "
    "No blood is consumed while in torpor, but it does not protect from the sun.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  return 1;
}

int cmd_torpor(string str) {

  object tp = this_player();
  object env = environment(tp);
  int lvl, time;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  lvl = tp->query_level();
  time = random(70 - (lvl > 50 ? 50 : lvl));
  time += 20;

  message("magic", "You close your eyes and fall into "+COL+"torpor"+RES+".", tp);
  message("magic", tp->query_cap_name()+" closes "+tp->query_possessive()+
                   " eyes and sinks to the ground in a deep sleep.", env, tp);

  tp->set_rest_type(SLEEP);
  tp->set(TORPOR_PROP, ({ 1, time/2, tp->query_hp() }) );
  who += ({ tp });
  set_heart_beat(1);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    if (p) {
      if (!sizeof(p->query(TORPOR_PROP)) || sizeof(p->query_attackers()) || !torpor_heal(p)) {
        p->set_rest_type(0);
        p->set(TORPOR_PROP, ({ }) );
        who -= ({ p });
        message("magic", COL+"You awaken, feeling restored."+RES, p);
        message("magic", p->query_cap_name()+" awakens and opens "+
                         p->query_possessive()+" eyes.", environment(p), p);
      }
    }
    if (!p)
      who -= ({ p });
  }
  if (!sizeof(who)) set_heart_beat(0);
}

int torpor_heal(object tp) {
  int *data;
  int beat, max, necro, hp;

  if (!tp) return 0;

  data = tp->query(TORPOR_PROP);
  beat = data[0];
  max = data[1];
  hp = data[2];

  necro = tp->query_skill("necromancy");
  
  tp->add_sp(8+necro/13);
  tp->add_mp(7+necro/11);
  if (tp->query_hp() < hp && (query_night() || environment(tp)->query_property("indoors")) )
    tp->set_hp(hp);

  foreach (int req, mixed *arr in healings)
    if (random(max) < 1+(necro/90) && necro >= req && (*arr[0])(tp)) {
      if (stringp(arr[1]))
        call_other(this_object(), arr[1], tp);
      else
        (*arr[1])(tp);
    }

  if (beat >= max) return 0;

  tp->set(TORPOR_PROP, ({ ++beat, max, hp }) );

  return 1;
}

void torpor_severed(object tp) {
  string limb = tp->query_severed_limbs()[random(sizeof(tp->query_severed_limbs()))];
  mapping info = RACE_D->query_limb_info(limb, tp->query_race());
  string *wield = RACE_D->query_wielding_limbs(tp->query_race());
  string alimb = info["attach"];

  if (alimb != "0" && member_array(alimb, tp->query_limbs()) == -1) {
    mapping attach = RACE_D->query_limb_info(alimb, tp->query_race());
    tp->add_limb(alimb, attach["ref"], tp->query_max_hp() / attach["max"], 0, 0);
    if (member_array(alimb, wield) != -1)
      tp->add_wielding_limb(alimb);
  }

  tp->add_limb(limb, info["ref"], tp->query_max_hp() / info["max"], 0, 0);
  if (member_array(limb, wield) != -1)
    tp->add_wielding_limb(limb);

}

