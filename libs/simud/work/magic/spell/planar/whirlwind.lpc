#include <magic.h>
#include <battle.h>

string query_name() { return "whirlwind"; }
int query_cost() { return 100; }
int query_violent() { return 1; }
string query_type() { return "wind"; }
int query_level() { return 2; }

int query_readiness_requirement() { return 2000; }
int query_num_steps() { return 8; }
string query_step_msg(mapping param) {
    return "~Name ~verbgesture rapidly at ~targ.";
}
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.technique.evoking",
              "magic.mana.wind",
			  "magic.technique.dancing" })[step % 3];
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
  wc = ([ "edged" : 18 + caster->skill_check("magic.mana.wind",dc,dc+25,dc+50),
          "ice": 2 + caster->skill_check("magic.mana.ice",dc,dc+25,dc+50,dc+75) ]);

  debug("initial wc = "+wc["edged"]+"/"+wc["ice"],"magic");
  caster->msg_local("~[030~Subt ~vertis engulfed in a fierce whirlwind!~CDEF");

  target->take_damage(wc);

  // now do splash damage
  wc["edged"] = wc["edged"] * 2 / 3;
  radius = 6 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["edged"]+"/"+wc["ice"]+", radius = "+radius,"magic");

  foreach( ob : all_inventory(environment(target)) ) {
    int distance = WALK_DAEMON->query_distance( target, ob );
    // validate teh new victim
    if( !valid_target( param + (["target":ob]) ) || distance > radius )
      continue;
    // hit them
    if( ob != target ) {
      debug("hitting "+ob->query_name()+", distance = "+distance,"magic");
      set_target( ob );
      caster->msg_local("~[030~Subt ~vertis caught in the whirlwind!~CDEF");
      ob->take_damage( wc );
    }
  }
	
  return 1;
}
