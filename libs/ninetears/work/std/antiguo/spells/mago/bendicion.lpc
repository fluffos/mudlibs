#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Bendicion"
#define	ESCUELA	({"conjuracion","paladin"})
#define	ESFERA	({"total"})
#define	CANCION	"'bleiso umanos'"
#define	NIVEL	1

void setup()
{
  set_spell_name(NOMBRE);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo garantiza +1 a la probabilidad de dar "
     "durante una determinada duracion.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
	allow_on_ghosts(1); // bendecir a espiritus!
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int base,dur;

  if (wrong_alignment(caster))
  {
    punish_align(caster);
    return 0;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
 
  if (target->QP("bless_on"))
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
    tell_object(caster,"Formulas el hechizo bendicion en ti mismo.\n");
    tell_room(ENV(caster),(string)caster->QCN+
      " pronuncia el hechizo bendicion sobre "+caster->query_objective()+
      ".\n",caster);
  }
  else
  {
    tell_object(target,(string)caster->QCN+" te bendice.\n");
    tell_object(caster, "Te acercas a "+(string)target->QCN+
      " y formulas una bendicion sobre el.\n");
    tell_room(ENV(caster),(string)caster->QCN+
      " se acerca a "+target->QCN+" y formula un cantico.\n",
      ({target,caster}) );
  }

  base=5*POWER;
  dur=10*caster->QL*(POWER+1);
  target->adjust_tmp_tohit_bon(base);
  target->add_static_property("bless_on",1);

  call_out("wear_off",dur,target,base);
  return 0;
}

void wear_off(object target, int level)
{
  if(target)
  {
    target->adjust_tmp_tohit_bon(-level);
    target->remove_static_property("bless_on");
    tell_object(target, "Tu bendicion acaba.\n");
  }
}
