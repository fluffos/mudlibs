#include <magic.h>
#include <battle.h>

string query_name() { return "mend"; }

int query_must_hold_target() { return 1; }

int query_level() { return 0; }

int query_cost() { return 50; }

string query_type() { return "order"; }

int query_readiness_requirement() { return 2000; }

int query_num_steps() { return 8; }

string query_step_skill(mixed param) {
	switch( param["step"] ) {
		case 0: return "magic.mana.order";
		case 1: return "magic.concentration";
		case 2: return "magic.item.misc";
		case 3: return "magic.technique.binding";
		case 4: return "magic.technique.chanting";
		case 5: return "magic.technique.enchanting";
		case 6: return "magic.technique.enchanting";
		case 7: return "magic.technique.chanting";
	}
	return "magic.mana.order";
}

string validate_params(mapping param) {
  param["cond"] = param["target"]->query_condition();
  param["max_cond"] = param["target"]->query_max_condition();

  if( param["target"]->query_broken() )
    return "It is too late to mend that.";
  if( param["cond"] * 100 / param["max_cond"] >= 50 )
    return "That isn't damage enough yet to need mending.";
  if( environment(param["target"]) != param["caster"] )
    return "You must be holding something to mend it.";
  else
    return "ok";
}

int valid_target(mapping param) {
  return validate_params(param) == "ok";
}

varargs int on_cast(mapping param) {
  int amt, needed;
  needed = (param["max_cond"] * 2 / 3) - param["cond"];
  amt = min(max( 20, param["caster"]->get_skill_roll("magic.concentration") * 2 ), needed);

  param["target"]->add_condition( needed );

  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~[030~Targ ~vertglow faintly in ~npos hands as it is mended slightly.~CDEF");

  return 1;
}
