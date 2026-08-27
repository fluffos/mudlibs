// Guldan Jun'98
// Pasado a hechizo por Paris. Nov'98

#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Fuerza"
#define	ESCUELA	({"alteracion","wizwar"})
#define	ESFERA	({""})
#define	CANCION	"'fuere magnus increments'"
#define NIVEL	2
#define	MCN	me->query_cap_name()
#define	HCN	him->query_cap_name()
#define STR     target->query_str()
#define PROPIEDAD "hechizo_fuerza"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo incrementa la fuerza del objetivo segun sea "
                "su gremio y habilidad del hechicero.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration=fix_damage(caster,target,10*POWER*caster->QL);
  object guild=target->query_guild_ob();
  int STR_BON=0;
  int extra=0;
  
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
  
  if (target->QP(PROPIEDAD))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (guild) switch (guild->query_base())
  {
    case "luchador":
    case "wizwar":
      STR_BON=roll(1,8);
     break;
    case "sacerdote":
    case "bribon":
      STR_BON=roll(1,6);
     break;
    case "hechicero":
      STR_BON=roll(1,4);
     break;
  }
  else STR_BON=roll(1,4);

  if (guild) extra=10*guild->query_extr_str();
  if (STR>(17+extra)) STR_BON=0;
  else if (STR+STR_BON>(18+extra)) STR_BON=18+extra-STR;
  target->ASP(PROPIEDAD,1);
  tell_object(target,"Notas como tus musculos crecen en volumen.\n");
  tell_object(caster,"Ves como, al acabar tu hechizo, los musculos de "+
                      target->query_cap_name()+" crecen espectacularmente.\n");
  tell_room(ENV(target),"Un hechizo de "+caster->QCN+" hace que los musculos de "+
                        target->QCN+" crezcan de forma espectacular.\n",({caster,
                        target}) );    
  call_out("wear_off",duration,STR_BON,target);
  target->adjust_tmp_str(STR_BON);
  return NIVEL*100;
}

void wear_off(int bonus, object target)
{
  if (target)
  {
    target->adjust_tmp_str(-bonus);
    tell_object(target,"Te sientes mas vulnerable.\n");
    target->remove_extra_look(TO);
    target->RSP(PROPIEDAD);
  }
}

string extra_look()
{
  return "Sus musculos estan aumentados mediante la magia.\n";
}
