#include <magic.h>
#include <battle.h>

string query_name() { return "fire explosion"; }
int query_cost() { return 60; }
int query_violent() { return 1; }
string query_type() { return "fire"; }
int query_level() { return 2; }

int query_readiness_requirement() { return 700; }
int query_num_steps() { return 3; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Npos eyes burn with passion as ~pron ~verbhold out ~poss palm toward ~targ.";
  else
    return 0;
}
string query_fail_msg(mapping param) {
  switch( param["step"] ) {
    case 0: return "~Name hold ~poss palm out to ~targ but nothing happens.";
    case 1: return "~Name ~verbburn ~refl.";
  }
  return 0;
}
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.fire";
  	return ({ "magic.technique.evoking",
              "magic.mana.wind",
			  "magic.mana.fire" })[step];
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster))
    return 0;
  if ( !target->query_is_living() && !target->query_has_aspect( C_PLANT ) )
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  mapping wc;
  int dc, check, radius;
  object caster = param["caster"], target = param["target"], ob;

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "fire" : 13 + 2*caster->skill_check("magic.mana.fire",dc,dc+25,dc+50) ]);

  if( target->query_has_aspect( C_PLANT ) ) {
    caster->msg_local("~[030A stream of flame erupts from ~npos outstretched palm and engulfs ~targ!~CDEF");
    target->add_damage( wc["fire"] * 3 );
    if( target->query_damage() >= target->query_max_hp() ) {
       caster->msg_local("~CWRN~Targ ~vertis reduced to a pile of smouldering ash.~CDEF");
       destruct( target );
    }
    return 1;
  }

  caster->msg_local("~[030A stream of flames erupts from ~npos outstretched palm toward ~targ.\nThe flames explode in a giant ring around ~objt.~CDEF");

  target->take_damage(wc);

  // now do splash damage
  radius = 6 + caster->skill_check("magic.technique.evoking",50,70,80,90,100);
  debug("splash wc = "+wc["fire"]+", radius = "+radius,"magic");

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
    // light them on fire ;)
    dc = ob->query_modified_skill("magic.technique.evoking") + ob->query_stat("dex");
    check = caster->skill_check("magic.mana.fire", dc);
    debug("dc = "+dc+", check = "+check, "combat");
    if ( check ) {
      object bleeder;
      int strength = 2 * caster->query_modified_skill("magic.mana.fire");
      caster->practice_skill("magic.mana.fire", 25, 1);
      bleeder = present_clone("/battle/bleeder_object",target);
      if (!bleeder) {
        set_target(ob);
        ob->msg_local("~CWRN~Post flesh catches on fire!~CDEF");
        bleeder = clone_object("/battle/bleeder_object");
        bleeder->set_hit_msg("Your flesh is burning!");
        bleeder->set_end_msg("The fire is finally extinguished.");
        bleeder->set_speed(10);
        bleeder->set_dam_type("fire");
        bleeder->set_strength( strength );
        bleeder->set_victim(target);
      } else {
        bleeder->add_strength( strength );
      }
    }
  }// end: foreach target in the room
	
  return 1;
}
