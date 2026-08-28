int
main (string str)
{
  int ret;

  if (!str) {
    notify_fail ("usage: rmdir <directory>\n");
    return 0;
  }

  if (!absolute_path (str))
    str = this_player()->query_cwd() + str;

  str = resolve_path (str);

  if (file_size (str) != -2) {
    notify_fail (str + ": No such directory.\n");
    return 0;
  }

  rmdir (str);

  return 1;
}

