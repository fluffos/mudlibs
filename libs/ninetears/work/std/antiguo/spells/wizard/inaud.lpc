
/**** Inaudibility Spell ***/
/* Taniwha '96 */
inherit "/std/spells/base";
#define TYPE "inaudibility"
#define save_type "magical"
void setup()
{
  set_spell_name("Inaudibility");
  set_school("abjuration");
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("When cast the target may become inaudible. "
    "This causes chanting to be unheard for a short time. "
    "\n");
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
    " chants,very quietly \"hush.\"\n", ({target,caster}) );
  tell_object(caster, "You chant,very quietly \"hush.\"\n");
  tell_object(target, (string)caster->query_cap_name()+
    " seems to be surrounded by a faint mist for a few seconds.\n"
    );
  level = (int)caster->query_level() * 3;
   damage = wiz_fix_damage(caster,target,100,save_type);
  if(random(damage) > 10)
  {
    target->add_static_property("inaudible",1);
  }
  return 0;
}



