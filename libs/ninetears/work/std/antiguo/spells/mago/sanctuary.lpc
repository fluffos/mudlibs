#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Santuario"
#define	NIVEL	3
#define	ESCUELA	({""})
#define	ESFERA	({"proteccion","paladin"})
#define	CANCION	"'prot me'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este hechizo crea un aura magica que rodea al hechicero "
  "y fuerza a todo aquel que le ataque a pasar una tirada de salvacion "
  "para que el hechicero no ignore el ataque. Mientras se este afectado "
  "por este hechizo no se puede atacar a nadie.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;

  if (target!=caster)
  {
    tell_object(caster,"Solo puedes utilizar el hechizo sobre ti.\n");
    return -1;
  }

  if (target->query_sanc())
  {
    tell_object(target,MSG_AFECTADO);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster, "Terminas el hechizo para que una aura azulada "
    "aparezca y te rodee. Ahora te sientes protegido y tus acciones son "
    "armoniacas y serenas.\n");
    tell_room(ENV(caster),caster->query_cap_name()+" es rodeado por "
    "un aura de proteccion color azul que irradia armonia.\n", caster); 
  }

  shadow=clone_object(SHADOWS+"sanctuary_sh");
  shadow->setshadow(caster);
  call_out("wear_off",100+caster->QL*10,caster);
  return 0;
}

void wear_off(object target)
{
  if (target)
  {
    target->destruct_sanct_shadow();
    tell_object(target,"El efecto del hechizo Santuario desaparece.\n");
  }
}
