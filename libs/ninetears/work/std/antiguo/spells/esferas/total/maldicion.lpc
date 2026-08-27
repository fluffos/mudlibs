#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Maldicion"
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({"total"})
#define	CANCION	"'mali umanos'"
#define	NIVEL	1
 
void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo echa una maldicion que causa un -1 al dar "
    "al objetivo de forma temporal.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int base,dur;
 
  if (wrong_alignment(caster))
  {
    punish_align(caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
 
  if (target->QP("clericcursed"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
 
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
 
  if (target==caster)
  {
    tell_object(target,"Te maldices a ti mismo. Brillante idea!!\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre si mismo.\n",caster);
  }   
  else
  {
    tell_object(target, (string)caster->query_cap_name()+" te toca, echandote una maldicion!\n");
       
    tell_object(caster, "Tocas a "+
      (string)target->query_cap_name() + ", echandole una maldicion!\n");
       
    tell_room(ENV(caster),(string)caster->query_cap_name()+
      " toca a "+target->query_cap_name()+", echandole una maldicion.\n",
      ({target,caster}) );
  }
 
  base=3*POWER*caster->QL/10;
  dur=caster->QL*(POWER+1)*10;
 
  target->adjust_tmp_tohit_bon(-base);
  target->add_static_property("clericcursed", 1);
  target->attack_by(caster);
 
  call_out("wear_off",dur,target,base);
  return 0;
}
 
void wear_off(object target,int base)
{
  if (target)
  {
   target->adjust_tmp_tohit_bon(base);
   target->remove_static_property("clericcursed");
   tell_object(target, "Afortunadamente tu maldicion desaparece.\n");
  }
}
