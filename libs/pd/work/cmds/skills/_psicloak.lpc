#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 RES+"%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_psicloak(class Effect);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_level() >= 5)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <psicloak>\n\n"
    "A cloak of psionic energy surrounds the caster, "
    "protecting him from some damage.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your psionic powers in this state.");

  if (tp->query_effect("psicloak"))
    FAIL("You are already protected by that.");

  return 1;
}

int cmd_psicloak(string str) {
  object tp = this_player();
  object env = environment(tp);
  int time, strength, cost, md;

  if (!spell()) return 0;
  
  if (!can_cast(tp)) return 0;

  time = tp->query_stats("wisdom")*3;
  time += random(tp->query_level());

  strength = 1 + tp->query_skill("magic defense")/35;
  strength += random(2);
  if (strength > 5)
    strength = 5 + (strength-5)/3;

  md = 5*((tp->query_level()-10)/5);

  cost = time * 70 / 100;
  cost += strength * 5;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->add_mp(-cost);
  tp->set_magic_round(2);

  message("magic", COL+"You begin to shape your "+
                   COL2+"psionic"+COL+" energy."+RES, tp);

  call_out("start_psicloak", 2, ({ tp, strength, time, md }) );

  return 1;
}

void start_psicloak(mixed *args) {
  object tp = args[0];
  int strength = args[1];
  int time = args[2];
  int md = args[3];
  class Effect psi = new(class Effect);

  psi->name = "psicloak";
  psi->castername = tp->query_name();
  psi->caster = tp;
  psi->target = tp;
  psi->desc = "You are protected by a psionic cloak.";
  psi->endtime = time()+time;
  psi->endfunc = (: end_psicloak :);
  psi->endmessages = ({
    COL2+"Your cloak of energy fades away."+RES,
  });
  psi->misc = ({ strength, md });

  tp->add_magic_protection( ({ 0, strength, 0 }) );
  tp->add_skill_bonus("magic defense", md);
  tp->add_effect(psi);

  message("magic", COL+"A "+COL2+"cloak"+
                   COL+" of psionic energy surrounds you."+RES, tp);

  message("magic", COL+"A "+COL2+"cloak"+
                   COL+" of psionic energy surrounds "+
                   tp->query_cap_name()+"."+RES, environment(tp), tp);
}

void end_psicloak(class Effect psi) {
  object who = psi->target;
  int *info = psi->misc;
  int strength = info[0];
  int md = info[1];

  who->add_magic_protection( ({ 0, -strength, 0 }) );
  who->add_skill_bonus("magic defense", -md);
}

