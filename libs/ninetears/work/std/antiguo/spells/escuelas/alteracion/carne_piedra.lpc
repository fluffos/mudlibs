#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Carne a piedra"
#define	ESCUELA	({"alteracion","elemental tierra"})
#define	ESFERA	({"hechizo"})
#define	NIVEL	6
#define	CANCION	""
#define STONED	OBJETOS+"stoned"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("This spell turns flesh to stone. In particular, the "
    "victim cannot fight, can only move with incredible effort. "
    "The plus side is that the victim is nearly immune to physical "
    "Note: this spell does NOT wear off on it's own.\n");
  set_gp_cost(NIVEL*2);
  set_casting_time(3);
  set_rounds(({"round1","round2","round3"}));
}



int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target) return -1;

  if(target->query_undead())
  {
    tell_object(caster,"Imposible convertir en piedra a un no-muerto.\n");
    return -1;
  }
  if (target->query_haste_spell())
  {
    target->dispell_time_spell();
    return 0;
  }

  if (target->query_dead())
  {
    tell_object(caster,"No puedes convertir en piedra a un fantasma!\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),caster->QCN+" glares stonilly at "+target->QCN+".\n",caster);
    tell_object(caster, "You glare stonilly at "+target->QCN+".\n");
  }

  if (target->query_hold_spell() || target->query_pacify_spell())
  {
    tell_object(caster,"An enchantment already on the target disrupts your spell.\n");
    return -1;
  }

  if (target->QP("stoned"))
  {
    tell_object(caster,"Your target has already been Stoned.\n");
    return -1;
  }
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target) return -1;

  if (target->query_haste_spell())
  {
    target->dispell_time_spell();
    return 0;
  }

  if (target->query_dead())
  {
    tell_object(caster,"You can not stone a ghost!\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),caster->QCN+" glares stonilly at "+target->QCN+".\n",caster);
    tell_object(caster, "You glare stonilly at "+target->QCN+".\n");
  }

  if (target->query_hold_spell() || target->query_pacify_spell())
  {
    tell_object(caster,"An enchantment already on the target disrupts your spell.\n");
    return -1;
  }

  if (target->QP("stoned"))
  {
    tell_object(caster,"Your target has already been Stoned.\n");
    return -1;
  }
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster,"Your spell failed... a ghost can not be turned to stone.\n");
    return -1;
  }

  if (random(target->query_res("magical"))>10)
  {
    tell_object(caster,"Your spell fails.\n");
    tell_object(target,"A cold shudder passes through you as you escape the spell.\n");
    target->ATP("stoned",1,80000);
    return -1;
  }

  tell_object(caster,"You cast flesh to stone at "+target->QCN+".\n");

  if (target->QP("mirror")>random(caster->QL))
  {
    tell_object(caster,"Alas however, your target seems to have come prepared with a mirror.\n");
    tell_room(ENV(caster),caster->QCN+" eyes flash with brilliant green light at "+target->QCN+
      ", and "+caster->query_possessive()+" slows to a halt with a terrible grinding sound.\n",
      ({caster,target})); 
    target=caster;
  }
  else
  {
    tell_room(ENV(caster),caster->QCN+" eyes flash with brilliant green light at "+target->QCN+
      ", and "+target->query_possessive()+" slows to a halt with a terrible grinding sound.\n",
      ({caster,target}));
  }

  tell_object(target,"You feel yourself slow, your body feels leaden slowing your every movement.\n");
  ob=clone_object(STONED);
  target->ATP("stoned",1,10*caster->QL*POWER);
  ob->move(target);
  ob->reset_get();
  ob->setup_shadow(target);
  return NIVEL*100;
}
