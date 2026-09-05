/* odoyle rulz */

#include <security.h>

int
cmd_load_dir(string x)
{
    if((int)this_player()->query_level() < CREATE)
      return 0;

    else
    {
      string err;
      if(!x) x=(string)this_player()->get_path();
      else x=(resolv_path(x) + "/");
      if(file_size(x) != -2)
        return (notify_fail("Unable to load_dir...\nString is not a directory!\n"), 0);

      else
      {
        int s, l;
        string *z, m;
        object a;

        s=sizeof(z=get_dir(x));
        if(x=="/obj/") { write("This would crash it.\n"); return 1; }
        while(s--)
          if(((l=strlen(m=z[s])) > 2) && (m[l-1] == 'c') && (m[l-2] == '.'))
          {
            write("Loading " + (m=(x+m)) + "... ");
            if(a=find_object(m))
            {
              write("Already loaded.\n");
            }
            else
           {
             if(err = catch(m->load_me()))
               write("Error: " + err + "\n");
            else write("Ok.\n");
        }
          }
      }
    }

    return 1;
}
