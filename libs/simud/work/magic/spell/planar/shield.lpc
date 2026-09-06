#include <magic.h>
#include <battle.h>

//The messages are compliments of Sora

string query_name() { return "shield"; }

int query_cost() { return 30; }

string query_type() { return "wind"; }

int query_readiness_requirement() { return 1800; }

int query_num_steps() { return 7; }

string query_step_msg(mapping param) {
  switch (param["step"]) {
    case 0: return "~Name ~verbbegin whistling a low-pitched tune.";
    case 1: return "~Name ~verbclench a fist and ~verbbegin moving it in circles around ~poss head.";
    case 2: return "~Npos whistling tune starts changing pitch more dramatically. A small spinning dust cloud is created above ~poss hand.";
    case 3: return "~Npos left hand, while still spinning slowly, starts moving down until it points at ~targ. The cloud follows ~npos hand.";
    case 4: return "~Name ~verbstop moving ~poss hand, now pointing directly at ~targ. The cloud continues to grow.";
    case 5: return "~Name ~verbstop whistling, ending the tune with a stepwise downward-turning movement and a descending third to the supertonic. At the last note, the cloud moves toward ~targ.";
  }
   return 0;
}
int query_level() { return 1; }
string query_step_skill(mixed param) {
	int step = param["step"];
	if( step >= query_num_steps() )
		return "magic.mana.wind";
  	return ({ "magic.mana.wind",
		      "magic.technique.binding",
			  "magic.technique.abjuring",
			  "magic.mana.wind",
		      "magic.technique.binding",
			  "magic.technique.abjuring",
			  "magic.technique.binding" })[step];
}

string query_fail_msg(mapping param) {
   switch (param["step"]) {
      case 0: return "~Name ~verbtry whistling, but can't get the proper sounds out.";
      case 1: return "As ~name ~verbstart to raise a clenched fist into the air, ~pron ~verbhit ~poss chin.";
      case 2: return "~Name whistles more, but one note sounds off-key, and ~name ~verbis surrounded by dust.";
      case 3: return "~Name ~verbstart moving ~poss hand down, and ~verbrealize that ~pron ~verbis pointing in the wrong direction. Dust comes from everywhere and gets all over ~name.";
      case 4: return "~Name ~verbstop moving ~poss hand, but, too focused on whistling, ~pron ~verbdrop ~poss arm to ~poss side, and the dust gets all over ~poss leg.";
      case 5: return "~Npos whistling ends, but the last supertonic was missed. The dust cloud fizzles away settles to the ground in front of ~name.";
      case 6: return "As the cloud moves toward ~targ it gradually gains elevation until, when it gets to ~targ, it forms a cloud above ~poss head and disappears there.";
   }
   return "OOPS!";
}

int valid_target(mapping param) {
  object caster = param["caster"], target = param["target"];
  if ((environment(target) != environment(caster) &&
      environment(target) != caster) || !target->query_is_living())
    return 0;
  return 1;
}

varargs int on_cast(mapping param) {
  object ob;
  object caster = param["caster"], target = param["target"];
  caster->practice_skill_conditional("magic.mana.wind",50,6);

  set_actor(param["caster"]);
  set_target(param["target"]);
  param["caster"]->msg_local("~[030As the cloud gets to ~targ, it surrounds ~obje. Then, at an instant, it becomes transparent.~CDEF");

  ob = clone_object("/magic/obj/shield_object");
  ob->set_potency(20 + 25 * caster->skill_check("magic.technique.abjuring",25,50,75));
  ob->set_hp(20 + caster->skill_check("magic.mana.wind", 30, 60, 90) * 20 + caster->skill_check("magic.technique.binding", 60, 80) * 10);
  ob->protect(target);
  return 1;
}
