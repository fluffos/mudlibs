#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Tormenta sagrada";
int	NIVEL	= 7;
mixed	ESCUELA	= ({""});
mixed	ESFERA	= ({"danyadora","paladin"});
string	CANCION	= "'deus ire'";
string	TIPO	= "magical";
int	SALV	= 100;
int	SIZE_D	= 6;
mixed	BADGUYS	= ({"Cleriga de Astaroth"});

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_target_type("all");
  set_range(2);
  set_line_of_sight_needed(0);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nCUIDADO: El danyo depende del Alineamiento\nTirada de Salvacion: Ninguna");
  set_help_desc("Este hechizo puede invocar una tormenta magica. "
    "Todos los objetivos vivientes en ese rango pueden ser afectados.");
  set_gp_cost(NIVEL);
  set_casting_time(3);
  set_rounds(({"round1","round1","round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i,j,dice,al;
  string str;

  if (!sizeof(target)) 
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  dice=SIZE_D;
  dice+=random((caster->QL+caster->query_cha()-5)/3);

  if (!quiet && !time)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
  
  if (member_array(caster->query_guild_name(),BADGUYS)!=-1) al=-1;
  else al=1;

	// mirar esto para asegurarse de ke se entra siempre en peleas  
  for (i=0;i<sizeof(target);i++)
  {
    j=al*target[i]->query_align();
    if (j<100 )
    {
      damage=fix_damage(caster,target[i],-roll(3,dice));
      target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
      tell_object(target[i],"Una tormenta magica se cierne sobre ti.\n");
      target[i]->attack_by(caster);
    }
    else if(j>100)
    {
      damage=fix_damage(caster,target[i],roll(1,dice));
      target[i]->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
      tell_object(target[i],"Una brisa Magica te acaricia curandote!\n");
    }
    else tell_object(target[i],"Una tormenta Magica se cierne sobre ti, pero no eres afectado por ella.\n");
  }
  str=query_multiple_short(target);
  tell_room(ENV(caster),caster->QCN+" envuelve a "+str+" en una tormenta magica!\n",({caster,target}));
  tell_object(caster, "Envuelves a "+str+" en una "+NOMBRE+"!\n");
  return 0;
}
