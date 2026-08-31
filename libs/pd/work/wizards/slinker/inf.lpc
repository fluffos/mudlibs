void query_access() {
   if (!access) write("Slinker is the only one allowed");
   else write("All others allowed.");
}

int set_access(int i) {
   if (this_player()->query_name() != "slinker") {
      write("Access denied.");
      return 1;
   }
   access = i;
}

mixed init() {
  ::init();
    if(this_player()->query_name() != "slinker" && !access)
{
      write("Access denied.");
      this_player()->move("/d/standard/square");
      return 1;
  }
   add_action("toggle", "toggle");
}

int toggle() {
   if (this_player()->query_name() != "slinker") {
      write("Access denied.");
      this_player()->move("/d/standard/square");
      return 1;
   }
   if (!access) {
      access = 1;
      write("All others now allowed.");
      return 1;
   }
   access = 0;
   write("Only Slinker allowed in right now");
   return 1;
}
