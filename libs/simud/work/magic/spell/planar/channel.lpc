#include <magic.h>
#include <battle.h>

string query_name() { return "channel"; }

int query_level() { return 0; }

int query_cost() { return 5; }

string query_type() { return "spirit"; }

int query_readiness_requirement() { return 1000; }

int query_num_steps() { return 4; }
string query_step_msg(mapping param) {
  switch (param["step"]) {
    case 0: return "~Name ~verbtouch ~targ on the head and ~verbbegin chanting.";
    case 1: return "A bright light begins to emanate from ~npos hand.";
  }
  return 0;
}

string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.spirit";
  	return ({ "magic.concentration",
			  "magic.technique.channeling",
			  "magic.mana.spirit",
			  "magic.technique.channeling" })[step];
}

int valid_target(mapping param) {
  if (environment(param["target"]) != environment(param["caster"]) &&
      environment(param["target"]) != param["caster"] ||
      param["target"] == param["caster"] ||
      !param["target"]->query_is_living() ||
      param["target"]->query_dead())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
   int amt, needed;

   amt = 10 + 10 * param["caster"]->skill_check("magic.mana.spirit", 20, 40, 60, 80);
   needed = param["target"]->query_max_mana() - param["target"]->query_mana();
   if (amt > needed)
      amt = needed;
   if (param["caster"]->query_mana() < amt)
      amt = param["caster"]->query_mana();
   param["target"]->add_mana(amt);
   param["caster"]->add_mana(-amt);

   param["caster"]->practice_skill_conditional("magic.mana.spirit", 25, 1);
   param["caster"]->practice_skill_conditional("magic.technique.channeling", 25, 3);

   set_actor(param["caster"]);
   set_target(param["target"]);
   param["caster"]->msg_local("~[030~Targ ~vertrock backward as energy flows into ~objt from ~name.~CDEF");
   set_listener(param["caster"]);
   if(amt == 0) {
      msg_object(param["caster"], "~CACTYou channel your energy into ~targ but ~post magical reserves are full.~CDEF");
      msg_object(param["target"], "~CACTYou feel the magic pass through you like a wave of heat, leaving you refreshed and your magical reserves full.~CDEF");
   } else {
      msg_object(param["caster"],"~CACTYou healed ~targ for "+amt+" mana.~CDEF");
      msg_object(param["target"],"~CACTYou have been healed for "+amt+" mana.~CDEF");
   }
   return 1;
}
