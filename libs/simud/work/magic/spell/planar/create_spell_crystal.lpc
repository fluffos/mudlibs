#include <magic.h>
#include <battle.h>

string query_name() { return "create spell crystal"; }

int query_must_hold_target() { return 1; }

int query_level() { return 1; }

int query_cost() { return 50; }

string query_type() { return "spirit"; }

int query_readiness_requirement() { return 2000; }

int query_num_steps() { return 8; }

string query_step_skill(mixed param) {
	debug("need to figure out step skills","magic");
	if( param["option"] )
		return "magic.mana."+param["option"];
	else
		return "magic.mana.spirit";
}
/*
string query_step_msg(mapping param) {
  switch (param["step"]) {
    case 0: return "~Name ~verbtouch ~targ on the head and ~verbbegin chanting.";
    case 1: return "A bright light begins to emanate from ~npos hand.";
  }
  return "OOPS!";
}
*/

int valid_target(mapping param) {
  if( !param["target"]->query_has_aspect(C_RAW) ||
      !param["target"]->query_has_aspect(C_CRYSTAL) ||
      !param["target"]->query_has_aspect(C_QUARTZ) ) {
    return 0;
  }
  return 1;
}

string validate_params(mapping param) {
  if( !valid_target(param) )
    return "You can only currently cast this spell on small quartz crytals.";
  else if( !param["target"]->query_has_aspect(C_SMALL) )
    return "Only _small_ quartz crystals work for this spell at the moment.";
  else if( param["caster"]->query_skill("magic.mana."+param["option"]) )
    return "ok";
  else if ( param["option"] )
    return "'"+param["option"]+"' is not a valid mana type.";
  else
    return "You must specify the mana type: 'cast create spell crystal on crystal as spirit', etc...";
}

varargs int on_cast(mapping param) {
  int amt, needed;
  object ob = clone_object("/magic/obj/spell_crystal");
  ob->set_mana_type( MAGIC_DAEMON->query_mana_aspect(param["option"]) );
  ob->move(param["caster"]);

  param["caster"]->practice_skill_conditional("magic.mana."+param["option"], 50, 3);
  param["caster"]->practice_skill_conditional("magic.technique.enchanting", 50, 3);

  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~[030~Name ~verbtransform ~targ into a "+param["option"]+" spell crystal.~CDEF");

  destruct(param["target"]);

  return 1;
}
