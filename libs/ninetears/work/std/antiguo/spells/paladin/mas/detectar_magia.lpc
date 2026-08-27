// Traducido por Lummen 4-9-97

#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE "Detectar magia"
#define	ESCUELA	({"adivinacion"})
#define	ESFERA	({"adivinacion"})
#define	NIVEL	1
#define	CANCION	"'magius is iseio'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("item");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo es usado para determinar si un objeto es de naturaleza "
    "magica o no. El brillo del objeto magico da al hechicero una idea de lo "
    "poderoso que resulta este. Este hechizo debe ser formulado con el objeto "
    "o npc (en el caso de que se desee conocer las auras magicas) "
    "para trabajar con el.");
  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

string powerp(int level,object ob,string str,string show)
{
  string temp;
  
  switch (ob->QP(str))
  {
    case -399..-1:
      temp="Una aura negra de ";
      break;
    case 0:
      return "";
    case 1..10:
      temp="Una tenue aura ";
      break;
    case 11..30:
      temp="Un definida aura ";
      break;
    case 31..50:
      temp="Un firme aura ";
      break;
    case 51..80:
      temp="Una solida aura ";
      break;
    case 81..99:
      temp="Un blindada aura ";
      break;
    case 100..399:
      temp="Una poderosa esfera ";
      break;
    default:
      temp="Un aura ";
  }
  temp+=show+" ";

  if (level>15)
  {
    switch (ob->query_time_remaining(str))
    {
      case 0:
        temp += "y es permanente.";
        break;
      case 1..10:
        temp += "aparecen signos de fallo inminente.";
        break;
      case 11..100:
        temp += "parece un poco inestable.";
        break;
      case 101..500:
        temp += "parece bastante estable.";
        break;
      case 501..2000:
        temp += "no aparecen signos de romperse pronto.";
        break;
      default:
        temp + "y lo ves bastante solido por mucho tiempo.";
    }
  }
  return temp+".\n";
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string es;
  int level=caster->QL;
  
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return 0;
  }
 
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C,caster);
  }

  if (living(target))
  {
    tell_object(caster,"Observas detenidamente a "+(string)target->QCN+
      " y parece ser circundado por:\n"+
      "%^GREEN%^"+powerp(level,target,"poison","verde")+
      "%^WHITE%^%^BOLD%^"+powerp(level,target,"magical","plateada")+"%^RESET%^"+
      "%^RED%^"+powerp(level,target,"fire","vermellon")+
      "%^BLUE%^"+powerp(level,target,"cold","azul")+
      "%^YELLOW%^"+powerp(level,target,"acid","amarilla")+
      "%^MAGENTA%^"+powerp(level,target,"electrical","magenta")+
      "%^CYAN%^"+powerp(level,target,"air","cian")+
      "%^BOLD%^%^BLACK%^"+powerp(level,target,"stone","gris")+
      "%^ORANGE%^"+powerp(level,target,"disease","naranja")+
      "%^BOLD%^%^CYAN%^"+powerp(level,target,"water","azul claro")+
      "%^BOLD%^%^WHITE%^"+powerp(level,target,"good","blanca")+
      "%^BOLD%^%^BLACK%^"+powerp(level,target,"evil","negra oscura")+
      "%^BOLD%^%^BLACK%^"+powerp(level,target,"death","negra parduzca")+
      "%^BOLD%^%^WHITE%^"+powerp(level,target,"missile","blanca fuerte")+
      "%^BOLD%^%^BLACK%^"+powerp(level,target,"psionic","fuerza mental")+
      "%^RESET%^"+
      powerp(level,target,"SPIRIT_ARMOUR_PROPERTY","armour")+".\n");
   if(target!=caster)
     tell_object(target, caster->QCN+" parece estar observando algo en ti detenidamente.\n");
  }
  else if (stringp(es=target->enchant_string()) && strlen(es))
    tell_object(caster, "Miras detenidamente buscando auras magicas...\n"+es+"\n");
  else 
    tell_object(caster,"Hmmm, no puedes hablar demasiado sobre esto.\n");
  return NIVEL*3;
}
