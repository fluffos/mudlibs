#include <magic.h>
#include <battle.h>

string query_name() { return "invigorate"; }

int query_cost() { return 15; }

string query_type() { return "fire"; }

int query_num_steps() { return 7; }
// need step messages
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.fire";
  	return ({ "magic.mana.earth",
			  "magic.mana.fire",
			  "magic.mana.fire",
			  "magic.technique.charming",
			  "magic.technique.charming",
			  "magic.technique.dancing",
			  "magic.mana.fire" })[step];
}

int query_readiness_requirement() { return 1800; }

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

  caster->practice_skill_conditional("magic.mana.earth",25,3);
  set_target(target);
  caster->msg_local("~[030~Subt ~vertemit a single pulse of dim orange light.~CDEF");

  if (obj = present_clone("/magic/obj/invigorate_object", target) ) {
    speed = 1 * caster->skill_check("magic.mana.fire", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.charming", 60, 80) * 10;
    obj->add_duration(duration);
    obj->add_speed(speed);
  } else {
    obj = clone_object("/magic/obj/invigorate_object");
    speed = 1 + 1 * caster->skill_check("magic.mana.fire", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.charming", 60, 80) * 10;
    obj->set_victim(target);
    obj->set_duration(duration);
    obj->set_speed(speed);
    debug("speed = "+speed+", duration = "+duration,"combat");
  }

  return 1;
}
