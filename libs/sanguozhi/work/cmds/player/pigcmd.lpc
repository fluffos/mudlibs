// pigcmd.c
// by Suicide on Sep 1 2000
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
inherit M_GLOB;
private void main(string arg)
{
   string *p_arg;
   string result,tmp;
   if(!arg)
	   p_arg=({"help"});
   else
	   p_arg=explode(arg," ");
   if (!environment(this_body())->is_pigroom()) return;
   switch(p_arg[0])
   {
   case "sit":
       if (stringp(result=environment(this_body())->do_sit(p_arg[1])))
          write(result);
       return;
   case "deal":
       if (stringp(result=environment(this_body())->do_deal()))
          write(result);
       return;
   case "leave":
       if (stringp(result=environment(this_body())->do_leave()))
          write(result);
       return;
   case "pass":
       if (stringp(result=environment(this_body())->do_pass()))
          write(result);
       return;
   case "refresh":
       if (stringp(result=environment(this_body())->do_refresh()))
          write(result);
       return;
   case "bid":
       if (stringp(result=environment(this_body())->do_bid(p_arg[1])))
          write(result);          
       return;
   case "play":
       if (stringp(result=environment(this_body())->do_play(p_arg[1])))
          write(result);          
       return;
   case "claim":
       if (sizeof(p_arg)==1) tmp=0;
          else tmp=p_arg[1];  
       if (stringp(result=environment(this_body())->do_claim(tmp)))
          write(result);          
       return;
   case "skip":
       if (stringp(result=environment(this_body())->do_skip()))
          write(result);          
       return;
   case "look":
       write(environment(this_body())->table_str());
       return;
   case "score":
       write(environment(this_body())->scoreboard_str());
       return;
   default    :
       write("好像没有这条指令哦,你可以用help pig_cmds指令查看一下!\n");
       return;
   }
   
}
