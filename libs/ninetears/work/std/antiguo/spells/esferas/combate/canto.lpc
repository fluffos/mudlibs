#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Canto de Batalla"
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({"combate"})
#define	CANCION	"'acerbace unos baletis'"
#define	NIVEL	3

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo provoca una penalizacon al ataque en "
  "combate y al danyo durante la duracion del hechizo. Este hechizo "
  "es acumulativo con el Maldicion.\n");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (wrong_alignment(caster))
  {
    punish_align(caster);
    return -1;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }
 
  if (target->query_property("chant_on"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
 
  if (target==caster)
  {
    tell_object(caster,"Formulas el canto sobre ti mismo, no entiendes "
    "para que la verdad...\n");
    tell_room(ENV(caster),(string)caster->QCN+
      " convoca el "+NOMBRE+" sobre si mismo.\n");
  }
  else
  { 
    tell_object(target,caster->QCN+" formula el "+NOMBRE+" sobre ti.\n");
    tell_object(caster,"Formulas el "+NOMBRE+" sobre "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" formula el "+NOMBRE+" sobre "+target->QCN+" invadiendole con un horrible canto.\n",({target,caster}));
  }
 
  target->ASP("chant_on", 1);
  target->adjust_tmp_tohit_bon(-10);
  target->adjust_tmp_damage_bon(-1);
  target->adjust_salvation(-10);
  target->attack_by(caster);
  call_out("wear_off",200+(caster->QL*5),target);
  return NIVEL*100;
}
 
void wear_off(object target)
{
  if (target)
  {
    target->adjust_tmp_tohit_bon(10);
    target->adjust_tmp_damage_bon(1);
    target->adjust_salvation(10);
    target->RSP("chant_on");
    tell_object(target,"El "+NOMBRE+" deja de hacer efecto.\n");
  }
}
