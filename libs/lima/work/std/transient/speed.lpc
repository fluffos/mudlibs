/* Do not remove the headers from this file! see /USAGE for more info. */

inherit TRANSIENT;

int strength;
string action;

private
void speed_action()
{
   object env = environment();
   if (action && env && env->is_living())
      if (action[0] != '!')
         env->simple_action(action);
      else
         tell(env, action[1..]);
   env->set_attack_speed(strength);
}

int query_boost_strength()
{
   return strength;
}

int do_effect()
{
   speed_action();
}

void extend_effect(object t)
{
   if (t)
   {
      ::extend_effect(t);
   }
}

void remove()
{
   object env = environment();
   if (env)
      env->set_attack_speed(0);
   else
   {
      TBUG("We lost our environment! May have player with high attack speed");
   }

   ::remove();
}

void mudlib_setup(int s, int d, string a)
{
   transient::mudlib_setup();
   add_save(({"action", "strength"}));
   set_effect_type("speed");
   set_effect_name("speed drug");
   strength = s;
   set_effect_duration(d);
   action = a;
}