#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Causar heridas "+CLASE
#define	TIPO	"magical"
string	CLASE	= "ligeras";
string	CORTES	= "menores";
mixed	ESCUELA	= ({"necromancia"});
mixed	ESFERA	= ({"danyadora"});
string	CANCION	= "'magius elis harmei'";
int	NIVEL	= 1;
int	NO_D	= 1;
int	SIZE_D	= 8;
int	BONUS	= 0;
#define	SALV	100

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Ninguna");
  set_help_desc("Con este hechizo, el sacerdote pone sus manos sobre una "
     "criatura y causa "+NO_D+"d"+SIZE_D+" + "+BONUS+" puntos de danyo de "
     "heridas "+CLASE+" u otros danyos. Para ello deberas tocar a tu objetivo. "
     "Si fallas al intentar tocarlo, la energia del hechizo es desperdiciada.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;

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

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target==caster)
  {
    tell_object(caster,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
    return -1;
  }

  if ((caster->query_thac0()-caster->query_tohit_bonus()-roll(1,150+50*POWER))<=target->query_total_ac())
  {
    target=check_melee_protector(target,caster);
    tell_object(target,caster->QCN+" se acerca a ti y te toca provocandote "
        "cortes "+CORTES+".\n");
    tell_object(caster, "Formulas "+NOMBRE+" y tocas a "+target->QCN+
        " causandole cortes "+CORTES+".\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo y toca a "+target->QCN+
        " causandole cortes "+CORTES+".\n",({target,caster}));
  } 
  else 
  {
    tell_object(target,caster->QCN+" se acerca a ti e intenta tocarte, pero falla.\n");
    tell_object(caster,"Formulas "+NOMBRE+" e intentas tocar a "+target->QCN+", fallando.\n");
    tell_room(ENV(caster),caster->QCN+" intenta tocar a "+target->QCN+", fallando.\n",
      ({target,caster}));
    return 1;
  }

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D)-BONUS);
  target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return 0;
}
