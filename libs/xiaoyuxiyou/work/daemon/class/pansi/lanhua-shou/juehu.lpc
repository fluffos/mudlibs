// juehu.c 兰花手「九阴绝户手」perform
//2000,by lestat
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage,p;
        string msg,succ_msg;

	if( me->query_level()<5 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="盘丝洞")
            	return notify_fail("只有盘丝洞门人才可以用这项技能！\n");
        if( (int)me->query_skill("lanhua-shou", 1) < 50 )
                return notify_fail("你的兰花手不够娴熟，不会使用「九阴绝户手」。\n");
        if( (int)me->query_skill("jiuyin-xinjing", 1) < 50 )
                return notify_fail("你的九阴心经不够高，不能用「九阴绝户手」伤敌。\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("你现在内力太弱，不能使出「九阴绝户手」招式。\n");
        if( (int)me->query_condition("juehu_busy"))
		return notify_fail("你元气大伤，现在没有能力使出「九阴绝户手」招式。\n");
	if((string)me->query_skill_mapped("unarmed")!="lanhua-shou" )
		return notify_fail("你先得捏个兰花手。\n");
			          
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )	
		return notify_fail("九阴绝户手只能对战斗中的对手使用。\n");

	me->add("force",-100);
        msg = HIB "$N"HIB"默运神功，脸色白得吓人，突然使出兰花手的一记阴招「"HIR"九阴绝户手"HIB"」，狠狠拍向$n"HIB"下腹！\n"NOR;
	if( target->query("gender")== "女性" )
		succ_msg = HIM"$n"HIM"被$P一击命中，，不禁既羞又怒，”"+RANK_D->query_rude(me)+"，真不要脸，竟对一女流之辈也用此阴毒招数！“\n"NOR;
	else	succ_msg = HIM"$n"HIM"突然觉的丹田内的精元已流失迨尽，心里一阵难过，知道自己有一段时间不能行欢做乐了！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"小腹");
	me->set_temp("pfm_msg",0);
	if( !target->is_killing(me->query("id")) )
		target->kill_ob(me);
	if( damage<1 )
	{
		message_combatd(HIM"可是$p看破了$N"HIM"的狠毒企图，向旁跳开数步，躲开了$P的凌厉一击！\n"NOR,me,target);
		me->start_busy(1);
		return 1;
	}
	p = damage/10;
	if( p<15 ) p = 15;
	if( p>60 ) p = 60;
	me->start_busy(2);
	target->apply_condition("juehu_busy",(int)target->query_condition("juehu_busy")+p);
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：九阴绝户手 
        外功所属：兰花手
        外功效果：使对方身中九阴绝户内伤，内伤期间气血精神上下限不停的减少
                  自身busy 2 秒，不中则自身busy 1 秒
        外功条件：
                  盘丝洞弟子
        	  人物等级5级	
                  内力500点，消耗100点
                  九阴心经50级
                  兰花手50级并激发
LONG;
me->start_more(str);
return 1;
}
