// Last edited by deforce on 12-08-2007
#include <mudlib.h>
inherit CMD;

void main(mixed width)
{
   width = to_int(width);

   if (!intp(width))
   {
      out("Screen width must be a number.\n");
      return;
   }
   else if (!width)
   {
      out("Your current screen width is " + this_user()->query_screen_width() + ".\n");
      return;
   }
   else if (width < 10)
   {
      out("Screen width must be at least 10.\n");
      return;
   }

   this_user()->set_screen_width(width);
   out("Screen width set to " + width + ".\n");
}