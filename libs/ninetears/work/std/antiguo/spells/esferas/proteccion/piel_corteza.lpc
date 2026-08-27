#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Piel de corteza"
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({"proteccion","vegetal"})
#define	NIVEL	2
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell causes the druid's skin to become very tough "
    "and hard, like tree bark.  Damage from attacks will be reduced while the "
    "Barkskin is in effect, and in addition a -1 to AC will be given. "
    "However, since the skin will be heavier, a -1 to dexterity will be "
    "incurred as well.  The spell lasts 5 rounds per level of the caster.");

  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You go into a deep meditative trance, drawing in power from the earth.\n");
  tell_room(ENV(caster),caster->QCN+" goes into a deep trance.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You awaken from the trance, wrapped in a sheath of power.\n");
  tell_room(ENV(caster),caster->QCN+" awakens from the trance, and "+caster->query_possessive()+
    " eyes seem to glow slightly.\n", caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"You weave the forces of nature into a rippling sheath of healthy, living tree bark.\n");
  tell_room(ENV(caster),"A huge sheet of tough, rippling tree bark forms in front of "+caster->QCN+".\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shadow;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    tell_room(ENV(caster),"The sheath of bark falls limply to the ground and disintegrates.\n");
    return -1;
  }

  if ( target->query_stoneskin_spell() || target->query_mirror_spell() ||
        target->query_armour_spell() || target->query_wraithform() )
  {
    tell_object(caster,"Magic around your target disrupts your spell.\n");
    tell_object(target,"The sheath of bark descends around you "
      "but slowly fades to nothingness before it touches you.\n");
    tell_room(ENV(caster),"The sheath of bark descends "
      "around "+target->QCN+" but disintegrates into nothingness.\n",({caster,target}));
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,"You wrap yourself in the sheet of bark and feel protected.\n");
    tell_room(ENV(caster),caster->QCN+" wraps "+
      caster->query_possessive()+"self in the sheet of bark, and it "
      "eerily molds to "+caster->query_possessive()+" skin.\n",caster);
  }
  else
  {
    tell_object(caster,"You wrap the sheet of bark around "+target->QCN+", in a protective shell.\n");
    tell_object(target,"The sheath of bark enfolds you and molds onto your skin.\n");
    tell_room(ENV(caster), "The sheath of bark enfolds "+
      target->QCN+" and molds to "+target->query_possessive()+" skin.\n",({caster,target}));
  }
  target->ATP("barkskin_on",1,5*caster->QL); 
  target->adjust_tmp_dex(-1);
  target->adjust_tmp_ac_bon(10);
  shadow=clone_object(SHADOWS+"barkskin_sh");
  shadow->setup_shadow(target);
  target->add_extra_look(shadow);
  return 0;
}
