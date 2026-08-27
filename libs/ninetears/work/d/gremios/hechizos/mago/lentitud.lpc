// Slow
// By Wonderflug
//Paris, Jun98. Anyadido como hechizo de atake

#include <spells.h>
#define	NOMBRE		"Lentitud"
#define	ESCUELA		"alteracion"
#define	ESFERA		""
#define	NIVEL		3
#define	SHADOW		SHADOWS+"slow_sh"
inherit BASE_SPELL;
string	CANCION="'temporis laggen'";

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo relentiza el tiempo para el objetivo. "
    "En particular, no sera capaz de atacar como siempre, y cualquier hechizo le tardara "
    "mas tiempo de lo normal de formular. Este hechizo relentizara al objetivo "
    "un turno por cada nivel del hechizero.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;
  object ob;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_haste_spell())
  {
    target->dispell_time_spell();
    return 0;
  }

  if (target->query_slow_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,MSG_NO_PUEDO);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster,"Formulas el hechizo Relentizar sobre "+ target->QCN+".\n");
  tell_object(target,"Sientes como el tiempo comienza a cambiar a tu alrededor, "
      "relentizando cualquier movimiento que realices.\n"); 
  tell_room(ENV(caster),caster->QCN+" termina un hechizo con un gesto sobre "
      +target->QCN+", y sus movimientos se ven relentizados.\n",({caster,target}));

  duration=caster->QL*POWER;
  duration=fix_damage(caster,target,duration);
  target->ATP("slow_on",1,duration);

  ob=clone_object(SHADOW);
  ob->setup_shadow(target); 
  ob->attack_by(caster);
  return NIVEL*100;
}
