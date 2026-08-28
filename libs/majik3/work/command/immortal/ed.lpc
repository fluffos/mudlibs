int size1, size2;
string file;

exit_fn ()
{
  size2 = file_size(file);

  if (size1 < 1 && size2)
  write_file ("/log/ed", ctime(time()) + " :: " + capitalize(THIS->query_name()) +
    " created " + file + "\n");
  else if (size1 == size2)
  write_file ("/log/ed", ctime(time()) + " :: " + capitalize(THIS->query_name()) +
    " did not modify " + file + "\n");
  else if (size1 > size2)
  write_file ("/log/ed", ctime(time()) + " :: " + capitalize(THIS->query_name()) +
    " modified " + file + " to be smaller\n");
  else if (size1 < size2)
  write_file ("/log/ed", ctime(time()) + " :: " + capitalize(THIS->query_name()) +
    " modified " + file + "\n");
  else
  write_file ("/log/ed", ctime(time()) + " :: " + capitalize(THIS->query_name()) +
    " did something else to " + file + "\n");
  return 1;
}

int
main (string str)
{
  if (!str) {
    notify_fail ("usage: ed <file>\n");
    return 0;
  }

  if (!absolute_path (str))
    str = this_player()->query_cwd() + str;

  str = resolve_path (str);

  size1 = file_size(str);

  file = str;

  ed (str, "exit_fn", 1);

  return 1;
}

query_author() { return "namhas"; }

query_help()
{
  return "The ed-command will launch the MudOS line-editor. "+
         "Pass the desired filename and/or directory as argument. "+
         "For detailed help about using ed, use ed's internal help "+
         "by typing 'h' within the editor.";
}


