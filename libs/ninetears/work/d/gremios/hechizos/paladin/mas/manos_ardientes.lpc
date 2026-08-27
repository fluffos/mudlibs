// Traducido por Lummen 1-7-97

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Manos ardientes"
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	({""})
#define	CANCION	"'flamius os aryes'"
#define	NIVEL	1
#define	TIPO	"fire"
#define	SALV	50
#define	MAX_L	10
#define	MOD_L	2
#define	NO_D	1
#define	SIZE_D	3

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Cuando es formulado el hechizo, una serie de llamas de fuego "
     "surge de la palma de la mano del hechicero dirigidas al objetivo "
     "produciendo "+NO_D+"d"+SIZE_D+" puntos + "+MOD_L+" puntos por nivel, "
     "hasta un maximo de "+NO_D+"d"+SIZE_D+" + "+MOD_L*MAX_L+" puntos .\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_of_range, int time, int quiet)
{
  int damage;
 
  if (!objectp(target))
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

  tell_object(target,caster->QCN+" extiende la mano exhibiendo la palma, surgiendo de esta un brillo"
    "que se hace cada vez mas intenso hasta provocar una llamarada de fuego que "
    "te envuelve.\n");
  tell_object(caster,"Tu mano despide una llamarada de fuego que envuelve a "+
    (string)target->QCN+".\n");
  tell_room(ENV(caster),"Un arco de fuego surge de la mano de "+caster->QCN+
    " envolviendo a "+target->QCN+".\n",({caster,target}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D)-MIN(caster->QL,MAX_L)*MOD_L);
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
