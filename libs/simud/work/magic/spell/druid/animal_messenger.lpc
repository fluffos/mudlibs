#include <magic.h>
#include <battle.h>

string query_name() { return "animal messenger"; }
int query_level() { return 0; }
int query_cost() { return 20; }
string query_type() { return "earth"; }
int query_readiness_requirement() { return 1000; }
int query_num_steps() { return 4; }
string query_step_skill(mixed param) {
	switch (param["step"]) {
		case 0: return "magic.mana.earth";
		case 1: return "magic.technique.channeling";
		case 2: return "magic.technique.charming";
		case 3: return "magic.mana.spirit";
	}
	return "magic.mana.earth";
}
string query_step_msg(mapping param) {
	switch (param["step"]) {
		case 0: return "~Name ~verbsubmerge ~refl in the serenity of nature.";
		case 1: return "~Name silently ~verbcall for a messenger and ~verbfeel a response as the animal moves toward ~obje.";
		case 2: return "A large turtle arrives and nudges ~npos foot, craning its neck toward the "+param["component"]+" ~pron ~verbis holding.";
		case 3: return "~Name ~verbfocus intently as ~pron quietly ~verbread ~poss message to the creature.";
	}
	return 0;
}
string query_fail_msg(mapping param) {
	switch (param["step"]) {
		case 0: return "~Name cannot properly immerse ~refl in nature.";
		case 1: return "With all of the life around ~name, ~pron can't seem to connect to just one animal.";
		case 2: return "~Name ~verbfeel the animal approach and pass by without connecting to ~obje.";
		case 3: return "The turtle creeps away without ~npos message, having only come for the fruit.";
	}
	return 0;
}
int valid_target(mapping param) {
	return param["target"]->query_has_aspect(C_PAPER) &&
		   param["target"]->query_location("front");
}
string validate_params(mapping param) {
	object apple;
	if( !valid_target(param) )
		return "You must cast the spell on a written paper.";
	if( !find_player(param["option"]) )
		return "Right now, you must cast the spell 'to' a currently logged in player.";
	if( !param["component"] )
		return "You must specify a piece of fruit 'with' which to cast the spell.";
	apple = single_present(param["component"], param["caster"]);
	if( !apple )
		return "You don't appear to be holding any such '"+param["component"]+"' to offer your messenger.";
	if( !apple->query_has_aspect( C_FRUIT ) )
		return capitalize(apple->query_specific())+" is not a piece of fruit.";
	return "ok";
}
void enqueue_delivery( string name, string message ) {
	// cheesy delivery method for now
	call_out( "on_deliver", 30 + random(60), name, message );
}
varargs int on_cast(mapping param) {
	object apple = single_present(param["component"], param["caster"]);
	set_actor(param["caster"]);
	set_target(apple);
	param["caster"]->msg_local("~[030The turtle chomps ~targ, gulping it down before turning to carry ~npos message to its destination... eventually...~CDEF");
	enqueue_delivery( param["option"], param["target"]->query_location("front") );
	destruct(apple);
	return 1;
}
void on_deliver( string name, string message ) {
	object who = find_player(name);
	if( !who ) {
		call_out( "on_deliver", 600, name, message );
	} else {
		set_actor( who );
		who->msg_local("~CACTA large turtle crawls up to ~name and whispers something into ~poss ear.~CDEF");
		msg_object( who, "~CACTThe turtle says:~CDEF\n'"+message+"'");
	}
}
