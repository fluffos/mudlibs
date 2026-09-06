#include <magic.h>
#include <battle.h>

string query_name() { return "stun"; }

int query_cost() { return 25; }

int query_violent() { return 1; }

string query_type() { return "chaos"; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
string query_step_msg(mapping param) {
  switch( param["step"] ) {
    case 0:
      return "~Name ~verbclench ~poss left fist.";
    case 1:
      return "A faint purple glow surrounds ~npos hand.";
  }
  return "Oops!";
}
int query_level() { return 0; }
string query_step_skill(mixed param) {
	int step = param["step"];
  	return ({ "magic.mana.spirit",
			  "magic.technique.evoking",
			  "magic.mana.chaos" })[step % 3];
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  int check;
  object caster = param["caster"], target = param["target"];

  check = caster->skill_check("magic.mana.chaos", 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120);
  caster->msg_local("~[030~Name ~verbopen ~poss hand and a thin ray of purple light strikes ~targ!~CDEF");
  if( target->query_readiness() > 0 ) {
    target->msg_local("~CBRT~Name ~verbglow darkly as ~poss energy dissipates.~CDEF");
    target->add_readiness( (check+5) * -100 );
  } else
    target->msg_local("~CDEF~Name ~verbshrug off the effects of the beam.");
  return 1;
}
