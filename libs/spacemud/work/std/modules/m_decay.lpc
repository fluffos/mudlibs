/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// This module can be used to make objects decay after a set
// amount of time. You may also have an object decay in stages.
/*
** Coded by Kinison@Private Idaho - June 18, 1996
** Rewritten by Tsath, 2020, to use STATE_D and to function for
** mobs as well as players.
*/

inherit M_STATEFUL;

private
int num_decays, decay_time;
private
mixed decay_action;
private
mixed last_decay_action;
private
int tag;
private
int auto_remove;
private
int decays = 1;
int decay_begun;

void remove();

//: FUNCTION set_decay_action
// set_decay_action(string) causes 'string' to be printed this
// object decays.  set_decay_action(function) causes the function
// to be called instead.
// If action contains a "$", it's assumed to be a message, and called via
//  env()->simple_action(action,this_object());
void set_decay_action(mixed action)
{
   decay_action = action;
}

int decays()
{
   return 1;
}

//: FUNCTION set_last_decay_action
// same as set_decay_action but only on the last decay.
void set_last_decay_action(mixed action)
{
   last_decay_action = action;
}

int decay_begun()
{
   return decay_begun;
}

//: FUNCTION set_num_decays
// This sets the number of stages to decay in.
int set_num_decays(int num)
{
   return (num_decays = num);
}

void set_decay_auto_remove(int i)
{
   auto_remove = i;
}

int query_num_decays()
{
   return num_decays;
}

//: FUNCTION set_decay_time
// void set_decay_time(int num)
// Set the length of time that it takes to decay this item.
// setting this makes the item decayable, not setting this varriable will not
// make it decay.
void set_decay_time(int num)
{
   set_call_interval(num);
}

// Decay at this time and remove the object if at the last decay.
int decay_it()
{
   mixed action;
   decay_begun = 1;

   if (num_decays == 1 && last_decay_action)
      action = last_decay_action;
   else
      action = decay_action;

   if (0)
      TBUG("m_decay: action=" + action + " decay_begun: " + decay_begun + " num_decays: " + num_decays +
           " auto_remove: " + auto_remove);

   if (stringp(action))
   {
      if (environment() && environment()->is_living())
      {
         if (strsrch(action, "$") != -1)
            environment()->simple_action(action, this_object());
         else
            tell(environment(), action + "\n");
      }
      else
         object_event(action);
   }
   else
      evaluate(action);

   num_decays--;

   if (num_decays <= 0 && auto_remove)
      remove();
   if (!num_decays)
      return 0;
   return 1;
}

int state_update()
{
   if (decays)
      if (decay_it())
         return 1;
   return 0;
}

void stop_decay()
{
   STATE_D->remove_from_queue(this_object());
}

void mudlib_setup()
{
   m_stateful::mudlib_setup();
   this_object()->add_save(({"num_decays"}));
}