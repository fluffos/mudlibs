// Last edited by deforce on 10-07-2009
#include <flags.h>
#include <mudlib.h>
inherit CMD;

void test_flag(int);
string format_capacity(int percent);

private void main(string arg)
{
   object this_body = this_body();
   string list = "";

   if (arg == "concealed")
   {
      list = inv_list_include_concealed(all_inventory(this_body));
   }
   else
   {
      list = inv_list(all_inventory(this_body));
   }

   if (strlen(list))
   {
      out("You are carrying:\n" + list + "\n" + format_capacity(to_int(floor((this_body->query_capacity() * 100) / this_body->query_max_capacity()))));
   }
   else
   {
      out(format_capacity(to_int(floor((this_body->query_capacity() * 100) / this_body->query_max_capacity()))));
   }

   if (wizardp(this_body))
   {
      out(" (" + this_body->query_capacity() + " / " + this_body->query_max_capacity() + ", " + to_int(floor((this_body->query_capacity() * 100) / this_body->query_max_capacity())) + "%)");
   }
}

string format_capacity(int percent)
{
   switch (percent)
   {
      case 0..5: return "You are carrying close to nothing.";
      case 6..19: return "You barely notice the weight of your equipment.";
      case 20..39: return "You notice the weight of your equipment.";
      case 40..59: return "You feel the burden of the weight of your equipment.";
      case 60..79: return "You strain under the weight of your equipment.";
      case 80..100: return "You struggle to carry a heavy load.";
      case 101..99999: return "You are incredibly over-burdened.";
   }
}