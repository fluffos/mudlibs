#include <magic.h>
#include <battle.h>

string query_name() { return "shock beam"; }
int query_cost() { return 60; }
int query_violent() { return 1; }
string query_type() { return "lightning"; }
int query_level() { return 2; }

int query_readiness_requirement() { return 500; }
int query_num_steps() { return 2; }
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
  int dc, check, zap;
  object caster = param["caster"], target = param["target"];

  dc = target->skill_check("magic.technique.evoking", 25, 50, 75) * 10 + target->query_stat("dex");
  wc = ([ "electricity" : 16 + 2*caster->skill_check("magic.mana.lightning",dc,dc+25,dc+50) ]);
  caster->msg_local("~[030A tongue of lightning arcs from ~npos palms, striking ~targ!~CDEF");
  zap = target->take_damage(wc)/5;
  target->add_held( max( zap, 1 ) );
  return 1;
}
