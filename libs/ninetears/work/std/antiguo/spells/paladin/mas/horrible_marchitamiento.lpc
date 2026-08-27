// Traducido por Lummen 4-9-97

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Horrible marchitamiento"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	"'wilos magius evapious'"
#define	NIVEL	8
#define TIPO	"water"
#define	SALV	50
#define SIZE_D	8
#define	NO_D	caster->QL

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("many");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Este hechizo puede evaporar toda la humedad de los cuerpos "
    "de tus enemigos. El danyo es igual al nivel del hechicero hasta 8 veces "
    "mas. Por ejemplo, un Mago de lvl 16 producira un random de 16-128 puntos "
    "de vida. Este hechizo no tiene limite de danyo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({({
    "Comienzas a formular el hechizo, tu poder concentrar en todo tu ser provocando un pequenyo estremecimiento de tierra.\n",
    "De pronto el aire comienza a levantarse acariciando tu cara, como si el poder hubiese llegado a su punto mas algido.\n",
  }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i,xp;
 
  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  target-=({caster});
  if (!target || !sizeof(target))
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  caster->ATP("stillcasting",1,3-POWER);
  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],caster->QCN+" termina de formular un hechizo y sientes como la humedad de tu cuerpo se evapora!\n");
    tell_object(caster, "Vaporizas a "+target[i]->QCN+"!\n");
    tell_room(ENV(caster), caster->QCN+" vaporiza a "+target[i]->QCN+".\n",({caster,target[i]}));
    target[i]->destruct_mirror_shadow();
    damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
    xp-=target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    target[i]->attack_by(caster);
  }

  if (sizeof(out_range)) tell_object(caster,"No, "+query_multiple_short(out_range)+" esta fuera de rango.\n");
  return NIVEL*100+xp;
}
