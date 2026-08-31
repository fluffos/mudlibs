/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_MESSAGES;

//: MODULE
// M_ASSISTANCE for having mobs help each other when under attack. This module
// requires M_MESSAGES for the grunt work.
//
// .. TAGS: RST

private
string helper;

void add_helper(string h)
{
   helper = h;
}

int check_wander(object helper)
{
   string *areas = environment(this_object())->query_area();

   if (present(helper, environment()))
      return 1;

   // If we do not wander, we do not assist.
   if (sizeof(helper->query_wander_area()) == 0)
      return 0;

   foreach (string area in areas)
   {
      if (member_array(area, helper->query_wander_area()) != -1)
         return 1;
   }
   return 0;
}

object *query_helpers()
{
   string *directions;
   object *candidates = ({});
   if (environment(this_object()))
      directions = environment(this_object())->query_exit_directions(1);

   candidates += all_inventory(environment());

   foreach (string dir in directions)
   {
      object room = find_object(environment(this_object())->query_exit_destination(dir));
      if (room)
         candidates += all_inventory(room);
   }

   candidates = filter_array(candidates, ( : $1->id(helper) && $1 != this_object() && !$1->is_body() :));
   candidates = filter_array(candidates, ( : check_wander($1) :));

   return candidates;
}

void assist_action(object who)
{
   targetted_action("$N $varrive to assist $t!", who);
}

void callout_help(object helper)
{
   if (environment(helper) != environment(this_object()))
   {
      helper->assist_action(this_object());
      helper->move(environment(this_object()));
   }

   // Move if we have a target, but our helper does not.
   if (this_object()->query_target() && !helper->query_target())
   {
      helper->start_fight(this_object()->query_target());
      helper->targetted_action("$N %^COMBAT_CONDITION%^$vassist%^RESET%^ in attacking $t",
                               this_object()->query_target());
   }
}

void get_help()
{
   foreach (object helper in query_helpers())
   {
      call_out(( : callout_help:), random(3) + 1, helper);
   }
}
