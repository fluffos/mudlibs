#include <magic.h>
#include <battle.h>

string query_name() { return "mana ball"; }
int query_cost() { return 30; }
int query_violent() { return 1; }
string query_type() { return "spirit"; }
int query_level() { return 1; }

int query_readiness_requirement() { return 600; }
int query_num_steps() { return 3; }
string query_step_msg(mapping param) {
    return "~Name ~verbgesture rapidly at ~targ.";
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.technique.evoking",
              "magic.mana.spirit",
              "magic.technique.evoking" })[step];
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
  int dc, check, radius;
  object caster = param["caster"], target = param["target"], ob;

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "mana" : 6 + 2*caster->skill_check("magic.mana.fire",dc,dc+25,dc+50) ]);

  caster->msg_local("~[030~Name ~verbgesture again, this time hurling a bolt of magic at ~targ.~CDEF");

  target->take_damage(wc);

  // now do splash damage
  wc["mana"] /= 2;
  radius = 2 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["mana"]+", radius = "+radius,"magic");

  foreach( ob : all_inventory(environment(target)) ) {
    int distance = WALK_DAEMON->query_distance( target, ob );
    // validate teh new victim
    if( !valid_target( param + (["target":ob]) ) || distance > radius )
      continue;
    // hit them
    if( ob != target ) {
      debug("hitting "+ob->query_name()+", distance = "+distance,"magic");
      set_target( ob );
      caster->msg_local("~[030~Subt ~vertis caught in the blast!~CDEF");
      ob->take_damage( wc );
    }
  }
	
  return 1;
}
