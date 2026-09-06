#include <magic.h>
#include <battle.h>

string query_name() { return "ice ball"; }
int query_cost() { return 30; }
int query_violent() { return 1; }
string query_type() { return "ice"; }
int query_level() { return 1; }

int query_readiness_requirement() { return 800; }
int query_num_steps() { return 3; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbhold out~poss palm.\n~Poss breath turns to steam as the air around ~obje freezes.";
  else
    return 0;
}
string query_fail_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "The air around ~name chills momentarily before it is swept away by the wind and ~poss spell is lost.";
    case 1: return "The air around ~name shatters loudly as shards of ice fall to the ground around ~obje as ~poss spell is lost.";
  }
  return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.ice";
  	return ({ "magic.mana.ice",
              "magic.technique.evoking",
			  "magic.mana.ice" })[step];
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

  dc = target->query_modified_skill("magic.technique.evoking", 25, 50, 75) + target->query_stat("dex");
  check = caster->skill_checl("magic.mana.ice",dc,2*dc,3*dc);
  wc = ([ "ice" : 16 + (check>2?2:check), "piercing" : 1 + (check>1?1:check) ]);

  target->take_damage_percent(wc);
  caster->msg_local("~[030Daggers of ice fly from ~npos outstretched palm into ~targ.~CDEF");

  // now do splash damage
  wc["ice"] /= 2;
  radius = 2 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["ice"]+", radius = "+radius,"magic");

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
     check = caster->skill_check("magic.mana.ice", 20, 40, 60, 70, 75) - target->skill_check("magic.intuition", 60, 80, 100);
     if(check > 0 ) {
        ob->add_readiness(-50 * check );
        msg_object(ob, "~CLABYou feel your blood chill and slow momentarily.~CDEF");
     }
  }// end: foreach target in the room
	
  return 1;
}
