#include <magic.h>
#include <battle.h>

string query_name() { return "exorcise"; }

int query_cost() { return 15; }

string query_type() { return "spirit"; }
int query_violent() { return 1; }

int query_readiness_requirement() { return 1000; }
int query_num_steps() { return 4; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbgesture calmly while staring into ~post soul.";
  else
    return 0;
}

int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.mana.spirit",
			  "magic.faith.judgement",
              "magic.technique.cursing",
			  "magic.mana.fire" })[step];
}

int valid_target(mapping param) {
  object target = param["target"], caster = param["caster"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
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
  law = (1000 + (law * 15)) / 16;
  good = (1000 + (good * 15)) / 16;
  debug("law = "+law+", good = "+good, "combat");
  caster->set_alignment(0, good);
  caster->set_alignment(1, law);

  dc = max(10, 25-caster->query_modified_skill("magic.technique.evoking"));
  wc = ([ "holy" : 3 + caster->skill_check("magic.mana.spirit",dc,dc+25,dc+50)
                     + caster->skill_check("magic.faith.judgement",dc) ]);

  target->take_damage(wc);
  caster->msg_local("~[030A bright yellow light explodes from ~targ!~CDEF");

  // alter alignment
  law = target->query_lawful_alignment();
  good = target->query_good_alignment();
  if (law > 350 && good > 350)
    return 1;
  debug("law = "+law+", good = "+good, "combat");
  law = (350 + (law * 15)) / 16;
  good = (350 + (good * 15)) / 16;
  debug("law = "+law+", good = "+good, "combat");
  target->set_alignment(0, good);
  target->set_alignment(1, law);

  msg_object(target,"~CTITYour whole body convulses as the evil is purged from your soul!~CDEF");
  return 1;
}
