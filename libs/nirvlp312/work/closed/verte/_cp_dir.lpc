int
main(string x)
{
    string *ff, src, dst, y, z;
    int i, s;

    if(!x || (sscanf(x, "%s %s", x, y) < 2))
      return (notify_fail("Syntax: 'cp_dir <old_dir> <new_dir>'\n"), 0);
    if(file_size(x) != -2)
      return (notify_fail(x+ " is not a directory!\n"), 0);
    if(file_size(y) != -2)
      return (notify_fail(y+ " is not a directory!\n"), 0);
    s=sizeof(ff=get_dir(x));
    write("Copying the contents of " + x + " to " + y + "...\n");
    if(y[strlen(y)-1] != '/') y+="/";
    if(x[strlen(x)-1] != '/') x+="/";
    this_player()->valid_write(x + " -> " + y);
    if(x == y) return (notify_fail("Why bother with that?\n"), 0);

    for(i=0;i<s;i++)
      if(src=(x+(z=ff[i])))
      {
        write(z+"... ");
        if(file_size(src) == -2)
          write("ERROR. Cannot copy sub-directories.\n");
        else if(file_size(dst=(y+z)) > 0)
          write("ERROR. Filename already exists in that locale.\n");
        else
        {
          write("OK.\n");
          cp(src, dst);
        }
      }
       
    return 1;
}

int
cmd_cp_dir(string x)
{
    return (main(x));
}
