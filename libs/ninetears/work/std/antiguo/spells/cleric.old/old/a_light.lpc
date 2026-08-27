#define MIN_LVL 8
#define GP_COST 50

mixed spell(int skill, int cast);

int cast_spell(string str)
{
 int skill;

 skill = (int)this_player()->query_skill_bonus("magic.spells.misc.area");

 if (skill < MIN_LVL)
 {
  notify_fail("You are not skilled enough to cast Brighten Area.\n");
  return 0;
 }
 spell(skill, 1);
 write("You start casting Brighten Area.\n");
 return 1;
}

mixed spell(int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";

 this_player()->add_spell_effect(1, "misc", "Brighten Area", this_object(),
  "hb_spell", ({ skill,cast }));

 return 1;
}

int hb_spell(object caster, mixed *params)
{
 int skill, light;

 skill = params[0];

 if((int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Not enough GP too complete spell.\n");
  return 0;
 }
 say((string)previous_object()->query_cap_name()+
  " speaks some strange words, and "
  "suddenly the room gets brighter.\n", previous_object());
 tell_object(previous_object(), 
   "The room brightens as you complete your spell.\n");

 environment(previous_object())->adjust_light(skill/10);

 return 50;
}
