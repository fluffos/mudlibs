#include <magic.h>
#include <battle.h>

string query_name() { return "greater heal"; }

int query_cost() { return 50; }

string query_type() { return "spirit"; }

int query_readiness_requirement() { return 1750; }

int query_num_steps() { return 6; }
string query_step_msg(mapping param) {
  if (param["step"] == 0)
    return "~Name ~verbbegin praying to Example.";
  else if (param["step"] == 1 && param["caster"] == param["target"])
    return "~Name ~verbgesture briefly in ~npot own direction as ~pron ~verbcontinue to pray.";
  else
    return "~Name ~verbgesture briefly in ~npot direction as ~pron ~verbcontinue to pray.";
}
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.mana.spirit",
              "magic.faith.healing",
			  "magic.technique.chanting",
			  "magic.faith.healing",
			  "magic.technique.singing",
			  "magic.mana.earth" })[step % 6];
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
  heal_amt += random(heal_amt) + (caster->query_stat("emp") * 2);

  if ( target->query_hp() < target->query_max_hp() ) {
     target->add_hp(heal_amt);
     caster->practice_skill_conditional("magic.faith.healing",50,3);
     caster->practice_skill_conditional("magic.mana.spirit",50,3);
  }

  caster->msg_local("~[030~Name ~verbfinish praying and ~subt ~vertis briefly surrounded by a radiant green aura.~CDEF");
  msg_object(target,"~CACTYou have been healed for "+heal_amt+" hp.~CDEF");
  // play nice with healing ai ;)
  if (ai = present_clone("/ai/heal",caster))
    ai->set_healing(0);
  return 1;
}
