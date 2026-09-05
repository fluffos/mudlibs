// 精简版的hp，给机器人专用。降低流量！
// jzhang 2011,Nov,15! 北侠260人在线，每日流量15G！

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

string status_color(int current, int max);

int main(object me, string arg)
{
    int exp = me->query("combat_exp");
    write("#");
	if ( exp < 100000 )
	  write(sprintf("%d,",exp));
	else if ( exp < 1000000 )
		write(sprintf("%.1fK,", (exp*1.0)/1000));
	else
		write(sprintf("%.2fM,", (exp*1.0)/1000000));
        
    printf("%d,%d,%d,%d,%d\n#%d,%d,%d,%d,%d,%d\n",to_int(me->query("potential") - me->query("learned_points")),
    to_int(me->query("max_neili")),to_int(me->query("neili")),
    to_int(me->query("max_jingli")),to_int(me->query("jingli")),
    to_int(me->query("max_qi")),to_int(me->query("eff_qi")),to_int(me->query("qi")),
    to_int(me->query("max_jing")),to_int(me->query("eff_jing")),to_int(me->query("jing")));
    
    

	return 1;
}


int help(object me)
{
	write(@HELP
指令格式 : hpbrief
	这个指令以最精简的格式反应玩家状态。做机器人时推荐使用这个指令。更加可靠。
    数据排列如下：
    #经验，潜能，最大内力，当前内力，最大精力，当前精力
    #最大气血，有效气血，当前气血，最大精神，有效精神，当前精神
HELP
    );
    return 1;
}
