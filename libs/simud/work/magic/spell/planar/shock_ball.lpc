#include <magic.h>
#include <battle.h>

string query_name() { return "shock ball"; }
int query_cost() { return 45; }
int query_violent() { return 1; }
string query_type() { return "lightning"; }
int query_level() { return 1; }

int query_readiness_requirement() { return 1250; }
int query_num_steps() { return 3; }
string query_step_msg(mapping param) {
  switch( param["step"] ) {
    case 0:
      return "~Name ~verbclap ~poss hands together loudly.";
    case 1:
      return "~Name ~verbbegin to rub ~poss hands together rapidly.";
    case 2:
      return "Sparks begin to leap up and down ~npos arms.";
    case 3:
      return "~Name ~verbseparates ~poss hands and turns ~poss palms toward ~targ.";
  }
  return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.technique.evoking",
              "magic.mana.lightning" })[step % 2];
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
  int dc, check, radius, zap;
  object caster = param["caster"], target = param["target"], ob;

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "electricity" : 6 + 2*caster->skill_check("magic.mana.lightning",dc,dc+25,dc+50) ]);

  caster->msg_local("~[030A tongue of lightning arcs from ~npos palms, striking ~targ!~CDEF");
 zap = target->take_damage(wc) / 5;

  // now do splash damage
  wc["electricity"] /= 2;
  radius = 2 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["electricity"]+", radius = "+radius,"magic");

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
     ob->add_held( max(zap, 1) );
  }// end: foreach target in the room
	
  return 1;
}
