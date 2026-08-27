
/*** Wall of Fire ***/
/*** Created by Wonderflug ***/
#include "tweaks.h"
inherit "/std/spells/base.c";
#define EC environment(caster)
#define SP_NAME "Power Word Defenestration"
void setup()
{
  set_spell_name(SP_NAME);
  set_spell_level(10);
  set_sphere("bard");
  set_target_type("one");
  set_range(0);
  set_help_extras(
    "Damage Type: Magical\n"
    "Saving Throw: Dex");
  set_help_desc("This spell will summon a window "
    "then hurl the victim through the window. "
    "It only works inside.\n"
    "Damage: varies, bonuses for being used in high places "
    "                bars or bedrooms. ");

  set_gp_cost(10);
  set_casting_time(2);
  set_rounds( ({ "round1","round2" }) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  if((string)environment(caster)->query_property("location") != "inside")
  {
    tell_object(caster, "You look around and realize there's no "
      "where for a window to be.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks around confusedly and stops casting.\n", caster);
    caster->add_timed_property("nope",1,6);
    return -1;
  }
  if(!quiet)
  {
    tell_object(caster,"As you frame a window in the air with your hands "
    "your arms grow longer and stronger.\n");
    tell_room(environment(caster),caster->query_cap_name()+
     " waves "+caster->query_possessive()+" arms and they seem to "
     "get longer and stronger as the gestures define a ghostly "
     "window frame.\n",caster);
  }
  return 1;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet )
{
  int damage,bonus,i;
  int *co;
  string *direc;
  string which;


  if(!target) return 0;
  if(caster->query_property("nope")) return 0;

  co = EC->query_co_ord();

  if ( !quiet )
  {
    tell_object(caster, "\nYou shout, 'defenestrate bastards'.\n");
    tell_room(environment(caster), "\n"+caster->query_cap_name()+
      " shouts, 'defenestrate'.\n",caster);
  }
  damage = 5;
  if(sizeof(co)) damage += co[2];
  bonus = 1;
  if(member_array("/std/pub.c",deep_inherit_list(environment(caster))) >= 0)
  {
    bonus = 5;
  }
  else if(member_array("bedroom",explode(environment(caster)->query_long()," ")) >= 0)
  {
    bonus = 10;
  }
   direc = EC->query_direc();
   which = direc[random(sizeof(direc))];

   if(!target->query_property("NOBUDGE"))
   {
        tell_object(caster,"Your ape like arms hurl "+target->query_cap_name()+" through the "+which+" window.\n");

        tell_room(EC,(string)caster->query_cap_name()+" grabs "+target->query_cap_name()+
            "and hurls them through the "+which+" window.\n",({caster,target}));
        tell_object(target,(string)caster->query_cap_name()+" hurls you through the "+which+" window.\n");

        EC->do_exit_command("",({which," "+(string)target->query_cap_name()+" hurtles through the "+which+" window."}),target,0);

        damage = damage * bonus;

        target->attack_by(caster);
        if(random((int)target->query_dex()) > 10) damage = damage / 2;
        target->adjust_hp( -random(damage) ,caster);
    }
    else
    {
        tell_object(caster,"You strain mightilly, but "+target->query_cap_name()+
        " just won't budge.\n");
        tell_room(EC,(string)caster->query_cap_name()+" appears to nearly have a hernia "
        " trying to throw "+target->query_cap_name()+" through the window.\n",({target,caster}));
        target->attack_by(caster);
    }
   EC->add_item(({"windowframe","window frame"}),"A neatly made window frame is fitted "
   "into the wall by the "+which+" exit.\n"
   "It seems out of place somehow since the view through the window isn't of the "
   "adjacent room, but seems to flicker with a variety of images.\n"
   "In neat gold lettering on the sill are the words: "
   "%^YELLOW%^\""+caster->query_cap_name()+" was here.\"%^RESET%^\n");
   return 1;
}

