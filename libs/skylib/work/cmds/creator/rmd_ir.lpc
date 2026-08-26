/* rmdir command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd(string str) {
   string *filenames;
   int fsize, loop;
 
   seteuid(geteuid(this_player()));
   if (!str || str == "") {
      notify_fail("Remove what dir?\n");
      return 0;
   }
   filenames = this_player()->get_files(str);
   if (!sizeof(filenames)) {
      notify_fail("No such directory : " + str + "\n");
      return 0;
   }
 
   for(loop = 0; loop < sizeof(filenames); loop++) {
      str = filenames[loop];
      fsize = file_size(str);
      if (fsize == -1) {
         notify_fail(str + " doesn't exist.\n");
         return 0;
      }
      if (fsize != -2) {
         notify_fail(str + " is not a directory.\n");
         return 0;
      }
      if (!rmdir(str)) {
         notify_fail("Couldn't remove dir : " + str + "\n");
         return 0;
      }
   }
   log_file( "RMED", ctime( time() ) + " : " + sprintf( "%-12s",
        TP -> query_name()) + str + "\n" ) ;
   write("Ok.\n");
   return 1;
}
