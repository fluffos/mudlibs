// Traducido por Lummen 1-7-97

#include <spells.h>
inherit BASE_SPELL;

#define TIPO	"fire"
#define	SALV	100
#define SIZE_D	4
#define	NOMBRE	"Meteoros diminutos"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
#define	NIVEL	3
#define	CANCION	"'miute pyros sphyes'"
#define	MAX_D	20

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(3);
  set_line_of_sight_needed(1);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Ninguna");
  set_help_desc("Este hechizo crea unas pequenyas bolas de fuego que le "
    "llueven a un solo objetivo. Cada bola produce 1d4 puntos de danyo. El "
    "caster crea 1 bola por cada nivel de experiencia.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,NO_D=MIN(MAX_D,caster->QL);

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(target,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }
    
  tell_object(target,caster->QCN+" te golpea con "+NO_D+" bolas en llamas.\n");
  tell_object(caster, "Golpeas a "+target->QCN+" con "+NO_D+" bolas en llamas.\n");
  tell_room(ENV(caster),target->QCN+" es golpeado por "+NO_D+" bolas en llamas.\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
