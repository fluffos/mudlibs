/*  NAME        : /command/immortal/ls.c                                   */
/*  DESCRIPTION : list contents of directories                             */
/*  CODER       : namhas                                                   */

int filtteri(string str)
{
    if (str[<2..<1] == ",v")
	return 0;
    if (str == "CVSROOT")
	return 0;
    return 1;
}

main (string str)
{
  string *junk, cwd, dir, buf = "";
  mixed *arr;

  cwd = THIS->query("cwd");

  if (str == "-l")
    {

      arr = get_dir(cwd, -1);
  for (int i=0;i<sizeof(arr);i++) {
    buf += sprintf("%-10s %4.1fK %-12s %s\n", "-", arr[i][1] ? arr[i][1]/1024.0 : 0.0, ctime(arr[i][2])[4..15], arr[i][0]);
  }

  message ("1", "^cc" + cwd + "^c0:\n", THIS);
  message ("0", buf, THIS);
  return 1;
  }      

  if (str)
    {
      if (!absolute_path(str))
        str = resolve_path(cwd + str);
      else
        str = resolve_path(str);
    }
  else
    str = cwd;

  if (!str || str == "")
   str = "/";

  if (file_size(str) == -2 && str[<1] != '/')
    str += "/";

  if (file_size(str) == -2)
    {
      dir = str;
      str += "*";
    }
  else
    dir = cwd;

  if (str[0] != '/')
    str = "/" + str;

  junk = get_dir(str);
  junk -= ({ ".", ".." });
    junk = filter_array(junk, "filtteri", THOB);

  for (int i=0;i<sizeof(junk);i++) {
    if (file_size(dir + junk[i]) == -2)
      junk[i] += "/";
    else if (file_size(dir + junk[i]) == -1)
      junk[i] += "@";
    else if (find_object(dir + junk[i]))
      junk[i] += "*";
  }

  message ("1", "^cc" + dir + "^c0:\n", THIS);

  if (sizeof(junk) == 0) {
    write ("No files.\n");
    return 1;
  }

  printf ("%#-78s\n", implode (junk, "\n"));
  return 1;
}
