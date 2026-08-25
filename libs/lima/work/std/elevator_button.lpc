// Do not remove the headers from this file! see /USAGE for more info.
inherit OBJ;

string dest;
string key = "";

mixed do_press();
mixed direct_press_obj();

string long()
{
   return "The button is marked '" + (key ? "(" + key + ") " : "") + capitalize(dest) + "'\n";
}

string query_destination()
{
   return dest;
}

void setup(string d, string k)
{
   set_attached(1);
   set_adj("elevator");
   set_id("button");
   dest = d;
   if (k)
   {
      set_id(k);
      key = k;
   }
   add_adj(d);
}

mixed do_press()
{
   environment(this_object())->handle_press((strlen(key) > 0 ? key + "/" : "") + dest);
   return 1;
}

mixed direct_press_obj()
{
   return 1;
}
