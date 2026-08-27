// Guldan Jul'98

#define NOMBRE	"Reducir"
#define NIVEL	1
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({""})
#define	CANCION	"'groez us mior'"

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

  set_help_desc("Este hechizo reduce temporalmente el tamanyo de un objetivo.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int fuerza=caster->QL*target->query_str()/100;
  int duracion=10*caster->QL*POWER;
  string tmp1,tmp2;
  
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
  
  tell_object(find_living("guldan"),"\nREDUCIR: Caster: "+caster->QCN+
    ". Target: "+target->QCN+". Reduccion: "+fuerza+".\n");
  if (target->QP("reducido"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target->query_damage_bon()-fuerza<-POWER)
    fuerza=target->query_damage_bon()+POWER;

  if (fuerza<POWER) fuerza=POWER;

  switch (fuerza)
  {
    case 1..3:
      tmp1="y tu tamanyo disminuye ligeramente.\n";
      tmp2="y su tamanyo disminuye ligeramente.\n";
      break;
    case 4..6:
      tmp1="y tu tamanyo y tu masa muscular disminuyen considerablemente.\n";
      tmp2="y su tamanyo y su masa muscular disminuyen considerablemente.\n";
      break;
    case 7..1000:
      tmp1="y te transformas en un ser diminuto!\n";
      tmp2="y se transforma en un ser diminuto!\n";
      break;
  }
    
  if (target==caster)
  { 
    tell_object(target,"Formulas el hechizo "+NOMBRE+" sobre ti, "+tmp1);
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo, "+tmp2,target);
  }
  else
  {
    tell_object(target,caster->QCN+" formula un hechizo sobre ti, "+tmp1);
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre "
      +target->QCN+", "+tmp2,({target,caster}));
  }

  duracion=fix_damage(caster,target,duracion);
  target->adjust_tmp_damage_bon(-fuerza);
  target->ASP("reducido",fuerza);
  target->add_extra_look(TO);
  call_out("wear_off",duracion,target,fuerza);
  return NIVEL*100;
}

void wear_off(object target,int fuerza)
{
  if (target)
  {
    target->adjust_tmp_damage_bon(fuerza);
    tell_object(target,"Vuelves a tu tamanyo normal.\n");
    tell_room(ENV(target),target->QCN+" vuelve a su tamanyo normal.\n",target);
    target->remove_extra_look(TO);
    target->RSP("reducido");
  }
}

string extra_look()
{
  return "Su tamanyo es minusculo.\n";
}
