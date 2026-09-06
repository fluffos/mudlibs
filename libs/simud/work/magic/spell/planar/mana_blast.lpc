#include <magic.h>
#include <battle.h>

string query_name() { return "mana blast"; }
int query_cost() { return 20; }
int query_violent() { return 1; }
string query_type() { return "spirit"; }
int query_level() { return 1; }

int query_readiness_requirement() { return 400; }
int query_num_steps() { return 2; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbgesture rapidly at ~targ.";
  else
    return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.technique.evoking",
              "magic.mana.spirit" }) [step];
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster))
    return 0;
  if ( !target->query_is_living() )
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  mapping wc;
  int dc, check;
  object caster = param["caster"], target = param["target"];

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "mana" : 11 + caster->skill_check("magic.mana.fire",dc,dc+25,dc+50) ]);
    caster->msg_local("~[030~Name ~verbgesture again, this time hurling a bolt of magic at ~targ.~CDEF");
  target->take_damage(wc);
  return 1;
}
