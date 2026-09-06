#include <magic.h>
#include <battle.h>

string query_name() { return "addle"; }

int query_cost() { return 50; }

string query_type() { return "chaos"; }
int query_violent() { return 0; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }

int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.technique.cursing",
			  "magic.mana.chaos",
              "magic.technique.cursing", })[step];
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
  int check, dc;
  object caster = param["caster"], target = param["target"];

  set_actor(caster);
  set_target(target);
  caster->msg_local("~[030Dark orange and yellow mist swirls around ~targ!~CDEF");

  dc = caster->get_skill_roll("magic.technique.cursing") + 75;
  check = target->get_stat_roll("wil") * 2;
  set_actor(target);
  if( check >= dc ) {
    target->msg_local("~CDEF~Name ~verbshrug off the effects of the mist.");
  } else {
    string who, *party;
    target->msg_local("~CDEF~Name ~verbis confused by the mist.");
    // confund them
    target->stop_combat();
    party = PARTY_DAEMON->query_party_members( target->query_env_var("party") );
    foreach( who : party ) {
      object ob = single_present( who, environment(target) );
      target->start_combat( ob );
    }
  }

  return 1;
}
