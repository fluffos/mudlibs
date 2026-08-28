int
main (string str)
{
  if (!str) {
    notify_fail ("usage: rm <file>\n");
    return 0;
  }

  if (!absolute_path (str))
    str = this_player()->query_cwd() + str;

  str = resolve_path (str);

  if (file_size (str) < 0) {
    notify_fail (str + ": No such file or directory.\n");
    return 0;
  }

  rm (str);

  return 1;
}

