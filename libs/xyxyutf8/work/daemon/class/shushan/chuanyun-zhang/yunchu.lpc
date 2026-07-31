#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,succ_msg;
        int damage,p;

      	if( me->query_level()<60 )
      		return notify_fail("你的人物等级不够。\n");
        if((int)me->query("force") < 800 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query_skill("chuanyun-zhang",1) < 600
         ||(string)me->query_skill_mapped("unarmed")!="chuanyun-zhang" ) 
                return notify_fail("你的掌法火候还不到，使用这一招会有困难！\n");
                
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁的施展「云出无心」？\n");
	
	p = me->query_skill("unarmed")/10;
	me->add("force",-150);
	damage = me->query_skill("unarmed")*3/2;
	msg = HIW"\n$N"HIW"浑身内息游走，口中念道：挫其锐，解其纷，和其光，同其尘。面上白气一闪，右掌随之直出，一道有形劲气如龙似虎，猛地对准$n"HIW"$l冲去！\n"NOR;
	succ_msg = HIR"$n"HIR"脚下一个不稳，踉跄几步，呕出几口鲜血，面色苍白了许多！\n"NOR;
	me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,({"小腹","后心","头部"})[random(3)],damage);
	if( damage>3 )
	{
		if( COMBAT_D->query_message_type(me,target)==2 )
			message_vision("结果造成了"HIR+damage/3*2+NOR"点气血损伤。\n",me,target);
		target->receive_wound("kee",damage/3*2,me,TYPE_PERFORM);
		COMBAT_D->report_status(target,1);	
	}
	me->delete_temp("pfm_msg");
	me->add_temp("apply/attack",-p);
	me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：云出无心
        外功所属：穿云掌
        外功效果：对敌进行带高伤害的要害攻击
        	  造成对方的气血减少与损伤
                  自身busy 2 秒
        外功条件：
        	  人物等级60级	
                  内力800点，消耗150点
                  穿云掌600级并激发
LONG;
me->start_more(str);
return 1;
}   
