#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Golpe de llama"
#define	NIVEL	5
#define	ESFERA	({"combate"})
#define	ESCUELA	({""})
#define	CANCION	"'flamious os colus'"
#define	TIPO	"fire"
#define	SALV	50
#define	SIZE_D	8
#define	NO_D	6

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(3);
  set_line_of_sight_needed(0);
  set_help_extras("Damage Type: "+tipo(TIPO)+"\nSaving Throw: 1/2");
  set_help_desc("This spell brings down a column of (un)holy flame upon your "
    "enemy. The damage caused is dependent upon the priesthood's "
    "combat sphere power. Also note only the most vengeful combat dieties "
    "will strike a victim who has run away.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;

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
    
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,caster->QCN+" brings down a pillar of flame upon you!\n");
  tell_object(caster, "You cast Flamestrike at "+target->QCN+".\n");
  tell_room(ENV(caster),(string)caster->QCN+" envelopes "+target->QCN+" in a pillar of flame!\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
  damage-=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100+damage;
}
