// messages by Sora
#include <magic.h>
#include <battle.h>
#include <wizard.h> // for find_thing

string query_name() { return "call of hearthfires"; }
int query_cost() { return 100; }
string query_type() { return "earth"; }
int query_num_steps() { return 4; }
int query_readiness_requirement() { return 1000; }
int query_level() { return 0; }
string query_step_skill(mixed param) {
	switch( param["step"] ) {
		case 0: return "magic.mana.earth";
		case 1: return "magic.technique.binding";
		case 2: return "magic.technique.dancing";
		case 3: return "magic.mana.wind";
	}
	return "magic.mana.earth";
}

int valid_target( mapping param ) {
  return param["caster"] == param["target"];
}

varargs int on_cast(mapping param) {
	object room = find_objectref(param["caster"]->query_env_var("home"));
	set_actor( param["caster"] );
	if( !room ) {
		param["caster"]->msg_local("~[030~Name almost ~verbcomplete the spell when ~pron suddenly ~verbrealize that ~pron ~verbhas forgotten to specify a destination.~CDEF");
		return 1;
	}
	param["caster"]->msg_local("~[030The ground beneath ~npos feet reaches up and quickly swallows ~obje.~CDEF");
	msg_object(param["caster"], "You feel your body stretched thin as it is pulled through the plane of earth.");
	param["caster"]->move( room );
	param["caster"]->validate_position();
	param["caster"]->msg_local("~[030~Name ~verbappear out of the ground with a loud 'Pop!'~CDEF");
	return 1;
}
