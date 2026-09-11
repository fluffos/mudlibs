// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** get.c
**
*/

#include <mudlib.h>
#include <move.h>
#include <setbit.h>

inherit VERB_OB;

void do_wade()
{
  mixed s = environment(this_body())->wade();

  if(stringp(s))
    {
      write(s);
      return;
    }
  else if(!s)
    {
      write("你要在什么地方涉水而过呢？\n");
      return;
    }
}



void do_wade_in_obj(object ob, string str) {
  mixed s;
    s = ob->wade(str);
    if(stringp(s))
      {
        write(s);
        return;
      }
    if(!s)
      {
        write("这样做是不行的。\n");
      }
}

int direct_wade_in_obj(object ob)
{
  return 1;
}


mixed * query_verb_info()
{
    return ({ ({ "", "in OBJ", }),({  }) });

}


