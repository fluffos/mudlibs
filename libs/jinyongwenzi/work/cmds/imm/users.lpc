// info command.
// by snowman@SJ 1998.

#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;

#define TIME_TICK (time()*60)
mixed main(object me)
{
	object *ob;
	int i,ppl_cnt = 0, cnt = 0, wcnt = 0, f_cnt = 0, u_cnt = 0, i_cnt;

	ob = filter_array(objects(), (: userp :));

	i = sizeof(ob);
	while( i-- ) {
            if (wizardp(ob[i]) && ((int)ob[i]->query("env/invisibility")<5)) wcnt++;
		else if (interactive(ob[i])){
			 ppl_cnt++;
			 if(ob[i]->is_fighting()) f_cnt++;
			 if(!living(ob[i])) u_cnt++;
			 if(query_idle(ob[i]) > 120) i_cnt++;
			 }
		else cnt++;
	}

	write("\n"+MUD_NAME+"目前共有 "+wcnt+" 位巫师， "+ppl_cnt+" 位玩家连线中，"+cnt+" 位玩家断线中。
其中：
        在战斗的有： "+f_cnt+" 位。
    昏迷或睡觉的有： "+u_cnt+" 位。
          发呆的有： "+i_cnt+" 位。
          
系统负担："+query_load_average()+"。
现在的 time() 是：" + time() + "。
现在的 Natured time() 是：" + TIME_TICK + " " + localtime(TIME_TICK)[2] + ":" + localtime(TIME_TICK)[1]+"。
现在的 uptime() 是：" + uptime() + "。
Natured 的时刻是：" + NATURE_D->query_daytime() + "。\n\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : users

这个指令可以列出目前的玩家数量。

相关指令： who
HELP
	);
	return 1;
}
