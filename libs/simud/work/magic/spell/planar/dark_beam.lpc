#include <magic.h>
#include <battle.h>

string query_name() { return "dark beam"; }
int query_cost() { return 60; }
int query_violent() { return 1; }
string query_type() { return "dark"; }
int query_level() { return 2; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbis quickly hidden in shadow.";
  else
    return 0;
}
string query_fail_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "Shadows begin to concentrate around ~name, but they are quickly dispelled.";
    case 1: return "~Name ~verbis temporarily blinded as the shadows recede and ~pron is revealed to the light once again.";
  }
  return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.dark";
  	return ({ "magic.mana.dark",
			  "magic.technique.evoking",
			  "magic.technique.cursing",
			  "magic.mana.dark" })[step];
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
  int check, dc, law, good;
  object caster = param["caster"], target = param["target"];

  law = caster->query_lawful_alignment();
  good = caster->query_good_alignment();
  debug("law = "+law+", good = "+good, "combat");
  law = (-1000 + (law * 15)) / 16;
  good = (-1000 + (good * 15)) / 16;
  debug("law = "+law+", good = "+good, "combat");
  caster->set_alignment(0, good);
  caster->set_alignment(1, law);

  check = 25 - caster->query_skill_roll("magic.technique.evoking");
  dc = max(10, 25-check);
  wc = ([ "dark" : 16 + caster->skill_check("magic.mana.dark",dc,dc+25,dc+50)
                     + caster->skill_check("magic.technique.necromancy",dc) ]);

  target->take_damage(wc);
  caster->msg_local("~[030Darkness streams from the shadows and wracks ~npot body with pain.~CDEF");

  // alter alignment
  law = target->query_lawful_alignment();
  good = target->query_good_alignment();
  if (law < -350 && good < -350)
    return 1;
  debug("law = "+law+", good = "+good, "combat");
  law = (-350 + (law * 15)) / 16;
  good = (-350 + (good * 15)) / 16;
  debug("law = "+law+", good = "+good, "combat");
  target->set_alignment(0, good);
  target->set_alignment(1, law);

  msg_object(target,"~CDRKYour soul burns in agony.~CDEF");
  return 1;
}
