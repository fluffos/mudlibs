#include <magic.h>
#include <battle.h>

string query_name() { return "aid"; }

int query_level() { return 1; }

int query_cost() { return 50; }

string query_type() { return "spirit"; }

int query_readiness_requirement() { return 1500; }

int query_num_steps() { return 6; }
string query_step_msg(mapping param) {
  switch (param["step"]) {
    case 0: return "~Name ~verbbegin praying to Example.";
    case 1: return "~Name ~verbgesture briefly in ~npot direction as ~pron ~verbcontinue to pray.";
	case 2: return "~Name ~verbstart chanting louder, more fervently.";
	case 3: return "~Npos voice finally reaches the point of shouting.";
	case 4: return "~Name rapidly ~verbcut the volume of ~poss chanting, reducing it to a hum.";
	case 5: return "~Npos voice falls to a whisper as the final words are spoken.";
  }
  return "OOPS!";
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.mana.spirit",
			  "magic.faith.healing",
			  "magic.faith.healing",
			  "magic.faith.healing",
			  "magic.technique.chanting",
			  "magic.mana.earth" })[step];
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  int heal_amt;
  object caster = param["caster"], target = param["target"], ai;
  heal_amt = caster->query_skill("magic.faith.healing") + caster->query_skill("magic.mana.spirit");
  heal_amt /= 2;
  heal_amt += random(heal_amt) + caster->query_stat("emp");

  if (target->query_hp() + heal_amt > target->query_max_hp() * 2)
     heal_amt = (target->query_max_hp() * 2) - target->query_hp();

  if (heal_amt < 1) {
     caster->msg_local("~[030~Name ~verbfinish praying and ~subt ~vertis surrounded by a dull green light.~CDEF");
	 msg_object(target,"~CACTYou received no healing from this spell.~CDEF");
  } else {
     caster->practice_skill_conditional("magic.faith.healing",50,3);
     caster->practice_skill_conditional("magic.mana.spirit",50,3);
     caster->msg_local("~[030~Name ~verbfinish praying and ~subt ~vertis surrounded by a brilliant green light.~CDEF");
     target->set_hp(target->query_hp()+heal_amt);
     msg_object(target,"~CACTYou have been healed for "+heal_amt+" hp.~CDEF");
  }
  // play nice with healing ai ;)
  if (ai = present_clone("/ai/heal",caster))
    ai->set_healing(0);
  return 1;
}
