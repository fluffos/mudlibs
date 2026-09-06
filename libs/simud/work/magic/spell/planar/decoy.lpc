#include <magic.h>
#include <battle.h>

string query_name() { return "decoy"; }
int query_level() { return 1; }
int query_cost() { return 200; }
string query_type() { return "earth"; }
int query_readiness_requirement() { return 1000; }
int query_num_steps() { return 3; }
string query_step_skill(mixed param) {
	switch (param["step"]) {
		case 0: return "magic.mana.earth";
		case 1: return "magic.technique.singing";
		case 2: return "magic.technique.binding";
	}
	return "magic.mana.earth";
}
string query_step_msg(mapping param) {
	switch (param["step"]) {
		case 0: return "~Name ~verbcall out to the spirit of stone.";
		case 1: return "~Name ~verbinvoke ballads of battle and melee.";
		case 2: return "~Name ~verbmotion randomly all around ~refl.";
	}
	return 0;
}
/*
string query_fail_msg(mapping param) {
	switch (param["step"]) {
	}
	return 0;
}
*/
int valid_target(mapping param) {
	return param["target"]->query_is_player();
}
string validate_params(mapping param) {
	object apple;
	if( !valid_target(param) )
		return "You may only cast this spell on yourself or another player";
	return "ok";
}
varargs int on_cast(mapping param) {
	object decoy;
	int hp;

	// debit hp first
	hp = to_int(param["caster"]->query_hp() * 0.95);
	param["caster"]->add_hp( -hp );

	// check for existing decoys... backlash
	decoy = present_clone( "/monsters/summon/decoy", environment(param["caster"]) );
	if( decoy ) {
		param["caster"]->msg_local( "~[030~Name ~verbstand completely still until ~pron ~verbis knocked down by a green blast.~CDEF" );
		msg_object( param["caster"], "~CWRNThere is already a decoy spirit at this location. Your spell has backfired.~CDEF" );
		param["caster"]->set_stance( ST_LYING );
		return 1;
	}

	// actually create the pet now
	decoy = clone_object( "/monsters/summon/decoy" );
	decoy->move(environment(param["caster"]));
    decoy->set_coord(WALK_DAEMON->query_random_adjacent(param["caster"]));
	decoy->validate_position();
	decoy->setup( param["caster"]->query_name(), hp );

	set_actor(param["caster"]);
	set_target(decoy);
	param["caster"]->msg_local( "~[030~Name ~verbstand completely still as ~targ ~vertfade into view beside ~obje.~CDEF" );

	return 1;
}
