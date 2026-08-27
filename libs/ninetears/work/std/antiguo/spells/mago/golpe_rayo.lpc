// Traducido por Lummen 4-9-97

#include <spells.h>
inherit BASE_SPELL;

#define TIPO	"electrico"
#define	SALV	50
#define SIZE_D	6
#define	MAX_D	10
#define	NOMBRE	"Golpe de rayo"
#define	ESCUELA	"conjuracion"
#define	ESFERA	""
#define	NIVEL	3
#define	CANCION	"'xlxyx de gadrum'"

void setup() 
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(4);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Este hechizo provoca un ataque a un solo objetivo con un "
    "rayo electrico. El danyo provocado es (nivel del hechicero)d6. Con un "
    "maximo de 10d6.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_D=MIN(MAX_D,caster->QL);

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  { 
    tell_object(caster,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
    return -1;
  }

  if (target->QP("invulnerable_hechizos")>=NIVEL)
  {
    tell_object(caster,"Tu hechizo no tiene efecto en "+target->QCN+".\n");
    tell_room(ENV(caster),"El hechizo de "+caster->QCN+" no tiene efecto en "
      +target->QCN+".\n",({caster,target}));
    return -1;
  }
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
    
  tell_object(target,(string)caster->QCN+" te electrocuta con un relampago.\n");
  tell_object(caster,"Electrocutas a "+(string)target->QCN+" con un relampago.\n");
  tell_room(ENV(caster),(string)caster->QCN+" formula un hechizo y "+target->QCN+" es electrocutado "
    "con un relampago.\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
