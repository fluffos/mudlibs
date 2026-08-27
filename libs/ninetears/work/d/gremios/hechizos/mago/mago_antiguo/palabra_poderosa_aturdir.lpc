#include <player.h>
#include <spells.h>
#define SHADOW	SHADOWS+"stun"
inherit BASE_SPELL;
#define	NOMBRE	"Palabra poderosa aturdir"
#define	ESCUELA	"necromancia"
#define	ESFERA	""
#define	NIVEL	7
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_school(ESCUELA);

  set_target_type("all");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo te permite gritar la Palabra Poderosa Aturdir. "
    "Todos los que esten en la habitacion estaran aturdidos de 1-5 rounds. Durante "
    "este tiempo, no se pueden mover, atacar o formular hechizos, y seran mas vulnerables "
    "ante los ataques.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object *shadows;
  int i,j;

  if (!sizeof(target))
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  caster->ATP(file_name(TO),1,30);
  shadows=allocate(sizeof(target));
  tell_room(ENV(caster), caster->QCN+" grita: STUN!\n", caster);
  tell_object(caster,"Gritas: STUN!\n");

  for (i=0;i<sizeof(target);i++)
  {
    if (target[i]==caster || !living(target[i]) || target[i]->query_dead() || target[i]->query_creator() ) continue;

    while (target[i]->query_time_spell())
    {
      tell_object(target[i],"La Palabra de Poder destruye tu encantamiento!\n");
      target[i]->dispell_time_spell();
    }

    j=random(5)+POWER+1;
    if ( j<=0 || target[i]->query_hold_spell() ||  target[i]->query_pacify_spell() || 
        target[i]->spell_saving_throw(caster,ESCUELA) )
    {
      tell_room(ENV(caster), target[i]->QCN+" resiste los efectos de la Palabra de Poder.\n", target[i]);
      tell_object(target[i],"Resiste los efectos de la Palabra de Poder.\n");
      continue;
    }

    tell_room(ENV(caster),target[i]->QCN+" sucumbe ante la palabra de poder y cae incosciente.\n",target[i]);
    tell_object(target[i],"Sucumbes ante la Palabra de Poder y la oscuridad se cierne sobre ti.\n");

    target[i]->ATP("stun_on",1,j);
    target[i]->ATP("nocast",1,j);
    target[i]->ATP("noguild",1,j);
    target[i]->ATP(PASSED_OUT_PROP,"Todavia te estas recuperando de la Palabra de Poder, no puedes hacer nada.\n",j);

    shadows[i]=clone_object(SHADOW);
    shadows[i]->setup_shadow(target[i],j);
    target[i]->add_extra_look(shadows[i]);

    target[i]->attack_by(caster);
  }
  return 0;
}
