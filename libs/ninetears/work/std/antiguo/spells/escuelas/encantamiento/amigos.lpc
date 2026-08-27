// Guldan Ago'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE		"Amigos"
#define	ESCUELA		({"encantamiento"})
#define	ESFERA		({""})
#define	NIVEL		1
#define	LOCKOUT		"amigos_on"
#define	CANCION		"''"
#define	NO_D		2
#define	SIZE_D		4

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("caster");
  set_range(0);
  set_line_of_sight_needed(0);
  add_property_to_check(LOCKOUT);
  set_help_desc("Este hechizo aumenta temporalmente el carisma del hechicero.\n");
  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster,mixed target,mixed out_range,int time,int quiet)
{
  int duracion=fix_damage(caster,target,10*caster->QL*POWER);
  int bonus=roll(NO_D,SIZE_D)+POWER-2;

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }
  
  target->ATP(LOCKOUT,1,duracion);
  target->adjust_tmp_cha(bonus);
  target->add_extra_look(TO);
  call_out("wear_off",duracion,target,bonus);
}

void wear_off(object target,int bonus)
{
  if (target)
  {
    target->remove_extra_look(TO);
    target->adjust_tmp_cha(-bonus);
  }
}

string extra_look()
{
  return "Esta rodeado de un aura brillante.\n";
}
