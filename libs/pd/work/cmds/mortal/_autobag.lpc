//Autobagger by Nightshade 9-17-02

#include <std.h>

inherit DAEMON;

int cmd_autobag(string str) {

  if (!str || str=="") {
    this_player()->remove_property("autobag");
    write("Autobagging turned off.");
    return 1;
  }
  if(sscanf(str,"into %s", str) != 1)
    return notify_fail("Syntax: <autobag into [container]>\n");
  this_player()->remove_property("autobag");
  this_player()->set_property("autobag", str);
  write("You will now autobag into your "+str+".");

  return 1;
}
int help()
{
  write( @EndText
Syntax: <autobag into [container]>
Effect: Will automatically put things you get off a corpse into the container.  <autobag> by itself will turn off autobagging.
See also: sacrifice
EndText
  );
  return 1;
}
