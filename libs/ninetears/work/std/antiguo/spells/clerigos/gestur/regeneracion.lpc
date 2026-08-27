#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Regeneracion"
#define	ESCUELA	({""})
#define	ESFERA	({"curadora"})
#define	NIVEL	6
#define	CANCION	"'in mani timus'"
#define   OBJETO	OBJETOS+"regeneration_obj"
#define	REGEN_NUM_HB	2

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este hechizo hace que las heridas de tu objetivo se curen mucho mas "
    "rapido.  El veneno y otras heridas mas especiales no pueden ser regeneradas "
    "por este hechizo. El hechizo durara 3 turnos por cada nivel del clerigo.\n"
    "     Sobre el uso de este hechizo hay que saber que el danyo es permanente.  "
    "El que lo recibe es susceptible a los atauqes de fuego incluso una vez "
    "el hechizo se acaba. Es posible que quede algun residuo en el. Es solo "
    "recomendable el uso de este hechizo a clerigos de alto nivel.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int amount, duration;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_armour_spell() || target->query_mirror_spell() || target->QP("regen_on"))
  {
    tell_object(caster, "Algun aura magica destruye tu hechizo.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  duration=fix_damage(caster,target,caster->QL*(POWER+1));
  amount=duration/10;

  ob=clone_object(OBJETO);
  ob->set_spell(target,amount);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();
  target->add_extra_look(ob);
  target->ATP("regen_on",1,duration);

  /* Fire resistance hit.  Every three times it drops 1% */
  if (target->QP("regen_fire_counter")==2)
  {
    target->ASP("fire",target->QSP("fire")-1);
    target->ASP("regen_fire_counter",0);
    tell_object(target,"Te sientes mas susceptible al fuego.\n");
  }
  else target->ASP("regen_fire_counter",target->QP("regen_fire_counter")+1);

  if ( target!=caster) tell_object(caster,"Formulas Regeneracion sobre "+target->QCN+", y sus colores de cara cambian a mejor.\n");
  tell_room(ENV(caster),caster->QCN+" formula el hechizo Regeneracion.\n",caster);
  tell_object(target,"Notas la salud fluir atraves de ti, y tu cara cambia de color.\n");
  return 0;
}
