// Armadura
// Traducido por Lummen 3-7-97

#include <spells.h>
inherit BASE_SPELL;
#define BASE_AC		10*POWER
#define	PROPIEDAD	"armour_on"
#define	NOMBRE		"Armadura"
#define	ESCUELA		({"proteccion"})
#define	ESFERA		({""})
#define	NIVEL		1
#define	CANCION		"'mior armanis'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);

  set_help_desc("Este hechizo conjura una proteccion global como una armadura "
    "alrededor del objetivo, proporcionando una pequenyo bonus a la clase de "
    "armadura (ac). Su duracion depende del nivel del hechicero.");
  set_help_extras(0);

  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int bonus,duration;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
  
  if (target->query_property(PROPIEDAD))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

    tell_object(target,"Sientes una vaga sensacion de proteccion.\n");
  if (target==caster)
    tell_room(ENV(caster),"Un ligero brillo recubre la silueta de "+(string)caster->QCN+".\n",caster);
  else
  {
    tell_object(caster,"Formulas el hechizo "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),(string)caster->QCN+" realiza unos gestos que provocan en "+target->QCN+" la aparicion "
        "de un aura de luz a su alrededor.\n",({target,caster}));
  }

  bonus=fix_damage(caster,target,BASE_AC);
  duration=fix_damage(caster,target,10*caster->QL*POWER);

  target->adjust_tmp_ac_bon(bonus);
  target->add_extra_look(TO);
  target->ASP(PROPIEDAD,1);
  call_out("wear_off",duration,bonus,target);
  return NIVEL*100;
}

void wear_off(int bonus, object target)
{
  if(target)
  {
    target->adjust_tmp_ac_bon(-bonus);
    tell_object(target,"Te sientes mas vulnerable.\n");
    target->remove_extra_look(TO);
    target->RSP(PROPIEDAD);
  }
}

string extra_look()
{
  return "Esta rodeado de un aura brillante de luz oro.\n";
}
