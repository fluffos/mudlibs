//转换特技 by whuan@pkuxkx
#include <ansi.h>
inherit F_CLEAN_UP;

string *specialsk=({
        "intellect","energy","constitution","chainless","perceive","sociability","lucky",
        "greedy","agile","might","corporeity","ironskin","spirituality","athanasy","health"
});
string *specialsk2=({
        "聪明睿智","聚精会神","镇蕴七星","金蝉脱壳","传音搜魂","长袖善舞","洪福齐天",
        "饕餮之力","身轻如燕","力大无穷","固本培元","铜皮铁骨","灵气逼人","凤凰涅磐","气息悠长",
});      
        
int main(object me, string arg)
{
    string msg;
	string from,to;
    int i;
    if(me->is_busy())   return notify_fail("你正忙着呢...\n");
    if(sizeof(me->query("special_skill"))>10)
        return notify_fail("你的特技太多了，再转换就出错了！\n");
	if(!arg || sizeof(arg) == 0)
		return notify_fail("请输入正确的参数\n");
	if(sscanf(arg,"%s to %s",from,to) == 2)
	{
		//转换到指定技能。
		if(member_array(from,specialsk) == -1 || member_array(to,specialsk) == -1)
		{
			return notify_fail("请输入正确的特技名（英文）。\n");
		}
		if(!me->query("special_skill/"+from))
		{
			return notify_fail("你并不会"+from+"这个特技。\n");
		}
		if(me->query("special_skill/"+to))
		{
			return notify_fail("你已经掌握了"+to+"这个特技。\n");
		}
		if(me->query("repute") < 1000000)
			 return notify_fail("你的声望不足！\n");
		if(me->query("combat_exp") < 1200000)
			 return notify_fail("你的经验不足！\n");
		if(me->query("balance") < 500000000)  
			return notify_fail("你的存款不足！\n");

		i = member_array(to,specialsk);
		me->set("special_skill/"+to,1);
		me->delete("special_skill/"+from);
		me->add("repute",-1000000);
		me->add("combat_exp",-1000000);
		me->add("balance",-500000000);

		me->save();
		tell_object(me,"个人特殊技能转换完毕，为"HIR+specialsk2[i]+"("+specialsk[i]+")"+NOR"这个特殊技能。\n");  
		MONITOR_D->report_sys_msg (me->name()+"转换的特殊技能为"+specialsk2[i]+"("+specialsk[i]+")\n");


		return 1;
	}

    if(me->query("repute") <= 300000)  
        return notify_fail("你的声望不足！\n");
    if(me->query("balance") <= 30000000)  
        return notify_fail("你的存款不足！\n");
    if(!me->query("special_skill/"+arg))
         return notify_fail("你只能转换你已有的特殊技能！\n");

   i = random(sizeof(specialsk));        
    msg=specialsk[i];
    while(me->query("special_skill/"+msg) == 1)
    {
     i = random(sizeof(specialsk));             
        msg=specialsk[i];
    }
    me->set("special_skill/"+msg,1);
    me->delete("special_skill/"+arg);
    me->save();
        tell_object(me,"个人特殊技能转换完毕，为"HIR+specialsk2[i]+"("+specialsk[i]+")"+NOR"这个特殊技能。\n");  
    MONITOR_D->report_sys_msg (me->name()+"转换的特殊技能为"+specialsk2[i]+"("+specialsk[i]+")\n");
	if (me->query("relationship/target_name")&&me->query_temp("relative/changespecial")&&!me->query("relationship/freesp"))//一人一生一次的特殊成就奖励，免费换技能一次 by Zine
	{
		me->set("relationship/freesp",1);
		me->delete_temp("relative/changespecial");
		tell_object(me,me->query("relationship/target_name")+"说得果然不错，你竟发现自己全无损失。\n");
		me->save();
		return 1;
	}
    me->add("repute",-300000);
    me->add("balance",-30000000);
    me->save();
    return 1;

}

int help(object me)
{
        write(@HELP
指令格式 : change_special <特技>

这个指令可以将花费30万声望和3000两黄金的存款，将已有
的一个特技随机转换为另一个不会的。

	或者：
	change_special <特技> to <新特技>
这个指令可以将某个特技转换为指定的另一个特技。消耗100万
声望，100万经验和5万黄金。
特技系统帮助请看 : help special / help kungfu-special
HELP
    );
    return 1;
}
