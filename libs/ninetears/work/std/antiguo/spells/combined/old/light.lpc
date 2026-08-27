/*** Priest Light Spell ***/
/*** Revised by: Eerevann ***/

/*** Sun Sphere ***/
/*** level 1 ***/



#define GP_COST 2

mixed spell(string str, int skill, int cast);

string help() {
   return
   "\n\n"
   "Spell Name:  Light\n"
   "Sphere:  Sun\n"
   "Level: 1st\n"
   "Gp Cost: 30\n"
   "Description: \n"
   "    This spell will create a small globe of light that is placed upon "
   "the target to help illuminate dark areas.  This spell must be cast on a "
   "target of some sort.\n"
   "    The spell has a limited duration.\n\n";
}

int cast_spell(string str)
{
 int skill;
 mixed ret;

 str = (string)this_player()->expand_nickname(str);


 ret = spell(str, skill, 1);
 if (stringp(ret))
 {
  notify_fail(ret);
  return 0;
 }
 write("You begin to cast Light.\n");
 say(this_player()->query_cap_name()+" begins to cast a spell.\n");
 return 1;
}

mixed spell(string str, int skill, int cast)
{
 mixed ob;
 if ((int) this_player()->query_spell_effect("misc"))
  return "You are already casting a miscelleanous spell.\n";

 ob = find_match(str, environment(this_player()));

 if(sizeof(ob))
  ob = ob[0];

 else
  ob = 0;

 this_player()->add_spell_effect(1, "misc", "Light", this_object(),
  "hb_spell", ({ skill,ob,cast }));

 return 1;
}

int hb_spell(object caster, mixed *params)
{
 int skill, light;
 mixed who;


 if(!params[1])
 {
  tell_object(previous_object(), "Your light spell fizzles since you "
   "can't see it's intended target.\n");
  return 0;
 }

 if(params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
 {
  tell_object(previous_object(), "Your mind is too weary to cast.\n");
  return 0;
 }

 if (params[1] == previous_object())
 {
  tell_object(previous_object(),"You will now be able to see in any dark "
   "room.\n");
  say((string)previous_object()->query_cap_name() +
   " raises his hands and a globe of light appears.\n", params[1]);
 }

 else
 {
  tell_object(previous_object(),"You cast light on "+
   (string)params[1]->query_cap_name()+", who starts to glow with light.\n");
  say((string)previous_object()->query_cap_name()+ "mumbles something and "+
   (string)params[1]->query_cap_name()+" starts to glow with light.\n", params[1]);
  tell_object(params[1], (string)previous_object()->query_cap_name()+
   " points at you and a globe of light appears in your hand.\n");
 }

 params[1]->set_light(60);
 call_out("wear_off", 500, params[1]);

 return GP_COST;
}

void wear_off(object target)
{
 target->set_light(0);
 tell_object(target,"Your globe of light disappears.\n");
 say(target->query_cap_name()+" stops glowing with light.\n",target);

}
