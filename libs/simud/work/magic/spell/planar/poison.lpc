#include <magic.h>
#include <battle.h>

string query_name() { return "poison"; }

int query_cost() { return 30; }

string query_type() { return "earth"; }

int query_violent() { return 1; }

int query_num_steps() { return 8; }
string query_step_msg(mapping param) {
  switch (param["step"]) {
    case 0: return "~Name ~verbbegin to swirl ~poss hands in front of "+
                   "~refl, as if stirring something.";
    case 1: return "~Name ~verbmake motions as if adding ingredients to "+
                   "the pot.";
    case 2: return "~Name ~verbstop mixing and ~verbmotion as if tapping "+
                   "the pot with a spoon.";
    case 3: return "~Name ~verbgive the mixture another quick stir.";
    case 4: return "~Name ~verblift the imaginary cauldron to ~poss lips.";
  }
   return 0;
}
int query_level() { return 1; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.earth";
  	return ({ "magic.mana.earth",
			  "magic.mana.earth",
			  "magic.mana.earth",
			  "magic.technique.brewing",
			  "magic.technique.brewing",
			  "magic.technique.brewing",
			  "magic.technique.cursing",
			  "magic.mana.wind" })[step];
}

int query_readiness_requirement() { return 2000; }

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  int strength = 10 + random(20), speed = 1;
  object obj = clone_object("/battle/bleeder_object");
  object caster = param["caster"], target = param["target"];

  caster->practice_skill_conditional("magic.mana.earth",50,6);

  strength += caster->query_skill("magic.mana.earth") / 2;
  speed += caster->skill_check("magic.mana.wind",20,40,80);

  obj->set_victim(target);
  obj->set_strength(strength);
  obj->set_speed(speed);

  caster->msg_local("~[030~Name ~verbblow across the lid of ~poss "+
      "imaginary container and a thick green cloud engulfs ~subt.~CDEF");
  return 1;
}
