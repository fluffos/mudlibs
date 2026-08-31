
#include <std.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s)
#define COL "%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_guard(class Effect guard);

void help() {
  message("help",
    "Syntax: <guard [who]>\n\n"
    "This spell of protection creates a weak "
    "magical guard around the target.",
    this_player() );
}

int spell() {
   object tp = this_player();
   if (tp && tp->query_class() == "mage" && tp->query_level() >= 2)
     return 1;
   return 0;
}

string type() { return "defense"; }

int can_cast(object tp, object tgt) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your magic fails.");

  if (!tgt)
    FAIL("Guard who?");

  if (!tgt->is_living())
    FAIL("It is perfectly safe.");

  if (tgt->query_effect("guard"))
    FAIL((tgt == tp ? "You are" : capitalize(tgt->query_subjective())+" is")+
         " already protected by that spell.");

  return 1;
}

int cmd_guard(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int md, wis, amt, time, cost;
  class Effect guard;

  if (!spell()) return 0;

  if (str) {
    if (str == "me" || str == "myself")
      tgt = tp;
    else
      tgt = present(str, env);
  }

  if (!can_cast(tp, tgt)) return 0;

  cost = 20+random(30);
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  md = tp->query_skill("magic defense");
  wis = tp->query_stats("wisdom");

  time = 30 + wis/2 + random(md/10);
  amt = 2 + md/30 + wis/17 + random(3);
  if (amt > 7)
    amt = 7 + (amt - 7)/4;

  guard = new(class Effect);
  guard->name = "guard";
  guard->castername = tp->query_name();
  guard->caster = tp;
  guard->target = tgt;
  guard->desc = "A weak magical guard protects you from harm.";
  guard->endtime = time()+time;
  guard->endfunc = (: end_guard :);
  guard->endmessages = ({
    COL+"The magical guard around you fades away."+RES,
    COL+"The magical guard around "+tgt->query_cap_name()+" fades away."+RES,
  });
  guard->misc = ({ amt });

  tgt->add_magic_protection( ({ 0, amt, 0 }) );
  tgt->add_effect(guard);

  if (tp == tgt) {
    message("magic", COL+"You cast a magical guard around yourself."+RES, tp);
    message("magic", COL+tp->query_cap_name()+" casts a magical guard "
      "around "+tp->query_objective()+"self."+RES, env, tp);
  }
  else {
    message("magic", COL+"You cast a magical guard around "+
      tgt->query_cap_name()+"."+RES, tp);
    message("magic", COL+tp->query_cap_name()+" casts a magical guard "
      "around you."+RES, tgt);
    message("magic", COL+tp->query_cap_name()+" casts a magical guard "
      "around "+tgt->query_cap_name()+"."+RES, env, ({ tp, tgt }) );
    tp->add_alignment(2);
  }

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->add_skill_points("magic defense", 10+amt);

  return 1;
}

void end_guard(class Effect guard) {
  object who = guard->target;
  int *info = guard->misc;
  int amt = info[0];

  who->add_magic_protection( ({ 0, -amt, 0 }) );
}

