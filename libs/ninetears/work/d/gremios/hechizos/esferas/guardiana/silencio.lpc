#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Silencio"
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({"guardiana"})
#define	CANCION	"'solus paqua quietum'"
#define	NIVEL	2

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo hace que el objetivo no pueda hablar, gritar, "
                "o cualquier otra cosa que use sus cuerdas vocales. Lo mas "
                "importante, es que el objetivo no podra formular hechizos. "
                "Este hechizo dura dos turnos por nivel del hechizero.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_silence_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }
        
  if (((caster->query_int()+caster->query_wis())/2)<random(target->QL))
  {
    tell_room(ENV(caster),caster->QCN+" termina de formular el hechizo, pero no ocurre nada.\n",({target,caster}));
    tell_object(target, caster->QCN+" termina el hechizo, y te mira fijamente preguntandose porque no te ocurre nada.\n");
    tell_object(caster, "Terminas de formular el hechizo, pero aparentemente a "+target->QCN+" no le ha ocurrido nada.\n");
  }
  else
  {
    ob=clone_object(SHADOWS+"silence_sh");
    ob->setup_shadow(target);
    target->add_extra_look(ob);
    target->ATP("silence_on",1,caster->QL*MAX(POWER,1));
    target->ATP("nocast",1,caster->query_level()*MAX(POWER,1));

    tell_room(ENV(caster),caster->QCN+" hace unos gestos y "+target->QCN+" grita silenciosamente.\n",({caster,target}));
    tell_object(caster,"Tu silencias a "+target->QCN+", y "+target->query_pronoun()+" te grita silenciosamente.\n");
    tell_object(target,caster->QCN+" te hace unos gestos sobre su cuello y no puedes decir nada!!!\n");
  }
  if (!interactive(target)) target->attack_by(caster);
  return 0;
}
