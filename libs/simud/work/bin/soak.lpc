int main(string arg) {
   int x, soak = this_player()->query_soak();
   if (!this_player()->query_skill("other.endurance")) {
     msg("You must have skill in the ~CBRTother.endurance~CDEF skill if you "+
         "want to soak damage.");
     return 1;
   }
   if (arg == "on") {
     x = 1;
     msg("You will now attempt to soak damage into your endurance.");
   } else if (arg == "off") {
     x = 0;
     msg("You will no longer attempt to soak damage.");
   } else {
     msg("You are "+(soak?"":"not ")+"currently soaking damage.\n"+
         "Type ~CCOMsoak "+(soak?"off":"on")+"~CDEF to change that.");
     return 1;
   }
   this_player()->set_soak(x);
   return 1;
}
