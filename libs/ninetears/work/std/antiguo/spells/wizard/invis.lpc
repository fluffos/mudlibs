
/**** Invisibility Spell ***/
/* Taniwha '96 */

inherit "/std/spells/base";
#define SHADOW "/std/spells/wizard/invis_sh"
#define TYPE "invisibility"
#define save_type "magical"

void setup()
{
  set_spell_name("Invisibility");
  set_school("alteration");
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("When cast the target may become invisible. "
    "Note that this spell breaks down if the target moves "
    "or talks emotes fights. "
    "In fact it's totally useless for doing anything other than lurking.\n");

  set_gp_cost(2);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );

}

int wiz_fix_damage(object caster,object victim,int damage,string save);

int round1(object caster, mixed target, mixed out_of_range, int time, int quiet)
{
  int damage;
  int level;
  object ob;
  if ( !objectp(target) )
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }



  tell_room(environment(caster),(string)caster->query_cap_name()+
    " chants, \"Illios effacious.\"\n", ({target,caster}) );

  tell_object(caster, "You chant, \"Illios effacious.\"\n");

  tell_object(target, (string)caster->query_cap_name()+
    " makes like a stain, and fades.\n"
    );


  level = (int)caster->query_level() * 3;

   damage = wiz_fix_damage(caster,target,100,save_type);

  if(random(damage) > 10)
  {
    ob = clone_object(SHADOW);
    ob->setup_shadow(target);
  }
  return 0;
}



