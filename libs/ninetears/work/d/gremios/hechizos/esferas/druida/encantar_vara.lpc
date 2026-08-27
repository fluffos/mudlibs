#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Encantar vara"
#define	ESCUELA	({})
#define	ESFERA	({""})
#define	CANCION	""
#define	NIVEL	3

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("item");
  set_range(0);

  set_help_desc("This spell will place an enchantment on a staff.  The power "
    "of the enchantment is +1 per 8 levels of the druid, to a maximum "
    "of +5.  Multiple enchants are not cumulative; the most recent "
    "enchant will be the one in effect.  It is rumored that some "
    "special staves will both increase the power of the enchantment "
    "and add some extra abilities and powers over nature.  The "
    "existence of these legendary staves is emphatically "
    "denied in the highest Druidic Circles.");

  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target)
  {
    tell_object(caster,"You draw in power from the world for your enchantment.\n");
    tell_room(ENV(caster),caster->QCN+" goes into an odd trance-like state.\n",caster);
  }
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target)
  {
    tell_object(caster,"You hold the "+target->query_short()+" out in front of you.\n");
    tell_room(ENV(caster),caster->QCN+" holds a "+target->query_short()+" out in front of "
       +caster->query_objective()+".\n",caster);
  }
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (target)
  {
    tell_object(caster,"You release the "+target->query_short()+
       ", and it hovers in the air in front of you.\n");
    tell_room(ENV(caster),caster->QCN+" releases the "+target->query_short()+" and it hovers in mid-air!\n",caster);
  }
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_weapon_name()!="quarterstaff")
  {
    tell_object(caster, "You come out of the trance and realize you "
      "cannot enchant this item!\n\nThe backlash of power whips you.\n");
    tell_room(ENV(caster), caster->QCN+" comes out of the trance and glows briefly with power. The power goes out "
      "of control and whips "+caster->QCN+"! "+caster->QCN+" howls with pain.\n", caster);
    caster->adjust_hp(-random(10)-1);
    return 0;
  }

  tell_object(caster, "You come out of the trance and channel your power "
    "into the "+target->query_short()+".\n");
  tell_room(ENV(caster), caster->QCN+" glows with a "
    "soft blue aura that slowly seeps into the "+target->query_short()+
    ".\n", caster);
  tell_room(ENV(caster), "The "+target->query_short()+" pulses "
    "with a blue radiance that slowly fades away.\n\nThe "+
    target->query_short()+" drops to the ground.\n");

  target->set_enchant(MAX(1,MIN(5,caster->QL/8)));
  return 0;
}
