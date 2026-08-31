/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_GETTABLE;
inherit M_GRAMMAR;

void show_hints(mixed hints)
{
   int w = this_user()->query_screen_width() - 5;
   if (stringp(hints))
      hints = ({hints});
   if (!sizeof(hints))
      return;
   for (int i = 0; i < sizeof(hints); i++)
   {
      hints[i] = XTERM256_D->xterm256_wrap(hints[i], w, 5);
   }
   tell(environment(this_object()), "%^HINTS%^Hints%^RESET%^:\n   - " + implode(hints, "\n   - ") + "\n");
}

object *find_hint_items()
{
   return all_inventory(environment(environment(this_object()))) + // Everything in the room
          ({environment(environment(this_object()))});             // The room itself
}

void hint_from(mixed something)
{
   if (objectp(something))
   {
      show_hints(something->query_hint(environment()->query_level()));
   }
   else
      show_hints(something);
}

void hook_func()
{
   object *items;
   string *hints = ({});
   if (!environment() || !environment(environment()))
      return;
   items = find_hint_items();
   foreach (object item in items)
   {
      mixed hint = item->query_hint(environment()->query_level());
      if (arrayp(hint))
      {
         map(hint, ( : punctuate:));
         hints += hint;
      }
      else
         hints += ({punctuate(hint)});
   }
   hints = filter_array(hints, ( : $1 && strlen($1) > 1 :));
   if (sizeof(hints) && find_call_out("show_hints") == -1)
      call_out("show_hints", 0, hints);
}

void dropped()
{
   if (!this_body())
      return;
   if (environment(this_object())->is_living())
      return;
   // Clean up the hooks
   remove_hook("move", ( : dropped:));
   this_body()->remove_hook("move", ( : hook_func:));
   this_body()->simple_action("$N $vdrop " + short() + " which disappears in a puff of smoke.");

   this_object()->remove();
}

string get_extra_long()
{
   return "\n%^HINTS%^Hints:\n%^RESET%^  This is an example hint.";
}

void mudlib_setup()
{
   ::mudlib_setup();
   set_id("hint token", "token", "hint_token");
   set_proper_name("a hint token");
   set_weight(0.01);
   set_long("This small hint token will provide hints whereever you go. The token will "
            "disappear if you drop it. The hints may change as you level up. Using 'hints <item>' to check a specific "
            "item you "
            "carry for hints.\n\n"
            "You can use 'hints on' to get a new one should you lose this one.");
   this_body()->add_hook("move", ( : hook_func:));
   add_hook("move", ( : dropped:));
}

string query_hint()
{
   return "Yes, this token will give you hints.";
}