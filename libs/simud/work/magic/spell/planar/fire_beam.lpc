#include <magic.h>
#include <battle.h>

string query_name() { return "fire beam"; }
int query_cost() { return 50; }
int query_violent() { return 1; }
string query_type() { return "fire"; }
int query_level() { return 2; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
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
  	return ({ "magic.technique.evoking",
			  "magic.mana.fire" })[step%2];
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
  int dc, check;
  object caster = param["caster"], target = param["target"];

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "fire" : 16 + 2*caster->skill_check("magic.mana.fire",dc,dc+25,dc+50) ]);

  if( target->query_has_aspect( C_PLANT ) ) {
    caster->msg_local("~[030A stream of flame erupts from ~npos outstretched palm and engulfs ~targ!~CDEF");
    target->add_damage( wc["fire"] * 3 );
    if( target->query_damage() >= target->query_max_hp() ) {
       caster->msg_local("~CWRN~Targ ~vertis reduced to a pile of smouldering ash.~CDEF");
       destruct( target );
    }
    return 1;
  }
  target->take_damage(wc);

  caster->msg_local("~[030A stream of flames erupts from ~npos outstretched palm toward ~targ.~CDEF");

  // light them on fire ;)
  dc = target->query_modified_skill("magic.technique.evoking") + target->query_stat("dex");
  check = caster->skill_check("magic.mana.fire", dc);
  debug("dc = "+dc+", check = "+check, "combat");
  if ( check ) {
    object bleeder;
    int strength = 3 * caster->query_modified_skill("magic.mana.fire");
    caster->practice_skill("magic.mana.fire", 25, 1);
    bleeder = present_clone("/battle/bleeder_object",target);
    if (!bleeder) {
      set_target(target);
      target->msg_local("~CWRN~Post flesh catches on fire!~CDEF");
      bleeder = clone_object("/battle/bleeder_object");
      bleeder->set_hit_msg("Your flesh is burning!");
      bleeder->set_end_msg("The fire is finally extinguished.");
      bleeder->set_speed(20);
      bleeder->set_dam_type("fire");
      bleeder->set_strength( strength );
      bleeder->set_victim(target);
    } else {
      bleeder->add_strength( strength );
    }
  }
  return 1;
}
