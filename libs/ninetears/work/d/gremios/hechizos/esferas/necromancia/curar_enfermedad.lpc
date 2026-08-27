#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Curar enfermedad"
#define	NIVEL	5
#define	ESFERA	({"necromantica"})
#define	ESCUELA	({"necromancia"})
#define	CANCION	"'illar camu enufus'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("   This spell will cure most diseases, although plague and "
     "a few rare strains may be beyond the scope of this spell.\n"
     "  Clerics with more "
     "powerful healing spheres will have more success with this "
     "spell.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int i,j;
  object *stuff;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  // added to kill parasites (shifter guild)
  if (target->query_property("infecting")==1)
  {
    tell_room(ENV(caster),caster->QCN+" summons of all of "+caster->query_possessive()+" powers and focuses them on "+target->QCN+"!\n");
    target->do_cure(caster);
    return 1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target==caster)
  {
    tell_object(target,"You cure yourself of disease.\n");
    tell_room(ENV(caster),caster->QCN+" cures "+caster->query_possessive()+"self of disease.\n",caster);
  }
  else
  {
    tell_object(target,caster->QCN+" touches you curing you of diseases.\n");
    tell_object(caster,"You cast cure disease at "+target->QCN+".\n");
    tell_room(ENV(caster),caster->QCN+" casts a spell and cures "+target->QCN+" of disease.\n",({target,caster}));
  }
  stuff=all_inventory(target);
  for (j=0;j<sizeof(stuff);j++) if((stuff[j]->query_name())=="disease") stuff[j]->dest_me();
  target->RTP("diseased");
  target->RSP("diseased");
  target->ROP("diseased");
  return 10;
}
