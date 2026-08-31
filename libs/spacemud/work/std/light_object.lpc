/* Do not remove the headers from this file! see /USAGE for more info. */

// light_object.c - Object to inherit for full functionality of a light
//                  source, light/extinguish verbs, and fuel.
// 26 June, 1998: Iizuka created.

#include <hooks.h>
#include <light.h>

inherit M_LIGHTABLE;
inherit M_LIGHT_SOURCE;
inherit M_DECAY;

private
string die_msg = "The light from the $o $vflicker and $vdie.";

void set_die_msg(string s)
{
   die_msg = s;
}

string query_die_msg()
{
   return die_msg;
}

protected
void set_lit(int x)
{
   m_lightable::set_lit(x);
   m_light_source::set_lit(x);
}

int is_lit()
{
   return m_lightable::is_lit();
}

mixed check_fuel()
{
   if (!query_num_decays())
      return object_event_message(query_burned_out_msg());
   return 1;
}

mixed extinguish()
{
   stop_decay();
   return ::extinguish();
}

mixed light()
{
   mixed tmp = check_fuel();
   if (tmp != 1)
      return tmp;

   // Call internal_add_to_queue() to make the light_object stateful when lit.
   internal_add_to_queue();
   return ::light();
}

// This object is only stateful when it's lit. Otherwise it's not.
int is_stateful()
{
   return is_lit();
}

void burn_out()
{
   set_light(0);
   set_num_decays(0);
   set_lit(0);
   call_hooks("extinguish", HOOK_IGNORE);
   object_event(die_msg);
}

void set_fuel(int x)
{
   set_num_decays(x);
}

void mudlib_setup()
{
   m_decay::mudlib_setup();
   set_decay_time(FUEL_DELAY);
   set_decay_action("$P $o flickers a little.");
   set_decay_auto_remove(1);
   set_last_decay_action(( : burn_out:));
}
