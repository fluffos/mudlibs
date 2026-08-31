
#include <std.h>
#include <effect_cl.h>
#include <damage_types.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^YELLOW%^"
#define COL3 RES+"%^CYAN%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "paladin" &&
      tp->query_skill("magic defense") >= 20*4 &&
      tp->query_skill("faith") >= 20*4)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <radiance [whom]>\n\n"
    "A prayer which surrounds someone in protective light. "
    "This cloak of light protects against the darkness figuratively "
    "and literally, providing both light to see by and a resistance "
    "against unholy attacks.",
    this_player()
  );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your prayers go unheard.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if (!tgt)
    FAIL("Surround whom in a cloak of light?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt->query_alignment() <= -300)
    FAIL(capitalize(tgt->query_subjective())+" is much too evil to receive "
	 "a cloak of light!");

  if (tp->query_recast("radiance"))
    FAIL("You are already maintaining a cloak of light.");

  if (tp->query_mp() < 125)
    FAIL("Not enough magic.");

  return 1;
}

int cmd_radiance(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, cost, def, align, light, resist;
  class Effect rad;
  class Effect radcast;

  if (!spell()) return 0;

  if (!str || str == "me")
    tgt = tp;
  else
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  align = tp->query_alignment();
  light = align/200 + random(2);
  def = to_int(BALANCE3_D->diminishing_returns(
    // note: the -155 depends on caster having combined md + faith of 160+!!
    // if this spell's reqs or paladin skill maxes change, change this number
    (tp->query_skill("magic defense") + tp->query_skill("faith") - 155),
    0.08
  ));
  if (def < 1) def = 1;
  resist = to_int(15 + BALANCE3_D->diminishing_returns(
    tp->query_skill("faith")-80 + align/60,
    5
  ));
  time = (
    tp->query_stats("wisdom")*7 +
    tp->query_skill("magic defense") +
    random(30)
  );
  cost = time/3 + resist*2;

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.");

  message("magic", COL+"You mutter a prayer."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" mutters a prayer."+RES, env, tp);

  message("magic", COL3+"A "+COL2+"cloak"+COL3+" of "+COL2+"light"+COL3+
    " surrounds you."+RES, tgt);
  message("magic", COL3+"A "+COL2+"cloak"+COL3+" of "+COL2+"light"+COL3+
    " surrounds "+tgt->query_cap_name()+".",
    env, tgt
  );

  tp->add_skill_points("magic defense", tp->query_level());
  tp->add_skill_points("faith", tp->query_level());
  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->set_recast("radiance", time()+time);
  if (tp != tgt)
    tp->add_alignment(2+random(2));

  rad = new(class Effect);
  rad->name = "radiance";
  rad->caster = tp;
  rad->castername = tp->query_name();
  rad->target = tgt;
  rad->desc = "A cloak of light protects you from dark forces.";
  rad->interval = 1;
  rad->endtime = time() + time;
  rad->endmessages = ({
    COL3+"The cloak of light vanishes."+RES,
    COL3+"The cloak of light surrounding "+
      tgt->query_cap_name()+" vanishes."+RES,
  });
  rad->misc = ({ light, def, resist, tgt->query_property("light") });
  rad->func = function(class Effect rad) {
    // every heartbeat, adjust light to match environment
    object tgt = rad->target;
    int rad_light = rad->misc[0];
    int orig_light = rad->misc[3];
    int eff_light, new_light;
    int ideal = 2;

    if (!tgt) return;

    tgt->remove_property("light");
    tgt->set_property("light", orig_light);

    new_light = 0;

    // needed until we have a func to do effective_light without
    // sight bonus modification:
    while (effective_light(tgt) < ideal && new_light <= rad_light) {
      new_light++;
      tgt->remove_property("light");
      tgt->set_property("light", orig_light + new_light);
    }
  };
  rad->endfunc = function(class Effect rad) {
    object caster = rad->caster;
    object tgt = rad->target;
    mixed *info = rad->misc;
    int light = info[0];
    int def = info[1];
    int resist = info[2];
    int orig_light = info[3];

    if (caster) caster->set_recast("radiance", 0);

    if (!tgt) return;

    tgt->remove_property("light");
    tgt->set_property("light", orig_light);

    tgt->add_resistance_bonus(DAMAGE_UNHOLY, -resist);

    tgt->add_magic_protection( ({ 0, -def, 0 }) );
  };

  /* actually, let the func above do this
  light += tgt->query_property("light");
  tgt->remove_property("light");
  tgt->set_property("light", light);
  */

  tgt->add_resistance_bonus(DAMAGE_UNHOLY, resist);

  tgt->add_magic_protection( ({ 0, def, 0 }) );

  tgt->add_effect(rad);

  // this chunk is so one person can maintain only one casting of radiance
  // at a time, but if their target logs out, the caster will get updated so
  // they can cast it again
  if (tp != tgt) {
    radcast = new(class Effect);
    radcast->name = "radiance";
    radcast->caster = tp;
    radcast->castername = tp->query_name();
    radcast->target = tgt;
    radcast->desc =
      "You are maintaining a cloak of light around "+tgt->query_cap_name()+".";
    radcast->interval = 1;
    radcast->endtime = time() + time;
    radcast->func = function(class Effect radcast) {
      object tp = radcast->caster;
      object tgt = radcast->target;
      if (tp && !tgt)
	radcast->endtime = time()-2;
    };
    radcast->endfunc = function(class Effect radcast) {
      object tp = radcast->caster;
      if (tp) tp->set_recast("radiance", 0);
    };

    tp->add_effect(radcast);
  }

  return 1;
}

