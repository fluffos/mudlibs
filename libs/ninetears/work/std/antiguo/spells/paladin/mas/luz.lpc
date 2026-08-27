// Traducido por Lummen 5-9-97

#define NOMBRE	"Luz"
#define	ESCUELA	"tiempo"
#define	ESFERA	""
#define NIVEL	1
#define CANCION	"'magius lios'"

#include <spells.h>
inherit BASE_SPELL;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo crea luz a traves de ti o un objetivo "
    "para ver en habitaciones oscuras.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
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
    tell_object(target,MSG_CAN_C);
  }
    
  if(target==caster)
  { 
    tell_object(target,"Formulas el hechizo "+NOMBRE+" sobre ti mismo.\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo.\n",target);
  }
  else
  {
    tell_object(target,caster->QCN+" formula un hechizo sobre ti.\n");
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre "+target->QCN+".\n",({target,caster}));
  }
  luz=fix_damage(caster,target,10*POWER+10);
  duration=fix_damage(caster,target,10*caster->QL*(POWER+1));
  target->adjust_light(luz);
  call_out("wear_off",duration,target,luz);
  return NIVEL*100;
}

void wear_off(object target,int luz)
{
  if (target)
  {
    target->adjust_light(-luz);
    tell_object(target,"Tu foco de luz desaparece.\n");
    tell_room(ENV(target),"El foco de luz de "+target->QCN+" desaparece.\n",target);
  }
}
