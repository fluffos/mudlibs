#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE  "Apresuramiento"
#define NIVEL   3
#define ESCUELA ({"alteracion","wizwar"})
#define ESFERA  ({""})
string  CANCION ="'temporis ondele areba'";
#define SHADOW  SHADOWS+"haste_sh"

void setup() 
{
  set_spell_name(NAME);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo altera el tiempo en el objetivo. "
    " En particular, sera capaz de atacar con el doble de frecuencia, "
    "y cualquier hechizo arrojado sobre el tardara menos de lo normal. "
    "Los efectos duran 1 turno por cada 2 niveles del hechicero.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_slow_spell())
  {

    target->dispell_time_spell();
    return 1;
  }

  // Hay otro Apresurar ??
  if (target->query_time_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  // No tendria sentido =)
  if (target->query_hold_spell() || target->query_pacify_spell())
  {
    tell_object(caster,MSG_NO_PUEDO);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,"Sientes que tu pulso se acelera y pare que te mueves "
    "mucho mas rapido de lo que lo hacias.\n");
  tell_room(ENV(caster),caster->QCN+" hace gestos a "+target->QCN+
    ", los movimientos de este se aceleran.\n",({caster,target}));

  duration=fix_damage(caster,target,caster->QL*POWER);
  target->ATP("haste_on",1,duration);
  clone_object(SHADOW)->setup_shadow(target); 
  return NIVEL*100;
}
