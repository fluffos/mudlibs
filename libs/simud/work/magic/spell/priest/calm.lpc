#include <magic.h>
#include <battle.h>

string query_name() { return "calm"; }

int query_cost() { return 25; }

string query_type() { return "order"; }
int query_violent() { return 0; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 4; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbgesture soothingly to ~targ.";
  else
    return "~Name ~verbcontinue to make soothing gestures at ~targ.";
}

int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.technique.charming",
			  "magic.faith.judgement",
              "magic.mana.spirit",
			  "magic.mana.order" })[step];
}

int valid_target(mapping param) {
  object target = param["target"], caster = param["caster"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  // only targets in combat are valid victims for this spell
  if( !target->query_in_combat() || target == caster )
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  mapping wc;
  int check, dc, law, good;
  object caster = param["caster"], target = param["target"];

  dc = target->get_save_roll( "wil" ) - 50;
  check = caster->skill_check( "magic.technique.charming", dc );
  if( check ) {
    mixed actions = target->query_actions();
    caster->msg_local("~[030A faint blue mist gathers around ~targ as ~prot ~vertcalm down.~CDEF");
    target->stop_combat();
    caster->stop_combat();
	if( sizeof(actions) > 0 ) {
      actions[0][B_FNAME]->on_interrupt(actions[0]);
    }
    target->set_actions( 0 );
  } else {
    caster->msg_local("~[030~Targ ~vertbrush aside ~npos spell and ~vertcontinue fighting!~CDEF");
    target->practice_stat("wil");
  }

  return 1;
}
