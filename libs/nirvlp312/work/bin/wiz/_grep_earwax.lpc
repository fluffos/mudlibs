/* grep
 * 
 * Earwax 1/16/04
 *
 * This version of grep will not load overly large files, but will allow
 * use of wildcards.  See 'wizhelp grep' for more information.
 *
*/

int cmd_grep(string arg)
{
  string pattern, filename, filetext;
  int i, siz;
  string *lines, *matches;

  if (!arg || sscanf(arg, "%s %s", pattern, filename) != 2)
  {
    notify_fail("See 'wizhelp grep' for help on using grep.\nSyntax: grep <pattern> <filename>\n");
    return 0;
  }

  if (sscanf(filename, "/%s", filename) == 1)
    filename = resolv_path("/"+filename);
  else
    filename = resolv_path((string)this_player()->query_pwd() + filename);

  filetext = read_file(filename, 1, 5100);

  if (!filetext)
  {
    write("File did not read: "+filename+"\n");
    siz = file_size(filename);

    if (siz < 1)
    {
      write("File does not exist, or is unreadable.\n");
      return 1;
    }

    write("Size of file probably too large: "+siz+"\n");
    return 1;
  }

  lines = explode(filetext, "\n");

  if (!sizeof(lines))
  {
    write("Could not explode file: "+filename+"\n");
    return 1;
  }

  matches = regexp(lines, pattern);
  siz = sizeof(matches);
  write("Searching "+filename+" for \""+pattern+"\" returned "+siz+" matches.\n");

  for (i = 0; i < siz; i++)
    write(matches[i]+"\n");

  write("Filesize: "+file_size(filename)+"\n");
  return 1;
}
