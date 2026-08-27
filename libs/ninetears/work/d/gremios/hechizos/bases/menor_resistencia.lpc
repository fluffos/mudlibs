// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

//#define	GRADO	TP->query_sphere(query_sphere())
#define GRADO 1
#define	BASE_R	( 10*GRADO )
#define	DUR_R	( 10*NIVEL*GRADO )
string	NOMBRE	= "Menor resistencia a la magia";
mixed	ESCUELA	= ({"abjuracion","alteracion"});
mixed	ESFERA	= ({"proteccion"});
string	CANCION	= "'mior maycal resit'";
string	TIPO	= "magico";
int	NIVEL	= 5;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este hechizo reduce la resistencia a los ataques "
     "de "+tipo(TIPO)+" en un "+BASE_R+"% + 1% por cada  nivel del "
     "lanzador. La duracion esta basada en el nivel del lanzador.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int resist,level,dur;

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
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre ti mismo.\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo.\n",target);
  }
  else
  {
    tell_object(target,"Te sientes resistente a los ataques de "+tipo(TIPO)+".\n");
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+(string)target->QCN+".\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre "+target->QCN+".\n",({target,caster}));
  }
  
  resist=fix_damage(caster,target,-BASE_R-caster->QL)*(100-target->query_res(TIPO))/100;
  resist+=target->query_res(TIPO)/2;
  dur=fix_damage(caster,target,DUR_R+level*NIVEL);
  
  target->ATP(TIPO,resist,dur);
  target->add_extra_look(TO);
  call_out("wear_off",dur,target);

  return 0;
}

void wear_off(object target)
{
  if (target)
  {
     tell_object(target,"Tu resistencia contra "+tipo(TIPO)+" vuelve a su estado normal.\n");
     target->remove_extra_look(TO);
  }
}

string extra_look()
{
   string color="gris";
   
   switch (TIPO)
   {
      case "acid":
        color="amarilla";
        break;
      case "water":
        color="azul";
        break;
      case "air":
        color="verde";
        break;
      case "electrical":
        color="naranja";
        break;
      case "disease":
        color="naranja";
        break;
      case "cold":
        color="azul";
        break;
      case "fire":
        color="roja";
        break;
      case "magical":
        color="blanca";
        break;
      case "psionic":
        color="blanca";
        break;
      case "death":
        color="negra";
        break;
      case "missile":
        color="blanca";
        break;
      case "stone":
        color="marron";
        break;
      case "poison":
        color="marron";
   }
   return "Esta rodeado de una oscura aura "+color+".\n";
}
