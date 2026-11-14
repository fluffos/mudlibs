 
lines(arg) {
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if (arg == "on") {
      write("Line numbers will be shown.\n");
      disp_lines = 1;
   }
   else if (arg == "off") {
      write("Line numbers will not be shown.\n");
      disp_lines = 0;
   }
   else
      write("Please use 'on' or 'off' as argument.\n");
   return 1;
} 
 
