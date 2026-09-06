#include <magic.h>
#include <battle.h>

//The messages are compliments of Sora

string query_name() { return "hold"; }

int query_cost() { return 25; }

string query_type() { return "spirit"; }

int query_violent() { return 1; }

int query_num_steps() { return 7; }

int query_readiness_requirement() { return 1700; }

string query_step_msg(mapping param) {
   switch (param["step"]) {
      case 0: return "~Name ~verblift ~poss hand above ~poss head, with ~poss fingers spread out.";
      case 1: return "~Name ~verbbegin whistling a mid-ranged tune. A very small, rapidly-spinning sphere of light beams is created above ~poss hand.";
      case 2: return "~Npos left hand, still outstretched starts moving until pointing at ~targ. The sphere follows ~npos hand.";
      case 3: return "~Name ~verbclench ~poss fist, now pointing directly at ~targ. The sphere continues to grow.";
      case 4: return "~Name ~verbstop whistling, ending the tune with a descending triplet. At the last note, the sphere moves toward ~targ.";
    }
   return 0;
}
int query_level() { return 1; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.wind";
  	return ({ "magic.technique.cursing",
              "magic.mana.spirit",
			  "magic.mana.wind",
			  "magic.technique.binding",
			  "magic.mana.wind",
			  "magic.technique.channeling",
			  "magic.technique.binding" })[step];
}

string query_fail_msg(mapping param) {
   switch (param["step"]) {
      case 0: return "As ~Name ~verbstart to raise ~poss hand into the air, ~poss thumb catches his chin.";
      case 1: return "~Name ~verbtry whistling, but can't get proper sounds out.";
      case 2: return "~Name ~verbstart moving ~poss hand down, and ~verbrealize that ~poss ~verbis facing the wrong direction. The ball of light disappears in a bright flash.";
      case 3: return "~Name, too focused on whistling, ~verbdo not clench ~poss hand at the proper moment, so the light beams get too far apart, and the sphere gradually disappears as it grows in size.";
      case 4: return "~Npos whistling ends, but the last note in the triplet was too low. The sphere gradually diminishes to a point speck of light, and then disappears.";
      case 5: return "As the sphere moves toward ~targ, its shape gets distorted, until, when it gets to ~targ, it is a tall vertical line that has no effect.";
   }
   return "OOPS!";
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  int time = 10;
  object caster = param["caster"], target = param["target"];
  caster->practice_skill_conditional("magic.technique.cursing",50,3);
  caster->practice_skill_conditional("magic.mana.spirit",50,3);
  caster->practice_skill_conditional("magic.mana.wind",50,3);

  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~[030As the sphere gets to ~targ, it surrounds ~obje. Then, at that instant, it becomes transparent.~CDEF");

  time += caster->query_skill("magic.technique.binding") / 20;
  time += caster->query_skill("magic.mana.wind") / 20;

  target->add_held(time);
//  target->add_readiness(time * -25);

  caster->msg_local("~[030~Name ~verbmake an arcane gesture and ~subt ~vertis surrounded by rings of red light.~CDEF");
  return 1;
}
