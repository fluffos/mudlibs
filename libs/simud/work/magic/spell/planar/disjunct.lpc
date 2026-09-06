#include <magic.h>
#include <battle.h>

string query_name() { return "disjunct"; }

int query_must_hold_target() { return 1; }

int query_level() { return 1; }

int query_cost() { return 5; }

string query_type() { return "chaos"; }

int query_readiness_requirement() { return 1000; }

int query_num_steps() { return 4; }

string query_step_skill(mixed param) {
	switch( param["step"] ) {
		case 0: return "magic.technique.evoking";
		case 1: return "magic.technique.channeling";
		case 2: return "magic.item.misc";
		case 3: return "magic.technique.channeling";
	}
	return "magic.mana.chaos";
}

string validate_params(mapping param) {
  if( param["target"]->query_is_living() )
    return "You can only disjunction inanimate objects.";
  if( param["target"]->query_quantity() > 1 )
    return "You may only disjunction one item at a time.";
  if( environment(param["target"]) != param["caster"] )
    return "You must be holding something to disjunction it.";
  else
    return "ok";
}

int valid_target(mapping param) {
  return validate_params(param) == "ok";
}

varargs int on_cast(mapping param) {
  int amt, dc;
  amt = 0;
  /**
  // TODO: special flag for artifact items to protect them from dj
  if( param["target"]->query_has_aspect( C_ARTIFACT ) ) {
    set_actor( param["caster"] );
    set_target( param["target"] );
    param["caster"]->msg_local("~CWRN~Subt ~verttwist violently in ~npos hands as ~prot ~vertresist ~poss disjunction!~CDEF");
    // hit them with a major hold effect
    param["caster"]->add_held( 20 );
    return 1;
  }
   */

  // chargable items are easiest - their mana comes out 1:1
  if( param["target"]->query_mana_capacity() ) {
    amt = param["target"]->query_mana_quantity();
  } else // they're disjunctioning a bleeding spellbook... 3:1 x each spell
  if( param["target"]->id("spellbook") && param["target"]->query_num_pages() ) {
    string spell;
    foreach( spell : param["target"]->query_pages() ) {
      if( stringp(spell) )
        amt += MAGIC_DAEMON->query_spell_cost( param["target"]->query_spell() ) / 3;
    }
  } else // scrolls are also a special case 1:1 (2:1 from the investment)
  if( param["target"]->id("scroll") && param["target"]->query_spell() ) {
    amt = MAGIC_DAEMON->query_spell_cost( param["target"]->query_spell() );
  } else // condition-driven wands... 1:4 condition:mana
  if( param["target"]->query_has_aspect(C_WAND) ) {
    amt = param["target"]->query_condition() * 4;
  } else // potions... for now are just 200 mana
  if( param["target"]->query_has_aspect(C_POTION) ) {
    amt = 200;
  } else { // everything else is weight->mana at 50g:1
    amt = max(1, param["target"]->query_weight() / 50);
  }

  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~CBRT~Targ ~vertflare in a blaze of yellow and green light as it is disjunctioned!~CDEF");

  // if the caster is overmax, he might not be able to absorb any of the energy
  if( param["caster"]->query_mana() > param["caster"]->query_max_mana() ) {
    int check;
    dc = param["caster"]->query_mana() - param["caster"]->query_max_mana();
    dc += amt / 10;
    if( check = param["caster"]->skill_check("magic.technique.channeling", dc) ) {
      msg_object(param["caster"],"~CBRTYou struggle against the overwhelming surge of energy and somehow manage to control it!~CDEF");
    } else {
      msg_object(param["caster"],"~CWRNThe surge of released energy is too much for you to control!~CDEF");
      param["caster"]->add_held( max(2, amt / 10) );
      destruct( param["target"] );
      return 1;
    }
    debug("dc = "+dc+", check = "+check, "magic");
  } // end: if overmax

  msg_object(param["caster"],"~CACTYou are healed for "+amt+" mana.~CDEF");
  param["caster"]->msg_local("~[030~Name ~verbglow softly as ~verbtap into the released mana.~CDEF");

  param["caster"]->set_mana( param["caster"]->query_mana() + amt );
  "/bin/hp"->force( param["caster"] );

  destruct( param["target"] );

  return 1;
}
