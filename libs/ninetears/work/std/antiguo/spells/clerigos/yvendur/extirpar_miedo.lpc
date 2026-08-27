#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Extirpar miedo"
#define	ESFERA	({"alteracion"})
#define	ESCUELA	({""})
#define   CANCION   "Medrus et pirus"
#define	NIVEL	1

void setup()
{
  set_spell_name(NOMBRE);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo hace desaparecer el miedo de un "
                "objetivo. Si este estaba afectado por el conjuro "
                "implantar miedo o por otro tipo de miedo");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int resist_value;
  int level;
   object ob;

  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " canta, "+CANCION+".\n", ({target,caster}));
    tell_object(target, "Tu cantas, "+CANCION+".\n");
  }

  if(target == caster)
  {
    tell_object(caster, "Formulas una bendicion calmadora sobre ti mismo.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " formula un hechizo sobre si mismo.\n",caster);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " te hace arrodillarte ante el y te bendice.\n");
   
    tell_object(caster, "Te arrodillas ante "+
      (string)target->query_cap_name() + " y te bendice "+
      " con unas palabras calmantes.\n");
   
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " se arrodilla delante de "+target->query_cap_name()+" y es bendecido.\n",
      ({target,caster}) );
  }
  target->remove_timed_property("fear");
  target->remove_static_property("fear");

   
  return 0;
}
