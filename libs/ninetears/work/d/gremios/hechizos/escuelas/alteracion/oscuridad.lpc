// Traducido por Lummen 4-9-97

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Oscuridad"
#define	ESCUELA	({"alteracion","wizwar"})
#define	ESFERA	({"sol"})
#define	NIVEL	1
#define	CANCION	"'maguis xeno lios'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo crea un foco de oscuridad, robando la luz "
    "alrededor del objetivo. Pudiendo ver en habitaciones donde la luz es intensa.\n");
  set_help_extras(0);
  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int luz,duration;
  
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,"El mundo parece oscuro a tu alrededor.\n");
  if (target==caster)
    tell_room(ENV(caster),(string)caster->QCN+" es oscurecido por un foco de oscuridad.\n",caster);
  else
  {
    tell_object(caster,"Pronincias el hechizo oscuridad sobre "+target->QCN+".\n");
    tell_room(ENV(caster),(string)caster->QCN+" invoca un foco de oscuridad sobre "+target->QCN+".\n",({target,caster}));
  }
  luz=fix_damage(caster,target,10*POWER+5);
  duration=fix_damage(caster,target,10*caster->QL*(POWER+1));
  target->adjust_light(-luz);
  call_out("wear_off",duration,target,luz);
  return NIVEL*10;
}

void wear_off(object target,int luz)
{
  if (target)
  {
    target->adjust_light(luz);
    tell_object(target,"Tu foco de oscuridad comienza a parpadear hasta desaparecer.\n");
    tell_room(ENV(target),"El foco de oscuridad de "+target->QCN+" desaparece.\n",target);
  }
}
