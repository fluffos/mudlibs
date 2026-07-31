// Zizai.c 自在逍遥 
// Cracked by 凌惊雪 1-4-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
	int damage,time;
	
	if( me->query_level()<15 )
        	return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("wuyou-steps",1)<150 )
		return notify_fail("你的无忧步法还不够纯熟！\n"); 
	if(  me->query("force")<500 )
        	return notify_fail("你的内力不足了。\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("「自在逍遥」只能对战斗中的对手使用。\n");
	if( target->is_busy() )
    		return notify_fail(target->name()+"已经手忙脚乱了！\n");

	time=(int)me->query_skill("dodge", 1) /50;
	if(  time > 5 ) time = 5;
	if(  time < 3  ) time = 3;      
	time += random(me->query_per())/10;
	if(  time > 7 ) time = 7;
	if(me->query("family/family_name") != "百花谷")
    		time = 3;
	
	me->add("force",-200);
	msg = HIY"$N"HIY"运起无忧步法，身形恬静轻柔，飘忽不定。\n"NOR;
	succ_msg = HIR"转眼不见了$N"HIR"的身行，$n"HIR"只觉目眩神弛，心惊肉跳，顿时一筹莫展！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
        	message_combatd(HIR"不料确被$N"HIR"看破，结果$N"HIR"并不慌张！\n"NOR,target,me);
        	me->start_busy(2);
        	return 1;
	}
	target->start_busy(time);
	me->start_busy(1);
	return 1;
}

int help(object me)
{
string str;
if(  !me )      return 0;
str = @LONG     
        外功名称：自在逍遥
        外功所属：无忧步法
        外功效果：以身法使对手busy 3-7 秒
                  施展完后自身busy 1 秒 
                  不中则自身busy 2 秒 
        外功条件：
                  人物等级15级
                  无忧步法150级
                  内力500点,消耗200点
LONG;
me->start_more(str);
return 1;
}
