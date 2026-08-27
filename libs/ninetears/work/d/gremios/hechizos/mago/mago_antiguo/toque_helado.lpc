// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Toque helado"
#define	TIPO	"evil"
#define	SALV	100
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	1
#define	CANCION	"'hanz ow froez'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Especial.\n");
  set_help_desc("Este hechizo ataca las fuerzas vitales de una criatura viva. "
    "La criatura tocada a de superar una tirada de salvacion o perder 1d4 "
    "puntos de danyo y 1 punto de fuerza temporalmente.\n");
  add_property_to_check("cast_toque_helado");
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
  tell_object(target, "Un frio temblor te envuelve al sentir contacto con "+caster->QCN+".\n");
  tell_object(caster, "Al tocar a "+target->QCN+" un frio temblor le envuelve.\n");
  tell_room(ENV(caster),caster->QCN+" pronuncia un hechizo y toca a "
      +target->QCN+" con un frio temblor.\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(1,4));
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  if (!target->spell_saving_throw(caster,query_sphere())) target->adjust_tmp_str(-1);

  target->attack_by(caster);
  caster->ATP("cast_toque_helado",1,100);
  return NIVEL*100-damage;
}
