// Traducido por Lummen 3-9-97

#include <spells.h>
inherit BASE_SPELL;

#define TIPO	"frio"
#define	SALV	50
#define SIZE_D	4
#define	NO_D	caster->QL
#define	NOMBRE	"Cono de frio"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	""
#define	NIVEL	5
#define	CANCION	"'frezzus es coe'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);
  set_help_desc("Este hechizo dispara un chorro de hielo que congela a un unico "
    "objetivo. El danyo que provoca es (nivel del hechicero)d"+SIZE_D+" + nivel del hechicero. "
    " Este hechizo no tiene maximo de danyo.\n");
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+ "\nTirada de Salvacion: 1/2");
  set_casting_time(1);
  set_rounds(({"round1"}));
  set_gp_cost(NIVEL);
}

int round1(object caster,mixed target,mixed out_of_range,int time,int quiet)
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
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  tell_object(target,caster->QCN+" hace un gesto con las manos y un cono azul de hielo se dirige hacia ti.\n");
  tell_object(caster,"Lanzas un cono de hielo a "+target->QCN+" produciendo un gran estruendo.\n");
  tell_room(ENV(caster),caster->QCN+" termina de formular un hechizo para "
    "crear un cono de hielo que golpea a "+target->QCN+".\n",({target,caster}));
  
  if (ENV(caster)!=ENV(target))
    tell_room(ENV(target),target->QCN+" es golpeado por un cono de hielo.\n",target);

  caster->ATP(STILLCASTING,1,3-POWER);

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D)-NO_D);
  damage-=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
