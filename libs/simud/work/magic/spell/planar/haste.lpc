#include <magic.h>
#include <battle.h>

string query_name() { return "haste"; }

int query_cost() { return 15; }

string query_type() { return "earth"; }

int query_num_steps() { return 8; }
// need step messages

int query_readiness_requirement() { return 2000; }
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.earth";
  	return ({ "magic.mana.earth",
              "magic.technique.charming",
			  "magic.mana.fire",
			  "magic.technique.chanting",
			  "magic.technique.charming",
			  "magic.mana.fire",
			  "magic.technique.charming",
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
  int duration, speed;
  object obj;
  object caster = param["caster"], target = param["target"];

  caster->practice_skill_conditional("magic.mana.earth",25,3);
  set_target(target);
  caster->msg_local("~[030~Subt ~vertis surrounded briefly in a bright yellow haze.~CDEF");

  if (obj = present_clone("/magic/obj/slow_object", target) ) {
    obj->end();
  } else if (obj = present_clone("/magic/obj/haste_object", target) ) {
    speed = 25 + 25 * caster->skill_check("magic.mana.fire", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.charming", 60, 80) * 10;
    obj->add_duration(duration);
    if (speed > obj->query_speed())
      obj->set_speed(speed);
  } else {
    obj = clone_object("/magic/obj/haste_object");
    speed = 25 + 25 * caster->skill_check("magic.mana.fire", 50, 100, 150);
    duration = 20 + caster->skill_check("magic.technique.charming", 60, 80) * 10;
    obj->set_victim(target);
    obj->set_duration(duration);
    obj->set_speed(speed);
    debug("speed = "+speed+", duration = "+duration,"combat");
  }

  return 1;
}
