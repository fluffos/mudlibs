/// This is the first incarnation of a basic spell under the new system.

#include <magic.h>
#include <battle.h>

string query_name() { return "wind strike"; }

int query_cost() { return 30; }

int query_violent() { return 1; }

string query_type() { return "wind"; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
string query_step_msg(mapping param) {
  if( param["step"] == 1)
    return "~Name ~verbgrasp at the air above ~refl.";
  else
    return 0;
}
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.wind";
  	return ({ "magic.technique.evoking",
			  "magic.mana.wind" })[step];
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  mapping wc;
  int dc, check;
  object caster = param["caster"], target = param["target"];

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "piercing" : 10 + caster->skill_check("magic.mana.wind",dc,dc+25,dc+50) ]);
  caster->msg_local("~[030~Name ~verbhurl the air at ~targ.~CDEF");
  target->take_damage(wc);
  return 1;
}
