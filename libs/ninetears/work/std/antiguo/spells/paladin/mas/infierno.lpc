// Paris. Nov'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Inferno"
#define NIVEL	9
#define	ESCUELA	({"invocacion","wizwar"})
#define	ESFERA	({""})
#define	TIPO	"fire"
#define	SALV	50
#define SIZE_D	5
#define	NO_D	caster->query_level()

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("all");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Este hechizo envuelve a tus enemigos en llamas surgidas desde "
     "el propio nucleo de la tierra misma calcinadolos hasta los huesos.");
  set_casting_time(2);
  set_gp_cost(NIVEL);
  set_rounds(({({
    "Llamas surgidas desde la misma tierra lamen suavemente los pies de los congregados.\n",
    "Llamas surgidas desde la misma tierra lamen suavemente los pies de los aqui presentes.\n"
    }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i;
  
  target-=({caster});
  if (!sizeof(target)) 
  {
    tell_object(caster,"Grandes llamas rojas y azuladas crecen alrededor tuyo "
      "hasta una altura descomunal, pero al no haber nadie no consigues herir a nade.\n");
    tell_room(ENV(caster), "Grandes llamas rojas y azules nacen alrededor de "+
      caster->QCN+" calcinando todo lo de tu alrededor pero sin herir a nadie.\n",caster);
    return -1;
  }

  tell_object(caster, "Llamas rojas y azuladas crecen a tu alrededor hasta una "
    "altura descomunal calcinando todo lo de tu alrededor.\n");
  tell_room(ENV(caster),"Grandes llamas rojas y azules nacen alrededor de "+
     caster->QCN+" calcinando todo lo de su alrededor.\n",caster);

  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],"Eres calcinado hasta los huesos por las llamas que te envuelven !\n");
    tell_room(ENV(target[i]),target[i]->QCN+" grita de horror y dolor al ser calcinado por las llamas !\n",target[i]);
    target[i]->destruct_mirror_shadow();
    damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
    target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    if (target[i]->query_dead())
      tell_room(ENV(caster),target[i]->QCN+" es incinerado hasta los huesos convirtiendose en no mas que un monton de polvo.\n");
    target[i]->attack_by(caster);
  }

  tell_object(caster,"Calcinas a "+query_multiple_short(target)+" con las llamas surgidas desde las entranyas de la tierra.\n");
  if (sizeof(out_range))
    tell_object(caster,"Ooopps, "+query_multiple_short(out_range)+" huye a un lugar seguro.\n");
  return 0;
}
