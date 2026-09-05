/*
 * Std Path Resolve by Vertebraker [7.8.01]
 */

varargs string
resolve_path(string old, string ext)
{
    if(!stringp(old)) return 0;

    else
    {
      if(ext)
      {
        int s, c;

        s = strlen(old);
        c = strlen(ext);

        if(s >= c) {

        if(old[s-c..s-1] != ext)
          old += ext;
        }
        else old += ext;
      }

      if(strlen(old) > 1)
      {
        if(old[0] == '~')
          old = "/players/" + (string)this_player()->query_real_name()
                          + old[1..strlen(old) - 1];
        /*
        else
          if(old[0..1] == "..")
          {
            string *a, er;
            int    b, i;

            b = sizeof(a = explode((string)this_player()->get_path(), "/"));
            er = "/";
            for(i = 0; i < (b - 1); i ++)
              er += (a[i] + "/");

            old = (er + old[2..strlen(old)-1];
          }

        */
        else if(old[0] != '/')
          old = (string)this_player()->get_path() + old[0..strlen(old)-1];

      }
            
      return old;
    }
}
