#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Sex Change"
#define	NIVEL	7
#define	ESFERA	({"total"})
#define	ESCUELA	({""})
#define	CANCION	"'switchum changeum'"
#define	TIPO	"laughter"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("This powerful enchantment calls upon the power "
    "of your diety to change the sex of a target.  "
    "Due to its nature, its very taxing on the caster, "
    "and even the highest priests must meditate for days "
    "to cast it.  No guarantee is made that the sexual urges of the "
    "target will change too, of course.");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"A nimbus of power forms in front of you.\n");
  tell_room(ENV(caster),"A nimbus of power forms in front of "+caster->QCN+".\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target->query_gender()==1)
  {
    tell_object(caster, "You shape the nimbus of power into a huge, glimmering pair of gardening shears.\n");
    tell_room(ENV(caster), caster->QCN+" gestures, and the nimbus of power molds into a pair of...\ngardening shears?\n", caster);
  }
  else
  {
    tell_object(caster, "You form the nimbus of power into something rather phallic, and best not described here.\n");
    tell_room(ENV(caster), caster->QCN+" shapes the nimbus of power into something indescribably phallic.\n", caster);
  }
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target->query_alive() || !living(target))
  {
    tell_object(caster,"Sex is irrelevant to that.\n");
    tell_room(ENV(caster),caster->QCN+" stops casting.\n",caster);
    return 0;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return 0;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  target->set_gender((target->query_gender()==1?2:1));
  if (target->query_gender()==1)
  {
    if (target!=caster)
      tell_object(caster,"You send the.. nimbus.. hurling at "+
        target->QCN+".\nThere's a large flash, a scream, and "
        "suddenly "+target->QCN+" is a new man.\n");

    tell_object(target,"The phallic nimbus suddenly hurtles toward you, "
      "and you scream as a very \nfundamental change comes over you.\n");
    tell_room(ENV(caster), caster->QCN+
      " gestures, and the phallic nimbus hurtles toward "+
      target->QCN+".\nA flash of light, and a scream, and "
      "you notice some change in "+target->QCN+".\n",
      ({ target, caster }) );
  }
  else
  {
    tell_object(target, "The glowing shears of power hurtle at you, "
      "ripping through your armor and \nsuddenly exploding.\n"
      "You feel something missing...\n");
    if ( target != caster )
      tell_object(caster, "You send the glowing shears of power "
        "at "+target->QCN+", who screams and suddenly \nlooks "
        "to have lost something vital.\n");
    tell_room(ENV(caster), caster->QCN+" gestures, "
      "and the shears of power hurtle at "+target->QCN+
      ", who is \nenveloped screaming in bright light.\n"
      "When the light fades, "+target->QCN+
      " appears to have lost something vital.\n",
      ({ target, caster }) );
  }
  return 0;
}
