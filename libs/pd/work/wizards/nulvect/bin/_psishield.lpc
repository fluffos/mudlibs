#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^MAGENTA%^"
#define COL2 RES+"%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_psishield(class Effect);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "sorceror" &&
      tp->query_skill("psionics") >= 20*6 &&
      tp->query_skill("magic defense") >= 20*4)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <psishield [who]>\n\n"
    "The caster creates a shield of psionic energy to absorb some "
    "damage in combat. It is less effective when used on others.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot harness your psionic powers in this state.");

  if (!tgt)
    FAIL("Shield who?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt->query_effect("psishield"))
    FAIL( (tgt == tp ? "You are "
          : capitalize(tgt->query_subjective())+" is ") +
          "already surrounded by a psionic shield.");

  return 1;
}

int cmd_psishield(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, strength, cost;

  if (!spell()) return 0;
  
  if (str) {
    if (str == "me") tgt = tp;
    else tgt = present(str, env);
  }

  if (!can_cast(tp, tgt)) return 0;

  time = tp->query_stats("wisdom")*2;
  time += tp->query_skill("psionics")/10;
  time += random(tp->query_level());

  strength = 2 + (tp->query_skill("magic defense") - 60) / 12;
  strength += random(2);
  if (tp == tgt)
    strength += 2;

  cost = time * 110 / 100;
  cost += strength * 15;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->add_mp(-cost);
  tp->set_magic_round(4);

  message("magic", COL+"You begin to shape your "+
                   COL2+"psionic"+COL+" energy."+RES, tp);

  call_out("start_psishield", 6, ({ tp, tgt, strength, time }) );

  return 1;
}

void start_psishield(mixed *args) {
  object tp = args[0];
  object tgt = args[1];
  int strength = args[2];
  int time = args[3];
  class Effect psi = new(class Effect);

  psi->name = "psishield";
  psi->castername = tp->query_name();
  psi->caster = tp;
  psi->target = tgt;
  psi->desc = "You are surrounded by a shield of psionic energy.";
  psi->endtime = time()+time;
  psi->endfunc = (: end_psishield :);
  psi->endmessages = ({
    COL2+"The psionic shield collapses around you."+RES,
    COL2+"The psionic shield collapses around "+
      tgt->query_cap_name()+"."+RES,
  });
  psi->misc = ({ strength });

  tgt->add_magic_protection( ({ 0, strength, 0 }) );
  tgt->add_effect(psi);

  message("magic", COL+"A psionic "+COL2+"shield"+
                   COL+" charges the air around you."+RES, tgt);

  message("magic", COL+"A psionic "+COL2+"shield"+
                   COL+" charges the air around "+
                   tgt->query_cap_name()+"."+RES, environment(tgt), tgt);
}

void end_psishield(class Effect psi) {
  object who = psi->target;
  int *info = psi->misc;
  int strength = info[0];

  who->add_magic_protection( ({ 0, -strength, 0 }) );
}

