// Traducido por Lummen '98

#include <weather.h>
#include <spells.h>
inherit BASE_SPELL;
inherit BASES+"UD_query";

#define	NOMBRE	"Terremoto"
#define	ESCUELA	({""})
#define	ESFERA	({"combate"})
#define	NIVEL	7
#define	CANCION	"'terra firma venit'"
#define TIPO	"stone"
#define	SALV	50
#define SIZE_D	3

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("many");
  set_range(0);

  set_help_extras("Tipo de Danyo: "+tipo(TIPO)+"\nTirada de Salvacion: 1/2");
  set_help_desc("Este hechizo causa un terremoto, el grupo de enemigos "
    "sufriran la fuerza del brazo de Astaroth. Este hechizo solo puede "
    "trabajar en la Suboscuridad. Una advertencia: la naturaleza "
    "destructiva de este hechizo hace que el hechizero pierda el "
    "conocimiento del hechizo 'curacion'. Igualmente importante es "
    "el hecho de que cuando el hechizo acabe, el Dios Astaroth pueda "
    "pedir un pago por realizar este...\n");

  set_gp_cost(NIVEL);	// 20 antes
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Levantas tus manos hacia el cielo para realizar tu plegaria.\n");
  tell_room(ENV(caster),caster->QCN+" levanta sus manos hacia el cielo realizando una plegaria en un tono de susurro.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(ENV(caster),"La tierra comienza a temblar, algo peligroso esta ocurriendo.\n");
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int NO_D=random(3)*MIN(30,caster->QL)+caster->QL/2,damage,i;

  if (!where_me(caster) && !ENV(caster)->query_underground())
  {
    tell_object(caster,"Estas demasiado lejos de la suboscuridad para que tu deidad te ayude.\n");
    return -1;
  } 

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  if (!sizeof(target))
  {
    tell_object(caster,"El hechizo comienza a concentrar la "
      "energia desmesuradamente sin que busque a un objetivo especifico. "
      "Desesperadamente intentas para el hechizo, pero la magia invade todo "
      "tu ser sin que puedas controlar su terrible poder. Parece descontrolado!.\n\n");
    tell_room(ENV(caster),"La cara de "+caster->QCN+" esta llena de terror. "
      "Un cumulo de energia magica te golpea, al parecer el control del "
      "hechizo se ha perdido. Algo te dice que debes huir de este lugar rapidamente.\n",caster);
    damage=fix_damage(caster,caster,-roll(NO_D,SIZE_D));
    caster->spell_damage(damage,TIPO,query_sphere(),SALV,caster);
    return -1;
  }

  tell_object(caster,"Invocas fervientemente a Astaroth y la tierra "
    "comienza a sacudir ruidosamente a tus enemigos!\n");
  tell_room(ENV(caster),caster->QCN+" invoca fervientemente a Astaroth y la "
    "tierra comienza a temblar terriblemente, parace que la tierra se "
    "desquebraja en tus pies. Estas encima de un terremoto!\n",caster);

  for (i=0;i<sizeof(target);i++)
  {
    if (!living(target[i]) || !target[i]->query_alive()) continue;

    damage=fix_damage(caster,caster,-roll(NO_D,SIZE_D));
    caster->spell_damage(damage,TIPO,query_sphere(),SALV,caster);

    if (target==caster)
    {
      tell_object(caster, "Estas loca!, Acaso quieres que la ira de Astaroth caiga sobre ti??\n");
      tell_room(ENV(caster),caster->QCN+" screams and curses as the earth collapses beneath "+caster->query_objective()+"!\n",caster);
    }
    else switch (damage)
    {
      case 1..10:
        tell_room(ENV(caster),target[i]->QCN+" es golpeado por una roca lanzada por la fuerza del terremoto.\n",target[i]);
        tell_object(target[i],"Eres golpeado por una roca lanzada por la fuerza del terremoto.\n");
        break;
      case 11..30:
        tell_room(ENV(caster),target[i]->QCN+" es lanzado por los aires por la fuerza del terremoto.\n",target[i]);
        tell_object(target[i],"La fuerza del terremoto te hace salir despedido por lo arires.\n");
        break;
      case 31..80:
        tell_room(ENV(caster),target[i]->QCN+" es derribado violentamente por un muro de rocas del terremoto.\n",target[i]);
        tell_object(target[i],"Eres derribado violentamente por un muro de rocas del terremoto.\n");
        break;
      case 81..120:
        tell_room(ENV(caster),"La tierra se abre con un horrendo sonido y "+target[i]->QCN+" es engullido por ella.\n",target[i]);
        tell_object(target[i],"La tierra se abre bajo tus pies y eres engullido por ella sintiendo un terrible dolor.\n");
        break;
      case 121..10000:
        tell_room(ENV(caster),"La tierra comienza a temblar de forma descontrolada escupeindo una llamarada de lava sobre "+target[i]->QCN+", el cual desaparece en la lava emitiendo un grito desgarrador.\n",target[i]);
        tell_object(target[i],"Una terrible ola de lava salde despedida por los aires del interior de la tierra para envolverte en una lluvia de dolor y terror.\n");
        break;
      default:
        tell_room(ENV(caster),target[i]->QCN+" milagrosamente solo es sacudido por el terremoto.\n",target[i]);
        tell_object(target[i],"Eres sacudido levemente por el terremoto.\n");
    }
    caster->remove_spell("curacion");
    target[i]->attack_by(caster);
  }
  return 0;
}
