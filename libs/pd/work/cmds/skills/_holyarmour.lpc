
#include <std.h>
#include <effect_cl.h>

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 RES+"%^CYAN%^"
#define COL3 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

string *subs = ({ "monk", "paladin", "cleric" });

int spell() {
  object tp = this_player();
  if (member_array(tp->query_subclass(), subs) != -1 &&
      tp->query_skill("magic defense") >= 50)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <holyarmour [whom]>\n\n"
    "This prayer of the faithful can create a strong field of protection "
    "around someone's body. Its power is extremely dependent on the goodness "
    "of the user.",
    this_player() );
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
    FAIL("Pray for holy armour upon whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt->query_effect("holy armour"))
    FAIL( (tgt == tp ? "You are" : capitalize(tgt->query_subjective())+" is")+
          " already surrounded by holy armour.");

  if (tp->query_mp() < 100)
    FAIL("Not enough magic.");

  return 1;
}

int cmd_holyarmour(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, cost, def, align;
  int perc, numlimbs;
  string *limbs;
  string torso;
  class Effect armour;

  if (!spell()) return 0;

  if (!str || str == "me")
    tgt = tp;
  else
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  align = tp->query_alignment();
  def = tp->query_skill("magic defense") + tp->query_skill("faith")/3;
  time = tp->query_level()*4 +
         tp->query_stats("wisdom")*6 +
         random(tp->query_stats("intelligence"));

  cost = time + def;

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.");

  switch (def) {
    case -500 .. 100: def = 1; break;
    case  101 .. 150: def = 2; break;
    case  151 .. 200: def = 3; break;
    case  201 .. 250: def = 4; break;
    case  251 .. 300: def = 5; break;
    default: def = 6;
  }

  // align ranges 1500 to -1500, should be a minimum of 200 from alignment_ok()

  limbs = tgt->query_limbs();
  perc = align * 100 / 1400;
  numlimbs = sizeof(limbs) * perc / 100;

  while (sizeof(limbs) > numlimbs)
    limbs -= ({ limbs[random(sizeof(limbs))] });

  if (member_array((torso = tgt->query_torso()), limbs) == -1) {
    limbs -= ({ limbs[random(sizeof(limbs))] });
    limbs += ({ torso });
  }

  time += align / 10;

  align /= 300;
  if (align > 3*def)
    align = 3*def;

  def += align;

  message("magic", COL+"You mutter a prayer."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" mutters a prayer."+RES, env, tp);

  message("magic", COL2+"You are surrounded by a "+
                   COL3+"holy"+COL2+" force."+RES, tgt);
  message("magic", COL2+tgt->query_cap_name()+" is surrounded by a "+
                   COL3+"holy"+COL2+" force."+RES, env, tgt);

  tp->add_skill_points("magic defense", time/2);
  tp->add_mp(-cost);
  tp->set_magic_round(1);
  if (tp != tgt)
    tp->add_alignment(1+random(3));

  armour = new(class Effect);
  armour->name = "holy armour";
  armour->caster = tp;
  armour->castername = tp->query_name();
  armour->target = tgt;
  armour->desc = "You are surrounded by a holy protective force.";
  armour->endtime = time() + time;
  armour->endmessages = ({
    COL2+"The holy force around you fades away."+RES,
    COL2+"The holy force around "+tgt->query_cap_name()+" fades away."+RES,
  });
  armour->misc = ({ limbs, def });
  armour->endfunc = function(class Effect armour) {
    object tgt = armour->target;
    mixed *info = armour->misc;
    string *limbs = info[0];
    int def = info[1];

    foreach (string limb in limbs)
      tgt->add_magic_protection( ({ limb, -def, 0 }) );
  };

  foreach (string limb in limbs)
    tgt->add_magic_protection( ({ limb, def, 0 }) );

  tgt->add_effect(armour);

  return 1;
}

