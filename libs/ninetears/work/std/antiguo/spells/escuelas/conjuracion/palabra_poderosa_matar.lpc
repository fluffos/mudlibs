#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Palabra poderosa matar"
#define	ESCUELA	"conjuracion"
#define	ESFERA	"necromantica"
#define	NIVEL	9
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell kills the one you use it at; if the victim is "
    "powerful enough it may survive.");

  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You start to chant in a hissing, cursing tongue.\n");
  tell_room(ENV(caster),caster->QCN+" chants quietly in a hissing, cursing sound.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Your chanting becomes a vile, twisted shouting.\n");
  tell_room(ENV(caster),caster->QCN+"'s chant grows louder, into a foul, twisted shout.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You cut off abruptly, a pall of silence drops over the area.\n");
  tell_room(ENV(caster),caster->QCN+" cuts off abruptly and an ominous silence fills the air.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int skill;
  int check;
  int cost;
  int c_roll, t_roll;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    tell_room(ENV(caster),caster->QCN+" looks very confused and curses.\n",caster);
    return -1;
  }

  if (target->query_creator())
  {
    tell_object(caster,"You don't think it is wise to kill an immortal.\n");
    tell_room(ENV(caster), caster->QCN+" looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster,(string)target->QCN+" is already dead.\n");
    tell_room(ENV(caster), caster->QCN+" looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster,"You don't feel like harming "+target->QCN+", seeing how peaceful "+target->query_pronoun()+" is.\n");
    return -1;
  }

  /* here is the "saving throw" I'm trying out */

  c_roll = random( (int)caster->query_level() * (int)caster->query_wis() + 5 );
  t_roll = (int)target->query_level() * (int)target->query_wis();
  if ( c_roll*((100-(int)target->query_property("magical")) / 100 ) < t_roll )
  {
    tell_object(target, "You hear "+(string)caster->QCN+" whisper death to you through the silence.\n");
    tell_object(caster,"Your word comes out only as a whisper.\n");
    tell_room(ENV(caster),caster->QCN+" whispers something into the silence to "+target->QCN+".\n",caster);
    caster->attack_ob(target);
    return 0;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(ENV(caster),"The Gods step in to save the life of "+target->QCN+" who is harmless.\n");
    return 0;
  }

  tell_object(caster,"You shout into the sudden silence: DIE "+target->QCN+"!\nYou call upon the gods to help you kill "+target->QCN+".\n");
  tell_room(ENV(caster),caster->QCN+" shouts in the sudden silence: DIE "+target->QCN+"!\n",caster);
  tell_object(target,"You feel "+caster->QCN+"'s word attack you.\nThe powerword killed you.\n");
  target->do_death(caster);
  return 0;
}
