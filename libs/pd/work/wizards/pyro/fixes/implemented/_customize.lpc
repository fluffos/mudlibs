#include <std.h>

int cmd_customize(string str)
{
 string line, color;
// mapping line;

 if (!str || str=="")
    return notify_fail("Customize what line with what color?\n");
 if (str=="list")
   {
    line = this_player()->query_line_color();
    return 1;
   }
 if ( sscanf(str, "%s with %s", line, color) != 2 )
   return notify_fail("Customize what line with what color?\n");

 if (member_array(line, this_player()->query_channels())==-1)
   return notify_fail("You do not have that line.\n");

 this_player()->set_line_color(line, color);
 write("The "+line+" line is now: "+color+"<"+line+">%^RESET%^.");
 return 1;
}

int help()
{
  write( @EndText
Syntax: customize <line> with <%%^RESET%^^COLOR%%^RESET%^^>
Effect: allows you to customize line colors.

EndText
  );
  return 1;
}
