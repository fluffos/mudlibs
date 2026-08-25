// bet.c
// by Suicide on Sep 6 2000

#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;

private void main(string arg)
{
   string result;
   object me = this_body();
   if (!environment(me)->is_casino())
      {write("这儿不是赌场，该指令无效！\n");
       return;}
   if (stringp(result=environment(me)->do_bet(arg)))
      write(result);
   
}
