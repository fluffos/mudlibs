// Last edited by deforce on 06-07-2008
#include <mudlib.h>
inherit CMD;

void main(string arg)
{
   int wimpy = to_int(arg);

   if (!arg)
   {
      out("Your wimpy is set to " + this_body()->query_wimpy() + "%, which is " + this_body()->query_wimpy_threshold() + " hit points.\n");
      return;
   }
   else if ((!wimpy && (arg != "0")) || (wimpy < 0))
   {
      out("Wimpy must be a positive number.\n");
      return;
   }
   else if ((wimpy < 0) || (wimpy > 50))
   {
      out("Wimpy must be from 0-50.\n");
      return;
   }

   this_body()->set_wimpy(wimpy);
   out("Wimpy set to " + wimpy + "% (" + this_body()->query_wimpy_threshold() + " hit points).\n");
}