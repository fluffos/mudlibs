#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Piedra a carne"
#define	ESCUELA	({"alteracion","elemental tierra"})
#define	ESFERA	({"hechizo"})
#define	NIVEL	6
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("Este hechizo invierte el efecto del hechizo Carne a Piedra.\n");
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

  if (!target->query_stone_spell())
  {
    tell_object(caster,"El no es una estatua, creo que el hechizo no sirve con el.\n");
    return -1;
  }

  if (random(target->query_res("magical"))>10)
  {
    tell_object(caster,"Tu hechizo falla.\n");
    tell_object(target,"Una rafaga de viento helado te golpea, lo cual hace que te endurezcas mas en tu forma de estatua.\n");
    target->ATP("stoned",1,200);
    return -1;
  }

  tell_object(caster,"Formulas el hechizo Piedra a Carne sobre "+target->QCN+".\n");
  tell_object(target,"Sientes como una confortable brisa te atrapa y hace que tu piel vuelva a ser carne.\n");
  tell_room(ENV(caster),"Los ojos de "+caster->QCN+" brillan intensamente "
    "con una luz verde sobre "+target->QCN+", y de pronto la luz hace que "
    "se desprendan de el la roca que le cubria, volviendo asi a su forma "
    "normal.\n",({caster,target}));
  target->dispell_stoned();
  return 0;
}
