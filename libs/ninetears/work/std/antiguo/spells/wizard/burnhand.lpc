/*** Burning Hands Spell ***/
/*** Created by Eerevann Tokani ***/
/*     Cosmetics by Aarn'Kii  --  03/94     */
/* working with NPC's Taniwha '95 */
/* Rewritten to use new base spell object, Wonderflug 95 */

inherit "/std/spells/base";

#define TYPE "fire"
#define SIZE_OF_DICE 3
#define save_type "fire"

void setup()
{
  set_spell_name("Burning Hands");
  set_school("alteration");
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras(
    "Damage Type: " TYPE "\nSaving Throw: 1/2");
  set_help_desc("When cast, a jet of flame shoots from the caster's "
    "fingertips to the target.  Damage done is 1d3 points + 2 points "
    "per level of the caster, to a maximum of 1d3+20 points.\n");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );

}

int wiz_fix_damage(object caster,object victim,int damage,string save);

int round1(object caster, mixed target, mixed out_of_range, int time, int quiet)
{
  int damage;
  int level;
 
  if ( !objectp(target) )
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }


  if (target == caster)
  { 
    tell_object(caster, "Wouldn't that be suicide?\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " stops casting.\n", caster);
    return -1;
  }

  tell_room(environment(caster),(string)caster->query_cap_name()+
    " chants, \"flamius os aryes.\"\n", ({target,caster}) );
    
  tell_object(caster, "You chant, \"flamius os aryes.\"\n");
   
  tell_object(target, (string)caster->query_cap_name()+
    " brings "+caster->query_possessive()+" hands together, and "
    "the air around them flashes into a brilliant jet of flames that "
    "envelopes you.\n");
   
  tell_object(caster,"You send a large jet of flames into "+
    (string)target->query_cap_name()+"'s midsection.\n");
   
  tell_room(environment(caster),
    "An arc of flame erupts from "+caster->query_cap_name()+
    "'s hands, blanketing "+target->query_cap_name()+" in fire.\n",
    ({caster,target}));

  level = (int)caster->query_level();

  if (level > 10)
    level = 10;

  damage = random(3) + 1 + (level*2);

  damage = wiz_fix_damage(caster, target, damage, save_type);

  target->spell_damage(target, damage, TYPE, caster);

  target->attack_by(caster);

  return 0;
}
