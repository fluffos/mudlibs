// Paris. Jun'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Cegar"
#define	NIVEL	9
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({""})
#define	CANCION	""
#define	SHADOW	SHADOWS+"blind_sh"
#define TIPO    "magico"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("Este hechizo nubla la vista del objetivo impidiendo que este vea nada "
                "durante un tiempo (variable).\n"); 
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({ "round1" }));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (target->query_timed_property("cegar"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }   

  ob=clone_object(SHADOW);
  ob->start(target);
  target->add_timed_property("cegado",1,150+20*15);
  tell_object(target,"Una neblina cubre repentinamente tu vision. Estas cegado !.\n");
  tell_object(caster,"Has cegado a "+target->query_cap_name()+".\n");
  return 0;
}

