#include <magic.h>
#include <battle.h>

string query_name() { return "dark explosion"; }
int query_cost() { return 90; }
int query_violent() { return 1; }
string query_type() { return "dark"; }
int query_level() { return 1; }

int query_readiness_requirement() { return 1000; }
int query_num_steps() { return 3; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbis quickly hidden in shadow.";
  else
    return 0;
}
string query_fail_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "Shadows begin to concentrate around ~name, but they are quickly dispelled.";
    case 1: return "~Name ~verbis temporarily blinded as the shadows recede and ~pron is revealed to the light once again.";
  }
  return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.dark";
  	return ({ "magic.mana.dark",
			  "magic.technique.evoking",
			  "magic.technique.cursing",
			  "magic.mana.dark" })[step];
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
  int dc, check, radius, law, good;
  object caster = param["caster"], target = param["target"], ob;

  law = caster->query_lawful_alignment();
  good = caster->query_good_alignment();
  debug("law = "+law+", good = "+good, "combat");
  law = (-1000 + (law * 15)) / 16;
  good = (-1000 + (good * 15)) / 16;
  debug("law = "+law+", good = "+good, "combat");
  caster->set_alignment(0, good);
  caster->set_alignment(1, law);

  check = 25 - caster->query_skill_roll("magic.technique.evoking");
  dc = max(10, 25-check);
  wc = ([ "dark" : 13 + caster->skill_check("magic.mana.dark",dc,dc+25,dc+50)
                     + caster->skill_check("magic.technique.necromancy",dc) ]);

  target->take_damage(wc);
  caster->msg_local("~[030Darkness streams from the shadows and wracks ~npot body with pain.~CDEF");

  // now do splash damage
  wc["dark"] /= 2;
  radius = 2 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["dark"]+", radius = "+radius,"magic");

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
     // alter alignment
     law = ob->query_lawful_alignment();
     good = ob->query_good_alignment();
     if (law < -350 && good < -350)
       continue;
     debug("law = "+law+", good = "+good, "combat");
     law = (-350 + (law * 15)) / 16;
     good = (-350 + (good * 15)) / 16;
     debug("law = "+law+", good = "+good, "combat");
     ob->set_alignment(0, good);
     ob->set_alignment(1, law);
  }// end: foreach target in the room
	
  return 1;
}
