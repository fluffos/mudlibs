/* Do not remove the headers from this file! see /USAGE for more info. */

// This is an example of a transient spell object that is held transparently in the
// players inventory. This shield spell provides a magical shield that reduces incoming
// bludgeon damage by intercepting the combat event and modifying it if the damage
// type is "bludgeon".
//
// The strength, duration, etc of the shield is determined upon clone of the shield.
// If more shield spells are cast, the duration is extended. (Thanks TRANSIENT).

inherit TRANSIENT;

int strength;
string action;

private
void shield_action()
{
   object env = environment();
   if (!action || !env || !env->is_living())
      return;

   if (action[0] != '!')
      env->simple_action(action);
   else
      tell(env, action[1..]);
}

//: FUNCTION query_boost_strength
// Returns the boost strength of the shield.
int query_boost_strength()
{
   return strength;
}

//: FUNCTION do_effect
// Executes the shield action effect.
int do_effect()
{
   shield_action();
}

//: FUNCTION extend_effect
// Extends the duration of the shield effect.
// Passed the object of the effect to be extended.
void extend_effect(object t)
{
   environment()->simple_action("$P magical shield is renewed.");
   if (t)
      ::extend_effect(t);
}

class event_info effect_modify_event(class event_info evt)
{
   // Override in effects to impact combat event.
   if (member_array("bludgeon", evt.data[0]) != -1)
   {
      environment()->simple_action("A shield around $n lights up briefly.");
      evt.data[1] = evt.data[1] - 5 <= 0 ? 0 : evt.data[1] - 5;
   }
   TBUG(event_to_str(evt));
   return evt;
}

void remove()
{
   object env = environment();

   ::remove();
}

void mudlib_setup(int strength_par, int duration_par, string action_par)
{
   transient::mudlib_setup();
   set_effect_type("shield");
   set_effect_name("shield spell");
   strength = strength_par;
   set_effect_duration(duration_par);
   action = action_par;
}

// @new("/std/transient/shield",5,120,"A shimmering shield protects $n.")->move(.me)