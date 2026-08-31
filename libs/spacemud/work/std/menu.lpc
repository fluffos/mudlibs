/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// Fancy menu, loosely based on /std/menu by John Viega (rust@virginia.edu) from 1995.
//
// Several examples for how to use this module in /obj/mudlib.
// "help","?","HELP","h" will always print out the menu again.
// Implement "h" shortcut as a standard to provide additional help text for your menu.
// "q" should always get the user out of the menu, unless you have a very good reason.
//
// This object consists of menus, that hold sections, that hold the menu items.
// Create the menu, sections and items, and add the sections to the menus,
// then add the menu items to the appropriate sections.
//
// Sections have colours you can specify via the codes in ``palette``, but you can also
// use "warning", "accent" and "title" to reuse the theme colours the user has picked
// if you do not want to specify new section colours that risk not fitting the themes.

#include <mudlib.h>

inherit M_INPUT;
inherit M_FRAME;

class menu_item
{
   string description;
   mixed action;
   int disabled;
   mixed choice_name; // should be a string if the user sets it.
   int prompt_after_action;
   function constraint;
}

class section
{
   mixed *items;
   mixed title;
   string colour;
   int sort;
}

class menu
{
   // Items should only ever be class menu:item*'s or string*'s, and
   // should be of uniform type.  If this is of type string,
   // The menu won't display options.
   // And if items is a string*, you'd better have a no_match_function,
   // because there won't be any class menu_itemS to match against.
   mixed *items;
   mixed title;
   mixed prompt;
   int allow_enter;
   function no_match_function;
   int num_columns;
   int dont_complete;
   string *current_choices;
}

protected void goto_menu(class menu);
protected
void display_current_menu();
protected
void prompt_then_return();

class menu current_menu, previous_menu;
private
int need_refreshing;
private
mapping section_layout;

protected
void remove()
{
   destruct();
}

int screen_width()
{
   return this_user()->query_screen_width();
}

class menu reset_menu(class menu m)
{
   m.items = ({});
   return m;
}

varargs protected class menu new_menu(string title, string prompt, int allow_enter, function no_match_function)
{
   class menu new_menu;

   new_menu = new (class menu);
   new_menu.items = ({});
   new_menu.title = title;
   new_menu.prompt = prompt;
   new_menu.allow_enter = allow_enter;
   new_menu.no_match_function = no_match_function;

   return new_menu;
}

varargs protected class section new_section(string title, string colour, int sort)
{
   class section new_section;

   new_section = new (class section);
   new_section.items = ({});
   new_section.title = title;
   new_section.colour = colour;
   new_section.sort = sort;

   return new_section;
}

varargs protected class menu new_prompt(string prompt, function callback, string *completions)
{
   class menu new_menu;

   new_menu = new (class menu);
   new_menu.prompt = prompt;
   new_menu.no_match_function = callback;
   new_menu.items = completions ? completions : ({});

   return new_menu;
}

varargs protected class menu_item new_menu_item(string description, mixed action, string choice_name, int prompt,
                                                function constraint)
{
   class menu_item new_menu_item;

   new_menu_item = new (class menu_item);
   new_menu_item.description = description;
   new_menu_item.action = action;
   new_menu_item.choice_name = choice_name;
   new_menu_item.prompt_after_action = prompt;
   new_menu_item.constraint = constraint;

   return new_menu_item;
}

protected
void add_section_item(class menu menu, class section section)
{
   if (!menu)
      error("Trying to add '" + section.title + "' section to undefined menu.");
   menu.items += ({section});
}

protected
void remove_section_item(class menu menu, class section section)
{
   menu.items -= ({section});
}

protected
void add_menu_item(class section section, class menu_item menu_item)
{
   section.items += ({menu_item});
}

protected
void set_menu_items(class menu menu, class section *sections)
{
   menu.items = sections;
}

protected
void set_menu_title(class menu menu, string title)
{
   menu.title = title;
}

protected
void set_menu_prompt(class menu menu, mixed prompt)
{
   if (!(stringp(prompt) || functionp(prompt)))
   {
      error("Bad type arg 2 to set_menu_prompt");
      return;
   }

   menu.prompt = prompt;
}

protected
void allow_empty_selection(class menu menu)
{
   menu.allow_enter = 1;
}

protected
void disallow_empty_selection(class menu menu)
{
   menu.allow_enter = 0;
}

protected
void set_no_match_function(class menu menu, function f)
{
   menu.no_match_function = f;
}

protected
void set_number_of_columns(class menu menu, int n)
{
   menu.num_columns = n;
}

protected
void disable_menu_item(class menu_item item)
{
   item.disabled = 1;
}

protected
void enable_menu_item(class menu_item item)
{
   item.disabled = 0;
}

protected
void set_menu_item_description(class menu_item item, string description)
{
   item.description = description;
}

protected
void set_menu_item_action(class menu_item item, mixed action)
{
   //  Should type check here, but I can't figure out how
   //  to typecheck the class.
   item.action = action;
}

protected
void set_menu_item_choice_name(class menu_item item, string choice_name)
{
   item.choice_name = choice_name;
}

//: FUNCTION user_is_active
// Called when the user is active in the menu.
// Can be overriden for your own purposes.
void user_is_active()
{
   // Override me
}

protected
void constrain_menu_item(class menu_item item, function f)
{
   item.constraint = f;
}

// This variable is kind of a hack... when an action is taken
// (assuming that action is a function) this menu becomes the
// current menu.  This was done so that I could integrate completion
// menus as a real menu without having to go through and modify
// every single action
private
class menu menu_after_selection;

protected
void new_parse_menu_input(string input)
{
   string *matches;
   int i;
   class menu_item matched_item;
   class menu completion_menu;
   class section completion_section;

   completion_section = new_section("Completion", "<128>");
   add_section_item(completion_menu, completion_section);

   input = trim(input);
   user_is_active();
   if (input == "" && !current_menu.allow_enter)
   {
      return;
   }
   if ((i = member_array(input, current_menu.current_choices)) != -1)
   {
      matches = ({input});
   }
   else
   {
      if (current_menu.dont_complete)
      {
         if (functionp(current_menu.no_match_function))
         {
            evaluate(current_menu.no_match_function, input);
         }
         else
         {
            write("Invalid selection..\n");
         }
         return;
      }
      matches = M_REGEX->insensitive_regexp(current_menu.current_choices, M_GLOB->translate(input, 1));
   }
   switch (sizeof(matches))
   {
   case 0:
      write("Invalid selection.\n");
      return;
   case 1:
      if (!sizeof(current_menu.items) || stringp(current_menu.items[0]))
      {
         evaluate(current_menu.no_match_function, matches[0]);
         if (menu_after_selection)
         {
            goto_menu(menu_after_selection);
            menu_after_selection = 0;
         }
         return;
      }
      matched_item = filter_array(current_menu.items,
                                  (
                                      : intp(((class menu_item)$1)->choice_name)
                                            ? sprintf("%d", ((class menu_item)$1)->choice_name) == $2
                                            : ((class menu_item)$1)->choice_name == $2:),
                                  matches[0])[0];
      if (functionp(matched_item.action))
      {
         if (menu_after_selection)
         {
            goto_menu(menu_after_selection);
            menu_after_selection = 0;
         }
         evaluate(matched_item.action, input);
         need_refreshing = 1;
         if (matched_item.prompt_after_action)
            prompt_then_return();
         return;
      }
      goto_menu(matched_item.action);
      return;
   default:
      /*
            completion_menu = new_menu("Choose one by number:\n"
                                       "---------------------\n");
            set_menu_items(completion_menu,
                           filter_array(current_menu.items,
                                        (
                                            : intp(((class menu_item)$1)->choice_name)
                                                  ? member_array(sprintf("%d", ((class menu_item)$1)->choice_name), $2)
         != -1 : member_array(((class menu_item)$1)->choice_name, $2) != -1
                                            :),
                                        matches));
            add_menu_item(completion_menu, new_menu_item("Return to previous menu", current_menu));
            goto_menu(completion_menu);
            menu_after_selection = current_menu;
            */
   }
}

protected
void parse_menu_input(mixed input)
{
   int counter;
   class menu_item item;
   mixed action;

   user_is_active();

   if (input == -1)
   {
      remove();
      return;
   }
   input = trim(input);

   if (input == "" && !current_menu.allow_enter)
      return;

   if (input == "?" || lower_case(trim(input)) == "help")
   {
      display_current_menu();
      return;
   }

   foreach (class section section in current_menu.items)
   {
      foreach (item in section.items)
      {
         // Quick and sleazy way of knowing we're a prompt...
         if (stringp(item))
            break;
         if (item.disabled || (item.constraint && !evaluate(item.constraint)))
            continue;
         if ((!stringp(item.choice_name) && sprintf("%d", ++counter) == input) || input == item.choice_name)
         {
            action = item.action;
            if (functionp(action))
            {
               evaluate(action, input);
               need_refreshing = 0;
               if (item.prompt_after_action)
                  prompt_then_return();
               return;
            }
            goto_menu(action);
            return;
         }
      }
   }
   if (functionp(current_menu.no_match_function))
      evaluate(current_menu.no_match_function, input);
   else
      write("Invalid selection...\n");
}

protected
string get_current_prompt()
{
   mixed prompt;
   if (frame_simplify())
      return "";

   prompt = current_menu.prompt;
   if (need_refreshing)
      display_current_menu();
   if (!prompt)
   {
      // Build a smart default prompt.  This info and constraint info
      // could easily be cached....
      // the only thing not smart about this prompt is that it assumes
      // your choices are one character if you provide them yourself.
      // I did that because comma seperating choices is ugly.
      string s = "";
      string c;
      class menu_item item;
      int counter;
      foreach (class section section in current_menu.items)
         foreach (item in section.items)
         {
            if (item.disabled || (item.constraint && !evaluate(item.constraint)))
               continue;
            if (!c = item.choice_name)
            {
               counter++;
               continue;
            }
            s += c;
         }
      switch (counter)
      {
      case 0:
         s = sprintf("[%s] ", s);
         break;
      case 1:
         s = (s == "" ? "[1] " : sprintf("[1,%s] ", s));
         break;
      default:
         s = (s == "" ? sprintf("[1-%d] ", counter) : sprintf("[1-%d,%s] ", counter, s));
         break;
      }
      return s;
   }

   return stringp(prompt) ? prompt : evaluate(prompt);
}

protected
void init_menu_application(class menu toplevel)
{
   modal_push(( : parse_menu_input:), ( : get_current_prompt:));
   current_menu = toplevel;
   goto_menu(toplevel);
}

protected
void quit_menu_application()
{
   modal_pop();
   destruct(this_object());
}

protected
void goto_menu(class menu m)
{
   previous_menu = current_menu;
   current_menu = m;
   display_current_menu();
}

protected
void goto_menu_silently(class menu m)
{
   previous_menu = current_menu;
   current_menu = m;
}

protected
void goto_previous_menu()
{
   class menu swap;
   swap = current_menu;
   current_menu = previous_menu;
   previous_menu = swap;
}

string generate_section_output(class section *sections, int largest_section, int leftwidth, int rightwidth, int columns)
{
   string output = repeat_string(" ", (columns * (leftwidth + rightwidth + 4))) + "\n";
   string format = accent("%" + leftwidth + "s") + (frame_simplify() ? ", " : "") + " %-" + rightwidth + "s   ";
   class menu_item this_item;
   class menu_item empty_item = new_menu_item("", "", " ");
   int counter;

   // foreach (class section s in sections)
   //    TBUG(s.title);

   for (int i = 0; i < largest_section; i++)
   {
      int printed_columns = 0;
      foreach (class section section in sections)
      {
         int picked_col;

         if (section_layout[(string)section.title])
         {
            picked_col = section_layout[(string)section.title];
         }
         else
         {
            section_layout[(string)section.title] = printed_columns;
            picked_col = printed_columns;
         }

         if (i >= sizeof(section.items))
            this_item = empty_item;
         else
            this_item = section.items[i];
         if (this_item.disabled || (this_item.constraint && !evaluate(this_item.constraint)))
            continue;

         // TBUG("Name: " + this_item.description + " Picked:" + picked_col + " Printed:" + printed_columns);

         if (!this_item.choice_name)
         {
            error(sprintf("%O", this_item) + " has no choice_name.");
         }

         // We might need to move columns in.
         if (picked_col > printed_columns)
         {
            output += repeat_string(" ", ((picked_col - printed_columns) * (leftwidth + rightwidth + 4)));
            printed_columns++;
         }
         if (!stringp(this_item.choice_name) && strlen(this_item.choice_name))
         {
            if (strlen(this_item.description) > 0)
               output += sprintf(format, ++counter + "",
                                 frame_simplify() ? punctuate(this_item.description) : this_item.description);
            current_menu.current_choices += ({sprintf("%d", counter)});
            // Note, this will still get recalculated every time, since
            // we're setting it to an int, and not a string, but that's
            // what we want since we want the menus to be dynamic...
            // We set this for convenience of finding this menu item
            // without having to recalculate all this crap when it comes
            // time to process the choice.
            this_item.choice_name = counter;
            printed_columns++;
         }
         else if (strlen(trim(this_item.choice_name)) > 0)
         {
            output += sprintf(format, this_item.choice_name,
                              frame_simplify() ? punctuate(this_item.description) : this_item.description);
            current_menu.current_choices += ({this_item.choice_name});
            printed_columns++;
         }
      }

      if (printed_columns < columns)
      {
         output += repeat_string(" ", (columns - printed_columns) * (leftwidth + rightwidth + 4));
      }
      output += "\n";
   }
   return output + repeat_string(" ", (columns * (leftwidth + rightwidth + 4))) + "\n";
}

private
int section_sort(class section s, class section t)
{
   if (s.sort > t.sort)
      return 1;
   if (s.sort < t.sort)
      return -1;
   if (s.sort == t.sort)
      return -1;
}

private
void reorder_sections(class menu menu)
{
   menu.items = sort_array(menu.items, ( : section_sort:), 1);
}

void display_current_menu()
{
   int leftwidth;
   int rightwidth;
   int num_columns, end, sec_count;
   int largest_section;
   string *output = ({});
   string *tmp;
   class menu_item *all_items = ({});
   section_layout = ([]);

   need_refreshing = 0;
   if (!sizeof(current_menu.items) && !current_menu.no_match_function)
   {
      write(warning("Not implemented yet.\n"));
      current_menu = previous_menu;
      need_refreshing = 1;
      prompt_then_return();
      return;
   }

   if (!sizeof(current_menu.items) || stringp((current_menu.items)[0]))
   {
      current_menu.current_choices = ({});
      foreach (class section section in current_menu.items)
         current_menu.current_choices += current_menu.items;
      return;
   }

   reorder_sections(current_menu);

   foreach (class section section in current_menu.items)
      all_items += section.items;

   rightwidth = max(map(all_items, ( : strlen(((class menu_item)$1)->description) :)));
   // This stuff is getting as ugly as Amylaar closures =P
   leftwidth = max(map(all_items, ( : strlen(((class menu_item)$1)->choice_name) :)) + ({2}));

   largest_section = max(map(current_menu.items, ( : sizeof((class section)$1.items) :)));

   if (!current_menu.title)
      error("Menu doesn't have a title.");
   set_frame_header("header");
   set_frame_title(trim(current_menu.title));

   // Build this each time, and pass it on to the input handler,
   // because the menu may change....
   current_menu.current_choices = ({});

   tmp = ({});
   foreach (class section section in current_menu.items)
      tmp += ({({section.title, section.colour})});

   num_columns = clamp(query_width() / (rightwidth + leftwidth + 6), 0, sizeof(current_menu.items));
   if (num_columns <= 0)
   {
      write("Your client is too narrow for this layout. Please make it larger.");
      return;
   }

   set_frame_sections(tmp, rightwidth);

   while (sec_count < sizeof(current_menu.items))
   {
      end = sec_count + num_columns - 1;
      if (end + 1 >= sizeof(current_menu.items))
         end = sizeof(current_menu.items) - 1;
      // TBUG("Range: " + sec_count + ".." + end);
      output += ({generate_section_output(current_menu.items[sec_count..end], largest_section, leftwidth, rightwidth,
                                          num_columns)});

      sec_count += num_columns;
   }

   set_frame_content(output);
   write(menu_render());
}

private
void finish_completion(function completion_callback, string *cur_choices, string input)
{
   int i;

   if (input == "")
      return;

   if (input == "r")
   {
      goto_menu(current_menu);
      return;
   }

   if ((i = to_int(input)) < 1 || i > sizeof(cur_choices))
   {
      write("Invalid choice.\n");
      return;
   }

   evaluate(completion_callback, cur_choices[i - 1]);
   need_refreshing = 1;
}

varargs protected void complete_choice(string input, string *choices, function f)
{
   string *matches;
   int i;
   string output;
   TBUG(choices);

   if (input)
      matches = M_REGEX->insensitive_regexp(choices, M_GLOB->translate(input, 1));
   else
      matches = choices;
   switch (sizeof(matches))
   {

   case 0:
      write("Invalid selection.\n");
      break;

   case 1:

      evaluate(f, matches[0]);
      break;

   default:
      output = "Select choice by number\n"
               "-----------------------\n";
      for (i = 1; i <= sizeof(matches); i++)
         output += sprintf("%=3d)  %s\n", i, matches[i - 1]);
      modal_simple(( : finish_completion, f, matches:), "[Enter number or r to return to menu] ");
      more(output);
      break;
   }
}

protected
void get_input_then_call(function thencall, string prompt)
{
   input_one_arg(prompt, thencall);
}

protected
void prompt_then_return()
{
   /* just ignore the input... */
   modal_simple(( : 0 :), "[Hit enter to return to menu] ");
}

// ### probably should be protected too
void quit_if_cr(string input)
{
   if (input == "")
   {
      quit_menu_application();
      return;
   }
}
