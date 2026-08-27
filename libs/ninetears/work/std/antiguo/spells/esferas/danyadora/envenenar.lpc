#include <spells.h>
inherit BASE_SPELL;
#define	NIVEL	2
void setup()
{
  set_spell_name("Neutralizar Veneno");
  set_spell_level(NIVEL);
  set_sphere("danyadora");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo puede curar a un objetivo de cualquier "
    "envenenamiento. Por lo que solo curar a aquellos afectados de "
    "hechizos de efectos de Veneno y heridas de veneno.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object* obs;
  int i;

  if ( !target )
  {
    tell_object(caster, 
      "El hechizo falla ... no hay nadie aqui con ese nombre.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " pronuncia en cantico 'toxus wrathi aborum'.\n", caster);
    tell_object(caster, "Pronuncias el cantico 'toxus wrathi aborum'.\n");
  }

  if ( target != caster )
    tell_object(caster, "Acabas el hechizo y extraes el veneno que "+
      target->query_cap_name()+" tiene en su cuerpo.\n");

  tell_room(environment(caster), (string)caster->query_cap_name()+
    " acaba el hechizo y "+target->query_cap_name()+
    " se ve mucho mejor.\n", ({caster, target}));
  tell_object(target, "Comienzas a sentirte mucho mejor puesto que "
    "el veneno de tu cuerpo ha sido extraido.\n");

  obs = all_inventory(target);
  for (i=0;i<sizeof(obs);i++)
    if ( (string)obs[i]->query_name() == "poisoned wound" )
      obs[i]->dispell_me();
 
  return 0;
}
