// Traducido por Lummen 5-9-97

#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Enjambre de meteoros"
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
#define	CANCION	"'meseious pyros blasious'"
#define NIVEL	9
#define TIPO	"tierra"
#define	SALV	50
#define SIZE_D	4
#define	NO_D	40

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("many");
  set_range(2);
  set_line_of_sight_needed(1);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Este hechizo envuelve a tus enemigos en una tormenta de "
    "meteoros que explotan al impacto, hiriendo al objetivo en el radio "
    "de la explosion. El danyo provocado es de 40-160 puntos.");
  set_casting_time(2);
  set_gp_cost(NIVEL);
  set_rounds(({({"4 esferas flamigeras de roca fundida aparecen en el aire ante ti.\n",
     "4 esferas flamigeras de roca fundida aparecen de subito en el aire.\n"}),
     "round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i,xp=0;
 
  target-=({caster});
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (!sizeof(target)) 
  {
    tell_object(caster, "Una lluvia de rocas fundidas caen de la nada... "
        "sin herir a nadie. No hay nadie aqui.\n");
    tell_room(ENV(caster),caster->QCN+" formula un hechizo y 4 meteoros de "
        "roca fundida caen en una lluvia masiva desde la nada, sin herir a "
        "nadie.\n",caster);
    return -1;
  }
  
  tell_object(caster,"Creas un enjambre de meteoros que caen como una lluvia "
    "de muerte y destruccion.\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo y un enjambre de "
      "meteoros caen como una lluvia de muerte y destruccion.\n",caster);

  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],"Un meteoro llueve del cielo y te golpea provocando una explosion!\n");
    tell_room(ENV(target[i]),target[i]->QCN+" desaparece en una explosion "
        "de un un meteoro caido del cielo!\n",target[i]);
    target[i]->destruct_mirror_shadow();
    damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
    xp-=target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    if (target[i]->query_dead())
      tell_object(caster,target[i]->QCN+" es borrado del mundo en una pila "
          "de explosiones y caos provocado por tu hechizo!\n");
    target[i]->attack_by(caster);
  }

  tell_object(caster, "Envuelves a "+query_multiple_short(target)+
    " en una lluvia de meteoritos.\n");

  if (sizeof(out_range)) tell_object(caster, "Ooopps, "+query_multiple_short(out_range)+" huye a un lugar seguro.\n");
  return NIVEL*100+xp*2;
}
