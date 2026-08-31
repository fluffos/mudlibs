
#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_bloodlust(class Effect);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("faith") >= 20*4)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <bloodlust>\n\n"
    "Antipaladins can pray for the bloodlust of the demons. "
    "This will make them more ferocious in combat.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force keeps your prayer from leaving your lips.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("The demons laugh at you.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if (tp->query_effect("bloodlust"))
    FAIL("You have already been granted bloodlust!");

  if (tp->query_hp() < tp->query_max_hp() ||
      tp->query_mp() < tp->query_max_mp())
        FAIL("You must be at full strength to pray for bloodlust!");

  return 1;
}

int cmd_bloodlust(string str) {
  object tp = this_player();
  object env = environment(tp);
  int time, att, def, strength;
  class Effect bl;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  time = 120;
  time += (tp->query_stats("wisdom")-25)*6;
  time += (tp->query_skill("faith")-50)/2;
  time += random(20) - random(20);

  att = tp->query_skill("attack")/5;
  def = -1*(tp->query_skill("attack")/5);
  
  strength = 5;
  strength += (tp->query_skill("ferocity")-120)/8;
  if (strength > 15)
    strength = 15 + (strength-15)/3;
  strength += random(6);

  bl = new(class Effect);
  bl->name = "bloodlust";
  bl->castername = tp->query_name();
  bl->caster = tp;
  bl->target = tp;
  bl->desc = "You are filled with bloodlust.";
  bl->endtime = time() + time;
  bl->endfunc = (: end_bloodlust :);
  bl->endmessages = ({
    COL+"The demonic "+COL2+"bloodlust"+COL+" leaves you."+RES,
    COL+"The evil aura around "+tp->query_cap_name()+" disappears."+RES,
  });
  bl->misc = ({ att, def, strength });

  tp->add_skill_bonus("attack", att);
  tp->add_skill_bonus("defense", def);
  tp->add_stat_bonus("strength", strength);
  tp->add_effect(bl);

  message("magic", COL+"You pray to the "+COL2+"demons"+
                   COL+" and suddenly you are filled with "+
                   COL2+"bloodlust"+COL+"!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" says a prayer and an evil aura "
                   "surrounds "+tp->query_objective()+"."+RES, env, tp);

  tp->add_mp(-(tp->query_max_mp()/2));
  tp->set_magic_round(1);
  tp->add_skill_points("faith", 10+strength);
  tp->add_alignment(-7);

  return 1;
}

void end_bloodlust(class Effect bl) {
  object who = bl->target;
  int *info = bl->misc;
  int att = info[0];
  int def = info[1];
  int strength = info[2];
  
  who->add_skill_bonus("attack", -att);
  who->add_skill_bonus("defense", -def);
  who->add_stat_bonus("strength", -strength);
}

