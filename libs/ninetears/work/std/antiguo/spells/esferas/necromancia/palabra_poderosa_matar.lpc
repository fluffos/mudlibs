#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Palabra poderosa matar"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	9
#define	CANCION	""

void setup() 
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este conjuro matara a tu victima.\n");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{     
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!living(target))
  {
    tell_object(caster,"Ups, parece que ya esta muerto.\n");
    return -1;
  }

  if (target->query_creator())
  {
    tell_object(caster,"Intentando matar a un inmortal?.\n");
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster, target->QCN + " ya esta muerto.\n");
    return -1;
  }

  if (target->query_hp()>80)
  {
    tell_object(caster,"Tu objetivo se resiste a morir.\n");
    tell_room(ENV(caster),caster->QCN+" senyala a "+target->QCN+" y dice MUERE!\n",({caster,target}));
    tell_object(target,caster->QCN+" te dice MUERE! y sientes mucho dolor en tu alma.\n");
  }
  else
  {
    tell_object(caster,"Extraes el alma de "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" senyala a "+target->QCN+" y dice MUERE!\n",({caster,target}));
    tell_object(target,caster->QCN+" te dice MUERE!\n");
    target->do_death(caster);
    return 100*NIVEL;
  }
}
