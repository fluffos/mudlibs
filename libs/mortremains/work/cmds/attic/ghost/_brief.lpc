/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

inherit "/std/cmd_m";

int cmd_brief() {
   int brief;
   brief = (int)previous_object()->query("brief");
   if(brief) {
      write("Verbose mode.\n");
      this_player()->set("brief", 0);
   } else {
      write("Brief mode.\n");
      this_player()->set("brief", 1);
   }
   return 1;
}
