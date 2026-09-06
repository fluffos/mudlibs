 
move_lines(arg) {
   string range, where; 
   int start, end, location;
 
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   if (sscanf(arg,"%s %s",range,where) != 2) {
      write("Error in syntax.\n");
      write("USAGE: move <range> <line>\n");
      return 1;
   }
   range = get_range( range );
   if (range == "error") return 1;
   sscanf( range,"%d-%d", start, end );
 
   location = get_line( where );
   if (location < 0) return 1;
   if ( (location>=start) && (location<=end) ) {
      write("ERROR: destination within range.\n");
      return 1;
   }
   buf_move( start, end, location );
   write("Lines " + start + "-" + end + " moved to " + location + ".\n" );
   return 1;
}
 
