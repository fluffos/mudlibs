/* odoyle rulz */

#include <security.h>

int
cmd_upd_dir(string x)
{
    if((int)this_player()->query_level() < CREATE)
      return 0;

    else
    {
      if(!x) x=(string)this_player()->get_path();
      else x=(resolv_path(x) + "/");
      if(file_size(x) != -2)
        return (notify_fail("Unable to upd_dir...\nString is not a directory!\n"), 0);

      else
      {
        int s, l;
        string *z, m;
        object a;

        s=sizeof(z=get_dir(x));
        while(s--)
          if(((l=strlen(m=z[s])) > 2) && (m[l-1] == 'c') && (m[l-2] == '.'))
          {
            write("Updating " + (m=(x+m)) + "... ");
            if(a=find_object(m))
            {
              destruct(a);
              write("Done.\n");
            }
            else
              write("Not loaded.\n");
          }
      }
    }

    return 1;
}
