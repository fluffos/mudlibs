// Traducido por Lummen 4-9-97

#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE	= "Proyectil magico menor";
#define	ESCUELA	({"invocacion"})
#define	ESFERA	({""})
string	TIPO	= "magical";
int	SALV	= 100;
string	CANCION	= "'magyiz myssl'";
int	NIVEL	= 1;
int	SIZE_D	= 4;
int	MAX_D	= 5;
int	BONUS	= 1;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(10);
  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvadion: Ninguna");
  set_help_desc("Este hechizo lanza unas pequenyas descargas de energia "
    "a un objetivo. Cada descarga provoca 1d"+SIZE_D+" +"+BONUS+" puntos de "
    "danyo, lanzando 1 misil por cada 2 niveles de experiencia, hasta un "
    "maximo de "+MAX_D+" misiles.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i;
  int damage;
  int NO_D=MIN(MAX_D,(caster->QL+1)/2);

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

  tell_object(target,"Eres herido por "+NO_D+" misiles magicos.\n");
  tell_object(caster,"Formulas el hechizo Misil Magico y hieres a "+target->QCN+" con "+NO_D+
    " misiles magicos.\n");
   
  if (ENV(caster)==ENV(target))
    tell_room(ENV(caster),(string)caster->QCN+" formula un hehcizo y "+target->QCN+" es atacado por "+
      NO_D+" misiles magicos.\n",({target,caster}) );
  else
  {
    tell_room(ENV(caster), caster->QCN+" formula un hechizo y "
      +NO_D+" misiles vuelan a alguna parte.\n", caster);
    tell_room(ENV(target), target->QCN+" es herido por "
      +NO_D+" misiles que llegan de algun lugar.\n", target);
  }

  damage=fix_damage(caster,target,-roll(NO_D,SIZE_D)-NO_D*BONUS);
  damage+=target->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  return NIVEL*100-damage;
}
