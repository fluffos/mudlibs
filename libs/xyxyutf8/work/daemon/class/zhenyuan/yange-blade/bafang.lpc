//bafang.c 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,succ_msg;
        int damage;
	
	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
	if((int)me->query_skill("yange-blade", 1) < 200)
                return notify_fail("你的雁歌刀法级别还不够，使用这一招会有困难！\n");
	if( time()<me->query_temp("wzg_bafang")+6 )
		return notify_fail("绝招滥使就不灵了！\n");
     	if( me->query("family/family_name") != "五庄观" )
		return notify_fail("你是哪儿偷学来的武功，也想用「八方风雨」?\n");
		
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「八方风雨」？\n");

	msg = HIY"$N"HIY"大喝一声，全场四处游动，$n"HIY"只看到数团身影，漫天刀光朝自己$l席卷而来！\n"NOR;
	succ_msg = HIR"$n"HIR"根本没法躲避，顿时几刀都砍在$n"HIR"$l！鲜血溅起，$n自觉眼前一片鲜红，遮住视线！\n"NOR;
	me->set_temp("wzg_bafang",time());
	me->receive_damage("kee", 100,me);
        me->add("force", -300);
        me->set_temp("pfm_msg",1);
        damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,me->query_skill("balde")/10);
        me->set_temp("pfm_msg",0);
        if( damage<1 ) 
        {
        	message_combatd(HIY"可是$n"HIY"早以看出其中虚实，毫不在意地坦然面对。\n"NOR,me,target);
        	me->start_busy(1);
        	return 1;
        }
        if( target && living(target) && me->is_fighting(target) )
        {
        	target->set("weapon_hurt",([
        		"start" : time(),
        		"time"  : (int)me->query_skill("blade")/5,
        		"target_name" : me->name(),
        		"target_id" : me->parse_command_id_list()[0],
        		"target" : me,
        		"limb" : "其他",
        		"damage" : damage/2+random(damage/2),
        	]));
        }
	return 1;
}

int help(object me)
{
        string str;     
        if( !me )      
                return 0;
        str = @LONG
        外功名称：八方风雨
        外功所属：雁歌刀法
        外功效果：对敌进行带固定伤害的攻击，命中则使对方身中兵器之伤
        	  冷却时间 6 秒，不中则自身busy 1 秒
        外功条件：
                  五庄观弟子
        	  人物等级20级	
                  内力500点,消耗300点
                  气血200点，消耗100点
                  雁歌刀法200级
LONG;
        me->start_more(str);
        return 1;
}
