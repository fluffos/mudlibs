#include <magic.h>
#include <battle.h>

string query_name() { return "animate pumpkin"; }
int query_level() { return 1; }
int query_cost() { return 250; }
string query_type() { return "fire"; }
int query_readiness_requirement() { return 2000; }
int query_num_steps() { return 8; }
string query_step_skill(mixed param) {
	switch (param["step"]) {
		case 0: return "magic.mana.earth";
		case 1: return "magic.technique.singing";
		case 2: return "magic.technique.singing";
		case 3: return "magic.mana.fire";
		case 4: return "magic.technique.dancing";
		case 5: return "magic.technique.dancing";
		case 6: return "magic.mana.fire";
		case 7: return "magic.faith.blessing";
	}
	return "magic.mana.earth";
}
string query_step_msg(mapping param) {
	switch (param["step"]) {
		case 0: return "~Name ~verbcall out to the spirit of the harvest.";
		case 1: return "~Name ~verbsing a song of deception and betrayal.";
		case 2: return "~Name ~verbbegin to dance as the music continues on without ~obje.";
		case 3: return "~Name ~verbcall upon the spirits of vengeance and anger.";
		case 4: return "~Name ~verbdance in wheeling arcs around ~targ.";
		case 5: return "~Name ~verbleap over ~targ.";
		case 6: return "With only ~poss finger, ~Name ~verbdraw the outline of a face on ~targ.";
		case 7: return "Flames leap from ~npot face and swirl around ~prot in a halo of light.";
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
	return param["target"]->query_has_aspect(C_SQUASH) &&
		   param["target"]->query_has_aspect(C_CROP);
}
string validate_params(mapping param) {
	object apple;
	if( !valid_target(param) )
		return "You must cast the spell on a whole squash of some sort or another.";
	return "ok";
}
varargs int on_cast(mapping param) {
	object jack, ai;
	int bonus = param["caster"]->skill_check("magic.mana.fire",50,60,70,80,90,100);

	set_actor(param["caster"]);
	set_target(param["target"]);
	param["caster"]->msg_local("~[030~Subt ~verttake on a life of ~post own and ~vertbegin to float next to ~name.~CDEF");
	destruct(param["target"]);

	jack = clone_object("/monsters/summon/jackolantern");
	jack->move(environment(param["caster"]));
	jack->validate_position();
	// heal pumpkin man
	jack->set_stat("con",jack->query_stat("con")+(bonus/2));
	jack->set_stat("int",jack->query_stat("int")+(bonus/2));
	jack->set_stat("spd",jack->query_stat("spd")+bonus);
	jack->set_stat("wil",jack->query_stat("wil")+bonus);

	jack->set_hp(jack->query_max_hp());
	jack->set_mana(jack->query_max_mana());
	jack->set_endurance(jack->query_max_endurance());

	// unfortunately, on_hire is a bit flaky right now and only works if the caster is
	// set to this_player()
	ai = present_clone("/ai/worker",jack);
	ai->on_hire();

	command("follow "+(param["caster"]->query_name()),jack);

	jack->set_time_to_live( max(20,param["caster"]->get_skill_roll("magic.faith.blessing")/2) );

	return 1;
}
