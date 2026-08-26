// Last edited by deforce on 12-08-2007
#include <mudlib.h>
inherit CMD;

void main(mixed lines)
{
   lines = to_int(lines);

   if (!intp(lines))
   {
      out("Screen height must be a number.\n");
      return;
   }
   else if (!lines)
   {
      outf("Your current screen height is %i.\n",
         to_int(this_user()->query_shell_ob()->get_variable("MORE")));
      return;
   }
   else if (lines < 3)
   {
      out("Screen height must be at least 3.\n");
      return;
   }

   this_user()->query_shell_ob()->set_variable("MORE", lines);
   out("Screen height set to " + lines + ".\n");
}