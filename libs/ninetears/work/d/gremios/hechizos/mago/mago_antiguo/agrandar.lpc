// Agrandar

#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Agrandar"
#define NIVEL	1
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({""})
#define	CANCION	"'groez us marj'"


void setup()
{
  set_spell_name("agrandar");
  set_school("alteracion");
  set_sphere("yvendur");
  set_spell_level(1);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo aumenta temporalmente el tamanyo de un objetivo."
                "Tan solo se puede ejecutar sobre el propio hechicero.\n");
  set_gp_cost(2);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int fuerza=caster->QL*target->query_str()/100+POWER;
  int duracion=10*caster->QL*POWER;
  string tmp1,tmp2;
  
 /* if(target != caster)
  {
    tell_object(caster,"Hechizo validos solamente para uso propio.\n");
    return -1;
  }
*/
  if (!target)
  {
    tell_object(caster,"No hay nadie aqui con ese nombre.\n");
    return -1;
  }
  
  if (target->QP("agrandado"))
  {
    tell_object(caster,"Tu objetivo ya esta afectado por este hechizo.\n");
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),caster->query_cap_name()+" comienza a formular un hechizo.\n",caster);
    tell_object(caster,"Comienzas a formular el hechizo Agrandar.\n");
  }
  
  switch (fuerza)
  {
    case 0:
      tmp1="pero no parece hacer ningun efecto.\n";
      tmp2="pero no se aprecia ningun efecto en el.\n";
      break;
    case 1..3:
      tmp1="y tu tamanyo aumenta ligeramente.\n";
      tmp2="y su tamanyo aumenta ligeramente.\n";
      break;
    case 4..6:
      tmp1="y tu tamanyo y tu masa muscular aumentan considerablemente.\n";
      tmp2="y su tamanyo y su masa muscular aumentan considerablemente.\n";
      break;
    case 7..1000:
      tmp1="y te transformas en un ser gigantesco!\n";
      tmp2="y se transforma en un ser gigantesco!\n";
      break;
  }
    
  if(target==caster)
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
  target->adjust_tmp_damage_bon(fuerza);
  target->ASP("agrandado",fuerza);
  target->add_extra_look(TO);
  call_out("wear_off",duracion,target,fuerza);
  return NIVEL*100;
}

void wear_off(object target,int fuerza)
{
  if (target)
  {
    target->adjust_tmp_damage_bon(-fuerza);
    target->remove_extra_look(TO);
    tell_object(target,"Vuelves a tu tamanyo normal.\n");
    tell_room(ENV(target),target->QCN+" vuelve a su tamanyo normal.\n",target);
    target->RSP("agrandado");
  }
}

string extra_look()
{
  return "Su tamanyo es descomunal.\n";
}
