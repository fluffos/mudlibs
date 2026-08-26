/* cp command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

mixed cmd(string str) {
  string *filenames, text, dest, *fnames, err;
  int loop, fs;

  if(!str)
    return notify_fail("Usage : cp file [file|dir...]\n");
  fnames = explode(str, " ");
  filenames = this_player()->get_files(implode(fnames[0..sizeof(fnames) -2],
                                               "/"));
  filenames = filter(filenames, (:$1[<1] != '.':));
  if(!sizeof(filenames)) {
    notify_fail("Usage : cp file [file|dir...]\n");
    return 0;
  }
  dest = fnames[sizeof(fnames) - 1];
  dest = this_player()->get_path(dest);
  if(!dest) {
    write("No destination\n");
    return 1;
  }
  for(loop = 0; loop < sizeof(filenames); loop++) {
    str = filenames[loop];
    text = read_file(str);
    if(!text) {
      write("No such file : " + str + "\n");
      continue;
    }
    fs = file_size(dest);
    if(fs == -2) {
      string *names;

      names = explode(str, "/");
      fs = file_size(dest + "/" + names[sizeof(names) - 1]);
      if(fs != -1) {
        write("file exists " + dest + "/" + names[sizeof(names) - 1] + "\n");
        continue;
      }
      write_file(dest + "/" + names[sizeof(names) - 1], text);
    }
    else {
      if(fs != -1) {
        write("File exists : " + dest + "\n");
        continue;
      }
      if(err = catch(write_file(dest, text))) {
  return notify_fail(err+"\n");
      }
    }
  }
  write("Ok.\n");
  return 1;
}

