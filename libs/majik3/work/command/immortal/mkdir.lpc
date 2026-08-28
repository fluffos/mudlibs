int
main (string str)
{
  int ret;

  if (!str) {
    notify_fail ("usage: mkdir <directory>\n");
    return 0;
  }

  if (!absolute_path (str))
    str = this_player()->query_cwd() + str;

  str = resolve_path (str);

  ret = mkdir (str);

  if (!ret)
    {
      notify_fail ("Failed to make directory.\n");
      return 0;
    }
  return 1;
}

