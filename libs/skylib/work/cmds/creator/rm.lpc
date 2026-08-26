/* rm command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd(string str) {
  int fsize, loop;
  string *filenames;
 
  seteuid(geteuid(this_player()));

  if (!str) {
    notify_fail("Usage: rm file [file ...]\n");
    return 0;
  }
  filenames = this_player()->get_files(str);
  if (!sizeof(filenames)) {
    notify_fail("No such file : "+ str+"\n");
    return 0;
  }
  for (loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    fsize = file_size(str);
    if (str[<2..] == "/." || str[<3..] == "/..")
      continue;
    if (fsize == -1) {
      notify_fail("No such file or directory.\n");
      return 0;
    }
    if (fsize == -2) {
      if (!rmdir(str)) {
        notify_fail("Couldn't rm directory: " + str + "\n");
        return 0;
      }
    } else if (!rm(str)) {
      notify_fail("Can't remove file.\n");
      return 0;
    }
  }
  log_file( "RMED", ctime( time() ) + " : " + sprintf( "%-12s",
        TP -> query_name()) + str + "\n" ) ;

  write("Ok.\n");
  return 1;
}
