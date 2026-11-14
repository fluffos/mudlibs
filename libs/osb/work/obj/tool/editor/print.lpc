 
print(arg) {
   int start,end;
   string range;
   
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if (!arg) {
      write("Please give a line number or a range.\n");
      return 1;
   }
   if (arg == "here") {
      start = cur_line - (chunk_size/2-1);
      if (start<1) start = 1;
      end = start + (chunk_size);
      if (end > last_line()) end = last_line();
   }
   else if (arg=="more") {
      start = cur_line+1;
      if (start<1) start = 1;
      end = start + (chunk_size-1);
      if (end > last_line()) end = last_line();
   }      
   else if (arg=="less") {
      start = cur_line - (chunk_size*2-1);
      if (start<1) start = 1;
      end = start + (chunk_size-1);
      if (end>last_line()) end = last_line();
   }
   else {
      range = get_range(arg);
      if (range == "error") return 1;
      sscanf(range,"%d-%d",start,end);
   }
   while (start <= end) {
      write( align_num(start) + buf_read(start) + "\n");
      start++;
   }
   cur_line = end;
   return 1;
}
 
