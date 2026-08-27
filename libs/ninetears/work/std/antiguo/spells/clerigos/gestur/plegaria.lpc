// Traducido por Spp

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Plegaria"
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({"yvendur"})
#define	CANCION	"'amenis unos baletis'"
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

  set_help_desc("Este hechizo proporciona a tu objetivo un bonus en el "
    "danyo y en la probabilidad de infringirlo durante una duracion "
    "limitada. Este hechizo es acumulable con el hechizo Bendicion.\n");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_property("prayer_on"))
  {
    tell_object(caster,MSG_AFECTADO);
    return 0;
  }
    
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
    
  if (target==caster)
  { 
    tell_object(target, "Formulas el hechizo "+NOMBRE+" sobre ti.\n");
    tell_room(ENV(caster),(string)caster->QCN+" formula el hechizo "+NOMBRE+" sobre si mismo.\n",TP);
  }
  else
  {
    tell_object(target, (string)caster->QCN+" te mira y "
      "formula un hechizo sobre ti, estas afectado por "+NOMBRE+".\n");
    tell_object(caster, "Miras a "+
      (string)target->QCN + " y formulas el hechizo "+
      NOMBRE+" sobre "+target->query_pronoun()+".\n");
    tell_room(ENV(caster),caster->QCN+" mira a "+
      target->QCN+"y formula el hechizo "+NOMBRE+".\n",
      ({target,caster}) );
  }
  
  target->add_static_property("prayer_on", 1);
  target->adjust_tmp_tohit_bon(10);
  target->adjust_tmp_damage_bon(1);
  target->adjust_salvation(10);

  call_out("wear_off",100+caster->QL*5,target);
  return NIVEL*100;
}

void wear_off(object target)
{
  if(target)
  {
    target->adjust_tmp_tohit_bon(-10);
    target->adjust_tmp_damage_bon(-1);
    target->adjust_salvation(-10);
    target->remove_static_property("prayer_on");
    tell_object(target, "Tu hechizo "+NOMBRE+" deja de hacerte efecto.\n");
  }
}
