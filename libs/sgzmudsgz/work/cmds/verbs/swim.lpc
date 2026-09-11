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

void do_swim()
{
  mixed s = environment(this_body())->swim();

  if(stringp(s))
    {
      write(s);
      return;
    }
  else if(!s)
    {
      write("你要在哪里游泳？\n");
      return;
    }
}



void do_swim_in_obj(object ob, string str) {
  mixed s;
    s = ob->swim(str);
    if(stringp(s))
      {
        write(s);
        return;
      }
    if(!s)
      {
        write("你不能在那里面游泳！\n");
      }
}

int direct_swim_in_obj(object ob)
{
  return 1;
}


mixed * query_verb_info()
{
    return ({ ({ "", "in OBJ", }),({  }) });

}


