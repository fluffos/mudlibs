// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
           int time;
    	time = time();
			write("现在现实中的时间是北京时间 " + ctime( time ) + "（" + NATURE_D->game_time() + "）。\n");
	  if (wizardp(me))
		  write(HIG"【wiz】 function time() = " + time + "\n"NOR);
      write("北大侠客行现在大约是" + NATURE_D->get_current_day_phase() + "时分。\n");
      write(SPEWEEK_D->query_msg() + NOR "\n");
      if(REWARD_D->is_in_binge())
      {
        write(HIW"现在正是北侠的超级狂欢期间，所有奖励在原基础上翻倍，修炼，学习，读书，打坐，吐纳等效率加倍。\n"NOR);
      }
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令让你(你)知道现在的时辰。

子时 23:00～1:00
丑时 1:00～3:00
寅时 3:00～5:00
卯时 5:00～7:00
辰时 7:00～9:00
巳时 9:00～11:00
午时 11:00～13:00
未时 13:00～15:00
申时 15:00～17:00
酉时 17:00～19:00
戌时 19:00～21:00
亥时 21:00～23:00

HELP
    );
    return 1;
}
