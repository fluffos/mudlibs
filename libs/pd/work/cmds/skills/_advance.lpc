#include <daemons.h>
#include <std.h>
#include <tirun.h>
inherit DAEMON;

int cmd_advance(string str) {
  if (this_player()->query_class() != "wanderer") return 0;
  //    return load_object(ROOMS+"/wanderer_hall")->advance(str);
  ADVANCE_D->advance_level(this_player());
  return 1;
}

void help() {
  if (this_player()->query_class() == "wanderer")
    write("
Syntax: <advance>
This ability will allow you to advance your level. You must have
the amount of experience required to advance to the next level
before doing this. Type <cost> to see how you're doing as far as 
accumulating experience towards advancing.
");
else
write("
Syntax: <advance>
Go to your class hall and type this in order to advance in level.
You must have the necessary amount of experience needed to advance
to the next level before doing this. Type <cost> to see how you're
doing as far as accumulating experience towards advancing.
");
}

int abil() {
   if (this_player()->query_class() != "wanderer") return 0;
   return 1;
}
