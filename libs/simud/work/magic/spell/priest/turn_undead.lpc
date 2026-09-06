#include <magic.h>
#include <battle.h>

string query_name() { return "turn undead"; }

int query_cost() { return 25; }

string query_type() { return "spirit"; }
int query_violent() { return 1; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
string query_step_msg(mapping param) {
  if( param["step"] == 0 )
    return "~Name ~verbinvoke the name of Example.";
  else
    return 0;
}

int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.mana.spirit",
			  "magic.faith.judgement" })[step % 2];
}

int valid_target(mapping param) {
  object target = param["target"], caster = param["caster"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return target->query_race() == "undead";
}

varargs int on_cast(mapping param) {
  mapping wc;
  int check, dc;
  object caster = param["caster"], target = param["target"];
  object *zombies = filter( all_inventory(environment(target)), (: $1->query_race() == "undead" :) );

  dc = caster->get_skill_roll( "magic.faith.judgement" );
  // debug( "dc = "+dc, "magic" );

  caster->msg_local("~[030~Name ~verbis surrounded by a soft yellow light as ~pron ~verbchant in holy tones.~CDEF");

  foreach( target : zombies ) {
    if( caster->query_mana() < 5 ) {
      caster->msg_local("~CACT~Name ~verbpant with exhaustion.");
      return 1;
    }
    caster->add_mana( -5 );
    target->start_combat( caster );

    check = target->stat_check( "wil" );
    // debug( "check = "+check, "magic" );

    set_actor( target );
    set_target( caster );
    if( check < dc ) {
      target->msg_local("~CEMO~Name ~verbcower before ~targ!~CDEF");
      target->add_held( 20 + caster->query_stat("wil") - target->query_stat("wil") );
    } else {
      target->msg_local("~CEMO~Name ~verbresist ~npot utterances.~CDEF");
    }
  }

  return 1;
}