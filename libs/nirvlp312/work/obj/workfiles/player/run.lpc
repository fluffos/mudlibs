/* Hacked by Shadowhawk the NUISANCE */
run_command_file(filename, except) {
  string lines;
  int index;

  filename = call_other(this_player(), "valid_read", filename);
  write("Filename: "+filename+"\n");
  filename = "/" + filename;
  if (file_size(filename) < 1) {
    write("No such file: " + filename + ".\n");
    return 1;
  }
  lines = grab_file(filename);
  for (index = 0; index < sizeof(lines); index++)
    if (sscanf(lines[index], except + "%s") < 1) {
      write("Executing: " + lines[index] + ".\n");
      command(lines[index], this_player());
    }
  return 1;
}

wiz_auto_exec() {
  write("Do you wish to execute your login file(y/N)?");
  input_to("wiz_auto_exec2");
}

wiz_auto_exec2(str) {
  if (lower_case(str)[0] != 'y') {
      write("Aborting execution of login file.\n");
      return 1;
   }
   run_command_file("/players/" + this_player()->query_real_name() +
      "/login", "quit");
   return 1;
}
