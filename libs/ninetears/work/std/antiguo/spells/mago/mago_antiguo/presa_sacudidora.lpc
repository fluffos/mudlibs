// Shocking Grasp Spell
// Created by Eerevann Tokani
// Traducido por Lummen 2-7-97

#define	NOMBRE	"Presa sacudidora"
#define	ESCUELA	({"conjuracion"})
#define	ESFERA	""
#define	NIVEL	1
#define	CANCION	"'hanz ow xlxyx'"
#define	TIPO	"electrical"
#define	SALV	100
#define	SIZE_D	8

#include <spells.h>
inherit BASE_SPELL;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Ninguna.\n");
  set_help_desc("Este hechizo confiere a las manos del hechicero una carga electrica. "
    "Este debera tocar al objetivo para inflingirle danyo, siendo "
    "1d"+SIZE_D+" + 1 punto por nivel del hechicero.\n");
 
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
  }
    
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  target=check_melee_protector(target,caster);
  
  tell_object(target,"Una descarga de electricidad te envuelve al sentir contacto con "+caster->QCN+".\n");
  tell_object(caster,"Al tocar a "+target->QCN+" una descarga electrica le envuelve.\n");
  tell_room(ENV(caster),caster->QCN+" pronuncia un hechizo y toca a "+target->QCN+" con una descarga electrica.\n",({target,caster}));
  damage=fix_damage(caster,target,-roll(1,SIZE_D)-caster->QL);
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
