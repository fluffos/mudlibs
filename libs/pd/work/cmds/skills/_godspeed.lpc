#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define GODSPEED_PROP "godspeed_spell_time"

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "paladin" &&
      tp->query_skill("faith") >= 15*4)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <godspeed [whom]>\n\n"
    "This prayer can bestow great speed upon a living being.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force keeps your prayer from leaving your lips.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your prayer comes out as a howl.");

  if (!tgt)
    FAIL("Grant godspeed to whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (!alignment_ok(tp))
    FAIL("You pray, but nothing happens.");

  if (tgt->query(GODSPEED_PROP) > time())
    FAIL( (tp==tgt ? "You have" : capitalize(tgt->query_subjective())+" has" )+
          " already been granted godspeed.");

  if (tp->query_mp() < tp->query_max_mp()/2)
    FAIL("Your magic is too low.");

  return 1;
}

int cmd_godspeed(string str) {
  object tp = this_player();
  object tgt;
  object env = environment(tp);
  int bonus, time, cost;

  if (!spell()) return 0;

  if (str == "me") tgt = tp;
  else if (str) tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  bonus = 2+tp->query_skill("faith")/7;
  if (bonus > 15) bonus = 15+((bonus-15)/2);
  if (bonus > 30) bonus = 30+((bonus-30)/2);
  bonus += random(bonus/6);

  time = tp->query_skill("faith") + tp->query_stats("wisdom")*1.75;
  time += random(time/5);

  cost = time/2 + bonus;
  cost += random(30);
  if (cost > 150) cost = 150;
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  if (tgt->query_alignment() < 500) bonus *= 0.75;
  tgt->add_stat_bonus("dexterity", bonus);
  tgt->set(GODSPEED_PROP, time()+time);
  tgt->fix_vital_bonus();
  tp->add_mp(-cost);
  DELAY_D->add_delay(time, this_object(), "remove_godspeed", ({ tgt, bonus }) );

  message("magic", COL+"You pray."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" prays."+RES, env, tp);
  message("magic", COL+"A glow surrounds you and you feel more nimble."+RES, tgt);
  message("magic", COL+"A glow surrounds "+tgt->query_cap_name()+"."+RES, env, tgt);

  tp->add_skill_points("faith", 20);
  tp->set_magic_round(1);

  return 1;
}

void remove_godspeed(object tgt, int bonus) {
  if (!tgt) return;
  message("magic", COL+"The glow around you fades out."+RES, tgt);
  message("magic", COL+"The glow around "+tgt->query_cap_name()+" fades out."+RES, environment(tgt), tgt);
  tgt->add_stat_bonus("dexterity", -bonus);
  tgt->fix_vital_bonus();
}
