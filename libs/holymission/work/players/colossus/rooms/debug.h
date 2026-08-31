nosave int debug;

debug() {
   if (!debug) {
      debug = 1;
      write("Debugging in "+file_name(this_object())+" is ON.\n");
      return;
   }
   else {
      debug = 0;
      write("Debugging off in "+file_name(this_object())+"\n");
      return;
   }
}              
