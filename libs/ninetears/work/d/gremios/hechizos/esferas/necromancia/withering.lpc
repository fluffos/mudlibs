// Traducido por Lummen '98
 
#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Lepra"
#define	NIVEL	6
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	"'xo harmi timus'"
#define	OBJETO	OBJETOS+"withering_obj"

void setup()
{ 
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este hechizo hace que el objetivo tenga una piel muy "
    "susceptible. Durante la duracion del hechizo, periodicamente, apareceran "
    "en el objetivo heridas menores. En adicion, el objetivo puede sentirse "
    "debilitado.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(ENV(caster),"A sudden stench of decay seems to fill the air.\n");
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int resist;
  int theroll;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_property("wither_on"))
  {
    tell_object(caster,MSG_AFECTADO);
    return 1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  resist=target->query_res("disease");
  theroll=random(100);

  if (theroll<resist) 
  {
    tell_object(caster, "Senyalas a "+target->QCN+" pero no parece ocurrirle nada!\n");
    tell_object(target,caster->QCN+" completa el hechizo, y te senyala pero no parece que te ocurra nada.\n");
    tell_room(ENV(caster),caster->QCN+" completa el hechizo y senyala a "+target->QCN+" pero no parece enterarse!\n",({caster,target}));
    return 0;
  }
 
  ob = clone_object(OBJETO);
  ob->set_spell(target,caster->QL/8);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();

  target->add_extra_look(ob);
  target->ATP("wither_on",1,caster->QL*POWER);
  target->adjust_temp_str(-POWER);

  tell_room(ENV(caster),"La piel de "+target->QCN+" comienza a pudrirse, separandose trozos y callendo al suelo.\n",({caster,target}));
  tell_object(caster,"Formula el hechizo Lepra sobre "+target->QCN+", y su piel comienza a pudrirse.\n");
  tell_object(target, caster->QCN+" completa el hechizo, y sientes como la piel de tu cuerpo comienza a pudrirse...\n");

  target->attack_by(caster);
  return NIVEL*100;
}
