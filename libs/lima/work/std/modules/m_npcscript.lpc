/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// m_npcscript (M_NPCSCRIPT)
//
// This object provides functionality for MOBILE adversaries to execute scripts at given intervals that involve a series
// of steps and checks along the way. Need your NPC to go buy a sandwich? This is the way.
//
// This modules inherits M_ACTIONS by itself. If triggers are used, inherit M_TRIGGERS in your mob as well.
// Only 1 trigger is supported at a time.

#include <npcscript.h>
inherit "/std/classes/script_step";
inherit M_ACTIONS;

private
mapping scripts = ([]);
int step_pause = 3;
string running_script;
int running_step;

void create_script(string name)
{
   scripts[name] = ({});
}

int add_steps(string name, class script_step *steps)
{
   if (!arrayp(scripts[name]))
      return 0;

   scripts[name] += steps;

   return 1;
}

varargs class script_step step(int type, mixed payload, mixed extra)
{
   class script_step ss = new (class script_step);
   ss.type = type;
   switch (type)
   {
   case SCRIPT_ACTION:
      if (stringp(payload))
      {
         string *more = explode(payload, "@@");
         if (sizeof(more) > 1)
            ss.multiple = more;
         else
            ss.action = (string)payload;
      }
      else if (functionp(payload))
         ss.func = (function)payload;
      break;
   case SCRIPT_TRIGGER:
      if (!function_exists("add_pattern", this_object()))
         error("Must inherit M_TRIGGERS to use triggers for NPC scripts.");
      ss.trigger = (string)payload;
      ss.action = (string)extra;
      break;
   case SCRIPT_WAIT:
      ss.wait = (int)payload;
      break;
   case SCRIPT_DESC:
      ss.in_room_desc = (string)payload;
      break;
   }

   return ss;
}

void execute_script(string name)
{
   // If we have ongoing conversations in M_CONVERSATION, exit those.
   // Also, disable conversations
   this_object()->exit_conversations();
   this_object()->set_can_talk(0);

   // Stop actions we might have running
   stop_actions();
   running_script = name;
   running_step = 0;
   call_out("next_step", step_pause);
}

void next_step()
{
   int next_call_out = step_pause;
   class script_step step;

   if (running_step >= sizeof(scripts[running_script]))
   {
      running_script = 0;
      running_step = 0;
      return;
   }
   step = scripts[running_script][running_step];

   if (running_step + 1 < sizeof(scripts[running_script]))
   {
      class script_step next_step;
      next_step = scripts[running_script][running_step + 1];
      if (next_step.type == SCRIPT_TRIGGER)
      {
         this_object()->add_pattern(next_step.trigger, next_step.action);
      }
   }

   switch (step.type)
   {
   case SCRIPT_ACTION:
      if (step.multiple && sizeof(step.multiple))
      {
         this_object()->do_game_command(step.multiple[0]);
         if (sizeof(step.multiple) > 1)
         {
            // Shorten the array, and go a step back so we don't progress.
            step.multiple = step.multiple[1..];
            running_step--;
         }
      }
      else if (step.action)
         this_object()->do_game_command(step.action);
      else
         evaluate(step.func);
      break;
   case SCRIPT_TRIGGER:
      return;
      break;
   case SCRIPT_WAIT:
      next_call_out = step.wait;
      break;
   case SCRIPT_DESC:
      this_object()->set_in_room_desc(step.in_room_desc);
      break;
   }

   running_step++;
   if (running_step >= sizeof(scripts[running_script]))
   {
      // Enable conversation again
      this_object()->set_can_talk(1);
      // Start actions from M_ACTIONS if we had any running.
      start_actions();
      return;
   }

   // Find next step
   step = scripts[running_script][running_step];

   // If next step is not a trigger, run it in call_out().
   if (step.type != SCRIPT_TRIGGER)
      call_out("next_step", next_call_out);
   else
   {
      // Triggers are added immediately.
      next_step();
   }
}

void triggered(string pattern)
{
   this_object()->remove_pattern(pattern);
   running_step++;
   call_out("next_step", step_pause);
}

mapping query_scripts()
{
   return scripts;
}