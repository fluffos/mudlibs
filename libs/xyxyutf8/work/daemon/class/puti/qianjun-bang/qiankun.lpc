// Qiankun.c 乾坤一棒
// Cracked by 凌惊雪 4-30-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
	int damage;
	
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
	
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招？\n");
	if(me->query("family/family_name") != "方寸山三星洞" )
		return notify_fail("你是哪儿偷学来的武功?\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力修为不够！\n");
        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足！\n");
	if( (int)me->query_skill("qianjun-bang",1)<60 )                
                return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");
	
	msg = HIY"$N"HIY"将手中$w"HIY"迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，对准$n"HIY"的脑门就砸了下去。这一下要是打中，恐怕连大罗金仙也难逃一命！\n"NOR;
	me->receive_damage("sen", 50);      
        me->add("force", -100);
        me->set_temp("QJB_perform", 7);
        if( COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部",(int)me->query_skill("stick")/15) )
        	me->add_temp("anger",10);
        me->delete_temp("QJB_perform");
     	me->start_busy(1);	
        return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：乾坤一棒
        外功所属：千钧棒
        外功效果：对敌进行带固定攻击的一击
                  命中则增加怒气10点
                  自身busy 1 秒
        外功条件：
        	  人物等级8级
        	  方寸弟子
        	  千钧棒法60级	
                  内力500点，消耗100点
                  精神200点，消耗50点
LONG;
	me->start_more(str);
	return 1;
}