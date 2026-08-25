/* Do not remove the headers from this file! see /USAGE for more info. */

inherit OBJ;
inherit M_STATEFUL;
inherit M_GRAMMAR;

mapping receiver_counts = ([]);
string *material = ({});
string success_action;
string fail_action;
string search_string;
int repeats = -1;

void mudlib_setup()
{
   m_stateful::mudlib_setup();
   set_call_interval(3 + random(5));
   set_attached();
}

void set_repeats(int r)
{
   repeats = r;
}

//: FUNCTION set_material_file
// Sets the file cloned when the player finds something.
void set_material_file(string f)
{
   material += ({f});
}

void set_material_files(string *fs)
{
   material = fs;
}

mapping receivers()
{
   return receiver_counts;
}

//: FUNCTION set_success_action
// Sets the action that happens when the player finds something. Since
// you can use the yield() function to return more than one thing, the syntax
// here is extended to include how many you find.
// i.e.
//   set_success_action("$N $vsearch the blackberry bush, and $vfind <wild blackberry>!");
//
// The action follows all other rules for these simple_action() calls.
void set_success_action(string a)
{
   success_action = a;
}

//: FUNCTION set_search_string
// Sets the string used when the player is search.
// See 'man busy_with'.
// i.e. set_search_string("searching for the trashcan");
void set_search_string(string ss)
{
   search_string = ss;
}

//: FUNCTION set_fail_action
// Sets the action that happens when the action fails.
void set_fail_action(string a)
{
   fail_action = a;
}

//: FUNCTION yield
// Returns the number of things given to the player by the material spawner.
// Override this and add random() or fixed numbers as you like.
int yield()
{
   return 1;
}

void fail_search()
{
   if (present(this_body(), environment()))
   {
      this_body()->simple_action(fail_action);
      if (!receiver_counts[this_body()->query_name()])
         receiver_counts[this_body()->query_name()] = 1;
      else
         receiver_counts[this_body()->query_name()]++;
   }
}

void give_material()
{
   if (present(this_body(), environment()))
   {
      object *mats = ({});
      string sa;
      int index_s = strsrch(success_action, "<");
      int index_e = strsrch(success_action, ">");
      int y = yield();

      if (!y)
         return fail_search();

      for (int i = 0; i < y; i++)
      {
         string mat = evaluate_path(choice(material), 0, 1);
         object m = new (mat);
         if (m)
            mats += ({m});
         else
         {
            error("File not found: " + mat);
         }
      }
      if (sizeof(mats) && strsrch(success_action, "<item>") != -1)
      {
         sa = replace_string(success_action, "<item>", mats[0]->a_short());
      }

      if (index_s != -1 && index_e != -1)
      {
         string word = success_action[index_s + 1..index_e-1];
         sa = replace_string(sa, "<" + word + ">", number_of(sizeof(mats), word));
      }

      this_body()->simple_action(sa);
      if (!receiver_counts[this_body()->query_name()])
         receiver_counts[this_body()->query_name()] = 1;
      else
         receiver_counts[this_body()->query_name()]++;
      mats->move(this_body());
   }
}

int state_update()
{
   if (repeats)
   {
      foreach (string name, int count in receiver_counts)
      {
         if (count > 0)
            receiver_counts[name]--;
         if (receiver_counts[name] == 0)
            map_delete(receiver_counts, name);
      }
      if (repeats > 0)
         repeats--;
      return 1;
   }
   return 0;
}

void do_search()
{
   this_body()->busy_with(this_object(), search_string, "search_action");
}

int search_action()
{
   if (!present(this_body(), environment()))
      return 0;

   if (member_array(this_body()->query_name(), keys(receiver_counts)) != -1)
   {
      fail_search();
   }
   else
      give_material();

   return 1;
}
