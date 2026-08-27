/*** Resist Cold Spell ***/
/*** Created by Eerevann Tokani ***/


#define SP_NAME "Resist Cold"
#define GP_COST 4
#define TYPE "cold"


string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Protection\n"
       "Level: 2nd\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "    This spell reduces damage done by Cold based attacks "
       "by 50%.  The duration is based upon the casters level.\n\n";
       

}

mixed spell(string str, int skill, int cast);

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
  write("You start to cast "+SP_NAME+".\n");
  say(this_player()->query_cap_name()+" begins to cast a spell.\n",
     previous_object());
  return 1;
  }

mixed spell(string str, int skill, int cast)
{
  mixed ob;

  if ((int)this_player()->query_spell_effect("defensive"))
    return "You are already casting an defensive spell.\n";
  ob = find_match(str, environment(this_player()));
  if (sizeof(ob))
    ob = ob[0];
  else
    ob = 0;

  this_player()->add_spell_effect(1, "defensive", SP_NAME,
    this_object(), "hb_spell", ({ skill,ob,cast }));
  return 1;
}

int hb_spell(object caster, mixed *params)
{
  int resist_value;
  int level;

  if (!params[1])
  {
    tell_object(this_player(),
      "Your spell failed ... there is no one of that name here.\n");
    return 0;
  }
  if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
  {
    tell_object(previous_object(), "You fail to draw enough energy from "
     "your god.\n");
    return 0;
  }
    
  say((string)previous_object()->query_cap_name()+
   " chants, 'frosz rissas cleios'.\n", ({params[1],previous_object()}));
    
  if(params[1] == previous_object())
   { 
    tell_object(params[1], "You chant, 'frosz rissas cleios'.\n");
    tell_object(params[1], "You cast "+SP_NAME+" upon yourself.\n");
    say((string)previous_object()->query_cap_name()+
      " casts a spell upon "+params[1]->query_objective()+"self.\n",params[1]);
   }
  else
  {
   tell_object(previous_object(), "You chant, 'frosz rissas cleios'.\n");
   
   tell_object(params[1], (string)previous_object()->query_cap_name() +
    " chants, 'frosz rissas cleios'.\n");
   
   tell_object(params[1], "You feel resistant to Cold attacks.\n");
   
   tell_object(previous_object(), "You cast "+SP_NAME+" on "+
    (string)params[1]->query_cap_name() + ".\n");
   
   say((string)previous_object()->query_cap_name()+
    " casts a spell upon "+params[1]->query_cap_name()+".\n",
       ({params[1],previous_object()}) );
  }

  resist_value = 50;

  params[1]->add_property(TYPE,resist_value);
  
  call_out("wear_off",50+(level*6),params[1]);
  return GP_COST;
}

void wear_off(object target)
{
  if(target)
  {
    target->add_property(TYPE,0);
   tell_object(target, "Your "+SP_NAME+" wears off.\n");
  }
}
