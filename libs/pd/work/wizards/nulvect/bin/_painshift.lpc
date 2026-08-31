
#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

#define PAINSHIFT_PROP "painshift_spell_time"


void end_painshift(class Effect);
void add_hp_hook(int);


int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("healing") >= 18*2 &&
      tp->query_skill("magic defense") >= 18*2)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <painshift>\n\n"
    "This spell draws power from every wound inflicted on the caster, "
    "causing every hit to increase his stamina. Unfortunately it also "
    "causes him to take slightly more damage.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You fail to cast the spell.");

  if (tp->query_effect("painshift"))
    FAIL("You have already cast that!");

  return 1;
}

int cmd_painshift(string str) {
  object tp = this_player();
  object env = environment(tp);
  int time, perc, cost;
  class Effect ps;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  time = 30 + tp->query_stats("wisdom");

  perc = 10;
  perc += (tp->query_skill("healing") - 18*2) / 7;
  if (perc > 40)
    perc = 40;

  cost = time + perc;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  ps = new(class Effect);
  ps->name = "painshift";
  ps->caster = tp;
  ps->castername = tp->query_name();
  ps->target = tp;
  ps->desc = "Every wound you suffer bolsters your stamina.";
  ps->endtime = time() + time;
  ps->endfunc = (: end_painshift :);
  ps->endmessages = ({
    COL+"The stinging of your blood finally stops."+RES,
  });
  ps->misc = ({ perc, (: add_hp_hook :) });

  tp->add_effect(ps);
  tp->add_hook("add_hp", ps->misc[1] );

  message("magic", COL+"Your "+COL2+"blood"+COL+" begins to throb and sting."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" whispers a spell."+RES, env, tp);

  tp->add_mp(-(cost+random(cost/5)));
  tp->set_magic_round(1);
  tp->add_skill_points("healing", 5+random(time/2));

  return 1;
}

void end_painshift(class Effect ps) {
  object tp = ps->caster;

  tp->remove_hook("add_hp", ps->misc[1]);
}

int add_hp_hook(int x) {
  object tp = previous_object();
  class Effect ps;

  if (!tp || !tp->is_living()) return x;
  
  ps = tp->query_effect("painshift");

  if (x < 0 && ps) {
    tp->add_sp( -x * ps->misc[0] / 100 );
    x = x * 110/100;
  }

  return x;
}

