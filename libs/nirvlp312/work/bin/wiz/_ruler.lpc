#include <security.h>

int
cmd_ruler(string arg)
{
    int i, s;
    string *text;
    string res;
    object x;

    if((int)this_player()->query_level() < APPRENTICE) return 0;
    if(!arg)
    {
      x=environment(this_player());
      arg="room";
    }
    else
    {
      if(!(x=present(arg, this_player())))
        if(!(x=present(arg, environment(this_player()))))
          return (notify_fail("That's not here.\n"), 0);
    }
    
    if(!x) return (notify_fail("Invalid object.\n"), 0);

    if(!function_exists("query_long", x))
      return (notify_fail("\
Invalid object.  \"query_long()\" does not exist.\n"), 0);

    res=(mixed)x->query_long();
    if(!stringp(res)) return (notify_fail("Invalid.  The result returned from \"query_long()\" is not a string.\n"), 0);
    res = delete_colour(res);
    text = explode(res, "\n");
    s=sizeof(text);

    write("\n\tLINE LENGTHS: " + capitalize(arg) + "\n");
    write("--------------------------------\n");
    for(i=0;i<s; i++)
      write((i+1)+": "+strlen(text[i])+"\n");
    write("--------------------------------\n");
    write("\n");
    return 1;
}
