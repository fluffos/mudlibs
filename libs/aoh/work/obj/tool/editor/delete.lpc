 
delete(arg) {
   int start,end,temp_line,diff;
   string range;
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if (!arg) {
      write("Please give a line number or a range.\n");
      return 1;
   }
   range = get_range(arg);
   if (range == "error") return 1;
   sscanf(range,"%d-%d",start,end);
   buf_delete(start,end);
   write("Lines " + start + "-" + end + " deleted!\n");
   return 1;
}
 
