// Do not remove the headers from this file! see /USAGE for more info.
#include <hooks.h>

inherit MOVING_ROOM;

/* The destinations with their lamps lit */
string *queue = ({});
string door_direction = "nowhere";

void hook_elevator_door_closed();

private
void generate_panel_item()
{
   mapping stuff = (["adjs":({"elevator"}), "get":"The panel seems fixed to the elevator."]);
   string lookstr = "The panel has a number of buttons, all clearly marked:\n";
   foreach (string dest in sort_array(keys(dests), 1))
   {
      string key;
      if (sscanf(dest, "%s/%s", key, dest) == 2)
         lookstr += "\t[" + key + "] " + capitalize(dest) + "\n";
      else
         lookstr += "\t" + capitalize(dest) + "\n";
   }
   stuff["look"] = lookstr;

   add_item("panel", "buttons", stuff);
}

void setup_buttons()
{
   foreach (string dest in keys(dests))
   {
      string key;
      if (sscanf(dest, "%s/%s", key, dest) == 2)
         new ("/std/elevator_button", dest, key)->move(this_object());
      else
         new ("/std/elevator_button", dest, 0)->move(this_object());
   }
   generate_panel_item();
}

void setup()
{
   set_brief("Elevator");

   set_state_description("elevator_door_on", "\nThere is an open door to the " + door_direction + ".");
   set_state_description("elevator_door_off", "\nThere is a closed door to the " + door_direction + ".");

   set_in_progress(( : tell_from_inside, this_object(), "The elevator continues ...\n" :), 5);
   add_hook("elevator_door_closed", ( : hook_elevator_door_closed:));
}

void set_door_direction(string d)
{
   door_direction = d;
   set_state_description("elevator_door_on", "\nThere is an open door to the " + door_direction + ".");
   set_state_description("elevator_door_off", "\nThere is a closed door to the " + door_direction + ".");
}

private
int dest_exists(string dest)
{
   return member_array(dest, keys(dests)) != -1;
}

void move_to(string dest)
{
   if (!dest_exists(dest))
      error("Trying to move to '" + dest + "' but it's unknown.");
   ::move_to(dest);
}

void handle_queue()
{
   if (query_in_motion() || !sizeof(queue))
      return;

   call_hooks("elevator_will_move", HOOK_IGNORE, 0);
}

void hook_elevator_door_closed()
{
   if (!sizeof(queue))
      return;

   move_to(queue[0]);
}

string *queue()
{
   return queue;
}

/* add a destination to the queue. */
void add_to_queue(string where)
{
   if (member_array(where, queue) != -1)
   {
      return;
   }
   queue += ({where});
   handle_queue();
}

void handle_press(string dest)
{
   string key, newdest;
   if (!dest)
   {
      return;
   }

   if (sscanf(dest, "%s/%s", key, newdest) == 2)
      this_body()->simple_action("$N $vpress the '" + (key ? "[" + key + "] " : "") + capitalize(newdest) +
                                 "' button.\n");
   else
      this_body()->simple_action("$N $vpress the '" + capitalize(dest) + "' button.\n");

   if (query_where() == dest)
   {
      call_hooks("elevator_arrived", HOOK_IGNORE, 0, query_location());
   }
   else
   {
      add_to_queue(dest);
   }
}

void arrive()
{
   tell_from_inside(this_object(), "The elevator slows down and stops\n");
   ::arrive();
   queue -= ({query_where()});
   call_hooks("elevator_arrived", HOOK_IGNORE, 0, query_location());
}

int call_elevator(string where)
{
   if (!dest_exists(where))
   {
      error("Getting called to unknown '" + where + "' destination in " + environment(previous_object()) + ".");
      return 0;
   }

   if (query_where() == where)
   {
      call_hooks("elevator_arrived", HOOK_IGNORE, 0, query_location());
      return 2;
   }

   if (member_array(where, queue) != -1)
   {
      write("Nothing happens.\n");
      return 0;
   }

   add_to_queue(where);
   return 1;
}
