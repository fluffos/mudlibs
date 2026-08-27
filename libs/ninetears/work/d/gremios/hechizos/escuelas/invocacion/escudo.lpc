// Guldan Ago'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Escudo"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
#define	NIVEL	1
#define LOCKOUT "ESCUDO_ON"
#define	CANCION	"'mior shield'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  add_property_to_check(LOCKOUT);
  set_help_desc("Este hechizo crea una barrera magica que protege al hechicero "
    "contra algunos tipos de proyectiles, ademas de mejorar la clase de armadura de este.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duracion=fix_damage(caster,target,10*caster->QL*POWER);
  int bonus1=fix_damage(caster,target,5*POWER+5);
  int bonus2=fix_damage(caster,target,caster->QL*POWER/2+1);

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,"Un escudo magico se forma delante de ti.\n");
  tell_room(ENV(target),"un escudo magico de proteccion envuelve a "+target->QCN+".\n",target);
  target->ATP(LOCKOUT,bonus1,duracion);
  target->adjust_tmp_ac(bonus1);
  target->ATP("missile",bonus2,duracion);
  target->add_extra_look(TO);
  call_out("wear_off",duracion,target,bonus1);
  return NIVEL*100;
}

void wear_off(object target,int bonus)
{
  if (target)
  {
    tell_object(target,"Tu "+NOMBRE+" se desvanece.\n");
    target->remove_extra_look(TO);
    target->adjust_tmp_ac(-bonus);
    target->RTP(LOCKOUT);
  }
}

string extra_look()
{
  return "Esta protegido por un escudo magico.\n";
}
