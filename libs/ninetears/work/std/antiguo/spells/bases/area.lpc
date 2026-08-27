// Hechizos de Area
// Traducido por Lummen 3-7-97
// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Bola de fuego";
string	TIPO	= "fuego";
string	RES	= "fuego";
int	SALV	= 50;
string	CANCION	= "'majos areos pyros'";
mixed	ESCUELA	= ({"area"});
mixed	ESFERA	= ({});
mixed	SIZE_D	= 6;
mixed	MAX_D	= 10;
mixed	LEVEL_D	= 1;
int	NIVEL	= 3;

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("many");
  set_range(0);
  set_help_desc("Este hechizo envuelve a un grupo de enemigos en "+tipo(TIPO)+".\n");
  if (!sizeof(MAX_D))
    set_help_desc("Este hechizo envuelve a un grupo de enemigos en "+tipo(TIPO)+
       ". El danyo causado es igual a (nivel del hechicero)d"+SIZE_D+(string)(MAX_D?(", hasta "
       "un maximo de "+MAX_D):" este hechizo no tiene maximo")+".\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage,i,j,nivel=caster->QL,xp=0,dados;

  if (sizeof(MAX_D)!=sizeof(SIZE_D) || sizeof(MAX_D)!=sizeof(LEVEL_D))
  {
    write("Este hechizo tiene un error en el numero de dados. Informa a alguien.\n");
    return 0;
  }
  
  if (!LEVEL_D)
  {
    write("Este hechizo tiene un error, informa a alguien.\n");
    return 0;
  }

  target-=({caster});
  if (!sizeof(target))
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  for (i=0;i<sizeof(target);i++)
    if (target[i])
    {
	//if (target[i]->query_dead()) - arreglado en patch.c
		//continue;
      damage=0;
      if (!pointerp(MAX_D))
      {
        dados=nivel/LEVEL_D;
        if (MAX_D && dados>MAX_D) dados=MAX_D;
        damage=-roll(dados,SIZE_D);
      }
      else
      {
        for (j=0;j<sizeof(MAX_D) && nivel>0;j++)
        {
          if (nivel>MAX_D[j] && MAX_D[j]) damage-=roll(MAX_D[j]/LEVEL_D[j],SIZE_D[j]);
          else damage=-roll(nivel,SIZE_D[j]);
          nivel-=MAX_D[j];
        }
      }
      target[i]->destruct_mirror_shadow();
      damage=fix_damage(caster,target[i],damage);
      xp-=target[i]->spell_damage(damage,RES,query_sphere(),SALV,caster);
      tell_object(target[i],caster->QCN+" te envuelve en un "+NOMBRE+"!\n");
      tell_room(ENV(target[i]),target[i]->QCN+" es envuelto en un "+NOMBRE+"!\n",target[i]);
      target[i]->attack_by(caster);
    }

  //if (sizeof(out_range)) tell_object(caster,"No, "+query_multiple_short(out_range)+" se ha ido.\n");
  return NIVEL*100+xp*2;
}
