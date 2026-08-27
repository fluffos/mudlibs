#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Thorn Foot"
#define	NIVEL	2
#define	ESCUELA	({""})
#define	ESFERA	({""})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(2);

  set_help_desc("This spell will place a thorn unerringly into an opponent's "
    "foot.  The bethorned victim will suffer damage when trying to move "
    "until such a time as they remove the affliction at great pain to "
    "themselves.  Won't have much effect on an NPC.");

  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You draw in power from the world for your enchantment.\n");
  tell_room(ENV(caster), caster->QCN+" goes into an odd trance-like state.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"A very sharp looking thorn appears in the air before you.\n");
  tell_room(ENV(caster),"A very sharp looking thorn appears in the air before "+caster->QCN+".\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object thorn;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    tell_room(ENV(caster),caster->QCN+" comes out of the trance, points a finger, and the thorn lodges itself into a nearby rock.\n",caster);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,"You come out of the trance and guide the thorn to "+
      target->QCN+"'s foot.\n");
    tell_object(target, caster->QCN+" comes out of the trance "
      "and points at you.\n\nThe thorn comes streaking toward you and "
      "lodges itself deeply into your foot!\n\nYou scream in pain.\n");
    tell_room(ENV(caster), "The thorn suddenly streaks toward "+
      target->QCN+" and lodges itself in "+
      target->query_possessive()+" foot.\n\n"+target->QCN+
      " howls in pain.\n",target);
  }
  target->adjust_hp(-random(10),caster);
  thorn=clone_object(OBJETOS+"thorn");
  thorn->move(target);
  thorn->reset_drop();
  thorn->reset_get();
  thorn->set_spell(target);
  target->attack_by(caster);
  return 0;
}
