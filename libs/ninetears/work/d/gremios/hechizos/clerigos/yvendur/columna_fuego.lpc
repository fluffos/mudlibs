#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Columna de fuego"
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
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de salvacion: 1/2");
  set_help_desc("Este hechizo levanta una columna de llamas sagradas sobre tu "
    "enemigo. El danyo causado depende del clerigo que lo formula y"
    "la esfera de poder de combate. Solo las deidades de combate pueden hacer"
    "que los golpes que recibe la victima le hagan huir.");
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

  tell_object(target,caster->QCN+" levanta un pilar de llamas sobre ti!\n");
  tell_object(caster, "Formulas Columna de fuego sobre "+target->QCN+".\n");
  tell_room(ENV(caster),(string)caster->QCN+" envuelve a "+target->QCN+" en una columna de fuego!\n",({target,caster}));

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
  damage-=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100+damage;
}
