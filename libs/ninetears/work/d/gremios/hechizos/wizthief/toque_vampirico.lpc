/*** Traducido por Lummen 3-9-97 ***/

#include <spells.h>
inherit BASE_SPELL;

#define TIPO	"evil"
#define	SALV	100
#define SIZE_D	6
#define MAX_D   8
#define	NOMBRE	"Toque vampirico"
#define	ESCUELA	({"necromancia","wizwar"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	3
#define	CANCION	"'gimme ye helth'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Ninguna");
  set_help_desc("Este hechizo permite al hechicero robarle puntos de vida a "
    "un objetivo y transmitirselos a si mismo. Solo podra transferirse la mitad "
    "de los puntos de vida robados. El maximo de puntos de vida del hechicero "
    "no podran ser excedidos. El danyo provocado es de 1d6 "
    "por cada 2 niveles del hechicero con un maximo de 6d6 (nivel 12). "
    "Las criaturas muertas no son afectadas por este hechizo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  int NO_D=MIN(MAX_D,(caster->QL+1)/2);

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,MSG_SUIC_C);
    tell_room(ENV(caster),MSG_SUIC_R,caster);
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  target=check_melee_protector(target,caster);

  if (!living(target) || target->query_dead())
  {
    tell_object(caster, "Necesitas formular el hechizo sobre seres vivos.\n");
    return -1;
  }

  tell_object(target,caster->QCN+" te toca, sientes como tu vida drenada y transmitida a "+caster->QCN+" que se ve refrescado.\n");
  tell_object(caster, "Formulas el hechizo "+NOMBRE+" sobre "+target->QCN+", sintiendote mas refrescado.\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y toca a "+
    target->QCN+" que pierde su fuerza vital para pasar a pertenecele.\n",
    ({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
  if (target->query_property("undead") ) 
  {
    tell_object(caster,"Has formulado el hechizo sobre una criatura muerta, sientes que algo estranyo ha ocurrido..\n");
    damage=-damage;
  }

  damage=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  damage+=caster->spell_damage(-damage*POWER/2,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
