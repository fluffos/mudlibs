#include <magic.h>
#include <battle.h>

string query_name() { return "slow"; }

int query_cost() { return 15; }

string query_type() { return "ice"; }

int query_violent() { return 1; }

int query_num_steps() { return 6; }

string query_step_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "~Name ~verbbegin to chant as ~poss icy gaze becomes fixed on ~targ.";
    case 1: return "~Name ~verbcontinue to glare and chant as the air around ~targ becomes colder.";
  }
   return 0;
}
string query_fail_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "~Name ~verbwas too unfocused to fix ~poss gaze on anything.";
    case 1: return "~Name ~verbbecome distracted.";
    case 2: return "~Name ~verbbecome distracted and the cold around ~targ dissipates.";
  }
   return 0;
}
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.ice";
  	return ({ "magic.technique.cursing",
			  "magic.mana.earth",
			  "magic.mana.water",
			  "magic.mana.ice",
			  "magic.technique.binding",
			  "magic.technique.cursing" })[step];
}
int query_readiness_requirement() { return 1500; }

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  int duration, speed;
  object obj;
  object caster = param["caster"], target = param["target"];

  caster->practice_skill_conditional("magic.mana.ice",25,3);
  set_target(target);
  caster->msg_local("~[030~Name ~verbfinish chanting and the air around ~targ thickens, slowing ~objt down.~CDEF");

  if (obj = present_clone("/magic/obj/haste_object", target) ) {
    obj->end();
  } else if (obj = present_clone("/magic/obj/slow_object", target) ) {
    speed = 25 + 25 * caster->skill_check("magic.mana.ice", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.cursing", 20, 40, 60) * 10;
    obj->add_duration(duration);
    if (speed > obj->query_speed())
      obj->set_speed(speed);
  } else {
    obj = clone_object("/magic/obj/slow_object");
    speed = 25 + 25 * caster->skill_check("magic.mana.ice", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.cursing", 20, 40, 60) * 10;
    obj->set_victim(target);
    obj->set_duration(duration);
    obj->set_speed(speed);
  }

  return 1;
}
