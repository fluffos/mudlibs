// Editado por Lummen 1996
// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

//#define	GRADO	( TP->query_sphere(query_sphere()))
#define GRADO 1
#define	BASE_R	( NIVEL*7+GRADO )
#define	DUR_R	( 10*NIVEL*GRADO )
string	NOMBRE	= "Resistencia mayor frio";
mixed	ESCUELA	= ({"resistencia"});
mixed	ESFERA	= ({"resistencia"});
string	CANCION	= "'marj corozev rissas'";
string	TIPO	= "frio";
int	NIVEL	= 7;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);

  set_help_desc("Este hechizo reduce el danyo infligido por los ataques base "
     "de "+TIPO+" en un "+BASE_R+"%. La duracion esta basada en el "
     "nivel del lanzador.");

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
    tell_object(caster, "Formulas el hechizo "+NOMBRE+" sobre ti mismo.\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre si mismo.\n",target);
  }
  else
  {
    tell_object(target,"Te sientes resistente a los ataques de "+TIPO+".\n");
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+(string)target->QCN+".\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo sobre "+target->QCN+".\n",({target,caster}));
  }
  
  level=caster->QL;
  resist=fix_damage(caster,target,BASE_R);
  dur=fix_damage(caster,target,DUR_R+level*NIVEL);
  
  target->ATP(TIPO,resist,dur);
  target->add_extra_look(TO);
  call_out("wear_off",dur,target);

  return NIVEL*100;
}

void wear_off(object target)
{
  if (target)
  {
     tell_object(target, "Sientes como la proteccion contra "+TIPO+" te abandona.\n");
	target->remove_property(TIPO);
     target->remove_extra_look(TO);
  }
}

string extra_look()
{
   string color="gris", cl="";
   
   switch (TIPO)
   {
      case "acido":
        color="amarilla";
	cl = "%^BOLD%^%^YELLOW%^";
        break;
      case "agua":
        color="azul";
	cl = "%^BOLD%^%^BLUE%^";
        break;
      case "aire":
        color="verde";
	cl = "%^BOLD%^%^GREEN%^";
        break;
      case "bien":
        color="blanca";
	cl = "%^BOLD%^";
        break;
      case "electrico":
        color="magenta";
	cl = "%^BOLD%^%^MAGENTA%^";
        break;
      case "enfermedad":
        color="naranja";
	cl = "%^ORANGE%^";
        break;
      case "frio":
        color="cyan";
	cl = "%^BOLD%^%^CYAN%^";
        break;
      case "fuego":
        color="roja";
	cl = "%^BOLD%^%^RED%^";
        break;
      case "magico":
        color="blanca";
	cl = "%^BOLD%^";
        break;
      case "mal":
        color="negra";
	cl = "%^BOLD%^%^BLACK%^";
        break;
	case "psionic":
      case "mental":
        color="blanca";
	cl = "%^BOLD%^";
        break;
      case "muerte":
        color="negra";
	cl = "%^BOLD%^%^BLACK%^";
        break;
      case "misiles":
        color="blanca";
	cl = "%^BOLD%^";
        break;
      case "tierra":
        color="marron";
	cl = "%^ORANGE%^";
        break;
      case "veneno":
        color="marron";
	cl = "%^ORANGE%^";
   }
   return "Le envuelve una brillante aura "+ cl + color+"%^RESET%^.\n";
}
