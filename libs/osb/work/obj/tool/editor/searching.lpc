 
find(arg) {
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if (!arg)
      write("Please give a string to search for.\n");
   else { 
      cur_line = 0;
      find_string = arg;
      next();
   }
   return 1;
}
 
next(arg) {
   int old_cur, is_found;
   string str;
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if ( (find_string=="") && (arg="") ) {
      write("No search string specified.\n");
      return 1;
   }
   if (arg) find_string = arg;
   old_cur = cur_line;
   is_found = 0;
   for (cur_line++; (!is_found) && (cur_line<=last_line()); cur_line++)
      if (sscanf(buf_read(cur_line),"%s"+find_string+"%s",str,str)==2)
         is_found = 1;
   cur_line--;
   if (is_found)
      write( align_num(cur_line) + buf_read(cur_line) + "\n");
   else {
      write( "String not found.\n");
      cur_line = old_cur;
   }
   return 1;
}      
 
prev(arg) {
   int old_cur, is_found;
   string str;
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1; }
   if ( (find_string=="") && (arg="") ) {
      write("No search string specified.\n");
      return 1;
   }
   if (arg) find_string = arg;
   old_cur = cur_line;
   is_found = 0;
   for (cur_line-- ; (!is_found) && (cur_line>0) ; cur_line-- )
      if (sscanf(buf_read(cur_line),"%s"+find_string+"%s",str,str)==2)
         is_found = 1;
   cur_line++;
   if (is_found)
      write( align_num(cur_line) + buf_read(cur_line) + "\n");
   else {
      write( "String not found.\n");
      cur_line = old_cur;
   }
   return 1;
}
 
