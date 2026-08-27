#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Implantar el miedo"
#define	ESFERA	({"hechizo"})
#define	ESCUELA	({"abjuracion"})
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

  set_help_desc("");

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
      " chants, 'bleiso umanos'.\n", ({target,caster}));
    tell_object(target, "You chant, 'bleiso umanos'.\n");
  }

  if(target == caster)
  {
    tell_object(caster, "You cast Bless upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+caster->query_objective()+"self.\n",caster);
  }
  else
  {
    tell_object(target, (string)caster->query_cap_name()+
      " kneels over you and Blesses you.\n");
   
    tell_object(caster, "You kneel over "+
      (string)target->query_cap_name() + " and bless "+
      target->query_objective()+".\n");
   
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " kneels over "+target->query_cap_name()+" chanting softly.\n",
      ({target,caster}) );
  }
   ob = clone_object(SHADOWS+"fear_sh");
   ob->setup_shadow(target);

  return 0;
}
