// longhe.c     龙鹤庄，龙鹤呈详（增加精力）  
// Rewrote by iszt@pkuxkx, 2007-05-19
// 效果为powerup

#include <ansi.h>

int exert(object me, string arg)
{
        string longhe = "龙鹤庄";
        int skill, level,inc, pflv;

        if(me->query_temp("longhe")) 
                return notify_fail("你正在运行"+me->query_temp("longhe")+"，无法运行"+longhe+"。\n");
        if (me->query_temp("powerup"))
        		return notify_fail("你已经在运功中了。\n");
        if(me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if( me->query("class") != "bonze" && me->query("chushi/last_family")!="峨嵋派")
                return notify_fail("你尘心未灭，无法运行临济十二庄"+longhe+"。\n");
        if((int)me->query("neili") < 200 )
                return notify_fail("你的真气不够。\n");
        if((int)me->query_skill("linji-zhuang",1) < 120)
                return notify_fail("你的临济十二庄修为太低，无法运行"+longhe+"。\n");
 
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;

        skill = me->query_skill("force");
        level = 5;
        if ( (int)me->query_skill("mahayana",1) > 400 ) 
			level = 3;
		else
		{
			if ( (int)me->query_skill("mahayana",1) > (int)me->query_skill("linji-zhuang",1)) level = 3;
			else if ( (int)me->query_skill("mahayana",1) > (int)me->query_skill("linji-zhuang",1)*2/3) level = 4;
			else level = 5; 
		}
		message_vision(HIM "$N微一凝神，运起临济十二庄"+longhe+"，脸上泛起一抹艳红。\n" NOR, me);
        inc=skill/level;
        if (me->query_skill("emei-jiuyanggong",1)>21)
        {
			if (me->is_realuser()&&me->query("chushi/done")==0)
			{
				inc=inc * 7/5;
			}
			else
			{
				inc = inc* 6/5;
			}
	        write(HIR"峨嵋九阳功的内息在你经脉中川流不止......\n"NOR);
        }
		if (pflv>=3)
			inc += inc*(pflv-2)/10;
        me->add_temp("apply/attack", inc);
        me->add_temp("apply/dodge", inc);
        me->set_temp("longhe", 1);
        me->set_temp("powerup",1);
        me->add("neili", - 100); 
        me->set_temp("active_force_buffer/linji-zhuang.longhe/name", "龙鹤庄");                        //buff名称
        me->set_temp("active_force_buffer/linji-zhuang.longhe/last_time", time() + inc );              //持续时间
        me->set_temp("active_force_buffer/linji-zhuang.longhe/effect1", "攻击命中+"+inc+"级");         //效果描述1   
        me->set_temp("active_force_buffer/linji-zhuang.longhe/effect2", "轻功技能+"+inc+"级");         //效果描述2
        me->start_call_out(__FILE__, "remove_effect", inc, me, inc);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}
 
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", -amount);
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("longhe");
        me->delete_temp("powerup");
        me->delete_temp("active_force_buffer/linji-zhuang.longhe");
        tell_object(me, WHT"你龙鹤庄运行完毕，又恢复如常。\n"NOR);
        return;
}


