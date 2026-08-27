// Paris. Nov'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Ola de frio"
#define NIVEL	9
#define	ESCUELA	({"invocacion","wizwar"})
#define	ESFERA	({""})
#define	TIPO	"frio"
#define	SALV	25
#define SIZE_D	4
#define	NO_D	caster->query_level() + 2

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("all");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/4");
  set_help_desc("Este hechizo envuelve a tus enemigos en una terrible ola de frio "
     "procedente del mismisimo polo, calandose hasta sus huesos");
  set_casting_time(2);
  set_gp_cost(NIVEL);
  set_rounds(({({
    "Una fria ventisca procedente del mismisimo polo azota los cuerpos de los congregados.\n",
    "Una fria ventisca procedente del mismisimo polo azota los cuerpos de los aqui presentes.\n"
    }),"round2"}));
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i;
  
  target-=({caster});

  if (!sizeof(target))
  {
    tell_object(caster,"Un frio vendaval de nieve y granizo se origina a " +
	"tu alrededor congelandolo todo, pero parece que nadie ha sufrido " +
	"las consecuencias.\n");
	/*
    tell_room(ENV(caster), "Un frio vendaval de nieve y granizo se origina "+
	"alrededor de " + caster->QCN +" congelando todo lo de tu alrededor " + 
	"pero sin afectar a nadie.\n",caster);*/
    return -1;
  }

  tell_object(caster, "Un frio vendaval de nieve y granizo se origina a " +
	"tu alrededor congelandolo todo.\n");
  tell_room(ENV(caster),"Un frio vendaval de nieve y granizo nace alrededor de "+
     caster->QCN+" congelandolo todo.\n",caster);

  for (i=0;i<sizeof(target);i++)
  {
    tell_object(target[i],"Escalofrios descomunales te hacen tiritar de forma incontrolada al calarsete el frio hasta en los huesos!\n");
    tell_room(ENV(target[i]),target[i]->QCN+" tirita y grita horrorizado al sufrir las bajas temperaturas!\n",target[i]);
    target[i]->destruct_mirror_shadow(); /*nunsei si dejarlo*/
//	target[i]->dest_hide_shadow(); no hace falta :?
    damage=fix_damage(caster,target[i],-roll(NO_D,SIZE_D));
    target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
/* CHORRADA
    if (target[i]->query_dead())
      tell_room(ENV(caster),target[i]->QCN+" es incinerado hasta los huesos convirtiendose en no mas que un monton de polvo.\n");*/
    target[i]->attack_by(caster);
  }

  tell_object(caster,"Congelas a "+query_multiple_short(target)+" con el frio proviniente desde el mismisimo polo.\n");
  if (sizeof(out_range))
    tell_object(caster,"Ooopps, "+query_multiple_short(out_range)+" huye a un lugar mas seguro.\n");
  return 0;
}
