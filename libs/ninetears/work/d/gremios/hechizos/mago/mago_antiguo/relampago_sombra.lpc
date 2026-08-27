// Traducido por Lummen 5-9-97

#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Relampago sombra"
#define	ESCUELA	"invocacion"
#define	ESFERA	""
#define	NIVEL	5
#define	CANCION	"'xlxyx de gadrum'"
#define TIPO	"psionic"
#define	SALV	100
#define SIZE_D	6
#define	MAX_D	12

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(5);
  set_line_of_sight_needed(0);

  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: Especial");
  set_help_desc("Este hechizo canaliza energia desde el plano Shadow para "
    "generar los hechizos de los magos ilusionistas.\nEl hechizo crea la ilusion de un "
    "relampago que golpea al objetivo provocando (nivel)d"+SIZE_D+" con un maximo "
    "de "+MAX_D+"d"+SIZE_D+" puntos de danyo. El objetivo realiza una tirada de salvacion "
    "para intentar descubrir la ilusion. Si falla el hechizo trabaja normalmente,"
    "sino, el hechizo no tendra efecto.\n"); 

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,NO_D,DETECTED;

  NO_D=MIN(caster->QL,MAX_D);

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
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  DETECTED=random(20);
  if (DETECTED!=19 && DETECTED)
  {
    DETECTED+=caster->QL+POWER-target->query_int();
    DETECTED=DETECTED<10;
  }

  if (DETECTED)
  {
    tell_object(caster,target->QCN+" detecta tu ilusion!\n");
    tell_object(target,"Descubres que el hechizo de "+caster->QCN+" no es mas que una ilusion.\n");
  }
  else
  {
    tell_object(target,caster->QCN+" te electrocuta con un relampago.\n");
    tell_object(caster,"Electrocutas a "+target->QCN+" con un relampago.\n");
    if (ENV(target)!=ENV(caster))
      tell_room(ENV(target),target->QCN+" es electrocutado por un relampago.\n",target);
    else
      tell_room(ENV(caster),caster->QCN+" formula un hechizo y "+target->QCN+
          " es electrocutado por un relampago.\n",({target,caster}));

    damage=fix_damage(caster,target,-roll(NO_D,SIZE_D));
    damage-=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  }
  target->attack_by(caster);
  return NIVEL*100+damage;
}
