// Reducir
// Guldan Jul'98
// Paris. Nov'98 - Ligeramente cambiado para los M/G

#define NOMBRE	"Debilitar"
#define NIVEL	1
#define	ESCUELA	({"alteracion","wizwar"})
#define	ESFERA	({""})
#define	CANCION	"'deslade non carme fuere'"

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

  set_help_desc("Este hechizo reduce temporalmente la fuerza del objetivo, "
    "asi como su capacidad para pegar y danyar en combate.\n");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int fuerza=caster->QL*target->query_str()/200;
  int duracion=15*caster->QL;
  string tmp1,tmp2;
  
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
  
  if (target->QP("debilitado"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
  
  switch (fuerza)
  {
    case 0:
      tmp1="pero no parece hacer ningun efecto.\n";
      tmp2="pero no se aprecia ningun efecto en el.\n";
      break;
    case 1..3:
      tmp1="y te sientes ligeramente debilitado.\n";
      tmp2="y se siente ligeramente debilitado.\n";
      break;
    case 4..6:
      tmp1="y tu fuerza disminuye considerablemnte.\n";
      tmp2="y su fuerza disminuye considerablemnte.\n";
      break;
    case 7..1000:
      tmp1="y te sientes tan debilitado que apenas puedes moverte !\n";
      tmp2="y se siente tan debilitado que apenas puede moverse !\n";
      break;
  }
    
  if (target==caster)
  { 
    tell_object(target,"Formulas el hechizo "+NOMBRE+" sobre ti, "+tmp1+".\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo, "+tmp2,target);
  }
  else
  {
    tell_object(target,caster->QCN+" formula un hechizo sobre ti, "+tmp1);
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo sobre "
      +target->QCN+", "+tmp2,({target,caster}));
  }
//  tell_object(find_player("paris"),"FUERZA: "+fuerza+".\n");
  duracion=fix_damage(caster,target,duracion);
  target->adjust_tmp_damage_bon(-fuerza);
  target->ATP("debilitado",fuerza,duracion);
  call_out("wear_off",duracion,target,fuerza);
  return 0;
}

void wear_off(object target,int fuerza)
{
  if (target)
  {
    target->adjust_tmp_damage_bon(fuerza);
    tell_object(target,"Recuperas tu vigorosidad.\n");
    tell_room(ENV(target),target->QCN+" recupera su estado de forma normal.\n",target);
    target->RTP("debilitado");
  }
}
