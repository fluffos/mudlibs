inherit TRANSIENT;

int strength;
string action;

private
void poison_action()
{
   object env = environment();

   if (action && env && env->is_living())
      if (action[0] != '!')
         env->simple_action(action);
      else
         tell(env, action[1..]);

   // If we're not inside an environment and it's not a ghost
   if (env && !env->query_ghost() && env->is_living())
   {
      env->hurt_us(random(strength) + 1, "torso");
   }
   else
   {
      this_object()->remove();
   }
}

int query_poison_strength()
{
   return strength;
}

int do_effect()
{
   poison_action();
}

void extend_effect(object t)
{
   if (t)
   {
      strength += t->query_poison_strength();
      ::extend_effect(t);
   }
   else
   {
      TBUG("No target sent!");
   }
}

void mudlib_setup(int s, int d, string a)
{
   transient::mudlib_setup();
   add_save(({"action", "strength"}));
   set_effect_type("poison");
   set_effect_name("some kind of poison");
   strength = s;
   set_effect_duration(d / 2);
   action = a;
}