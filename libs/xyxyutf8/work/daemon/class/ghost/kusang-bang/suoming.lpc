#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;  
	string msg,succ_msg;   
	
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "阎罗地府")
        	return notify_fail(HIG"「冤魂索命」"+NOR"是地府不传之密！\n");		
	if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me
 	 || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「冤魂索命」？\n");
	if((int)me->query("force") < 800 )
        	return notify_fail("你的内力不够！\n");
        if( me->query("kee")<500 )
        	return notify_fail("你气血不足，无法驱使冤魂。\n");	
	if( time()-(int)me->query_temp("hell_suoming") < 6 )
        	return notify_fail("绝招用多就不灵了！\n");
	if((int)me->query_skill("kusang-bang", 1) < 300)
        	return notify_fail("你的哭丧棒级别还不够，使用这一招会有困难！\n");
        	
        msg = HBBLU"$N"HBBLU"长嘶一声，只见漫天的棍影化做阴风在$n"HBBLU"身后翻腾合拢，一片鬼哭狼嚎声搅的天地大乱，震天的狂雷，缠绵的靡雨，带着屈死冤魂伴着那无尽诅咒卷向$n"HBBLU"。\n"NOR;
        succ_msg = YEL"但见幢幢鬼影四周飘浮，突然$N"YEL"鬼唱一声，无数鬼手抓向$n"YEL"！\n"NOR;
        me->add("force",-300);
        me->receive_damage("kee",100,me);
        me->set_temp("pfm_msg",1);
        me->set_temp("hell_suoming",time());
        damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
        me->set_temp("pfm_msg",0);
        if( damage<1 )
        {
        	me->add_temp("hell_suoming",4);
        	me->receive_damage("kee",100,me);
        }	
        else
        {
        	target->set_temp("HellSuoming",me);
        	damage = me->query_level()*10+me->query_skill("kusang-bang",1);
        	damage/= 2;
        	damage+= me->query_spells_damage();
        	damage-= target->query_spells_def();
        	if( damage<50 )
        		damage = 50;
        	target->apply_condition("hell_suoming",damage);	 	
        }	
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：冤魂索命
        外功所属：哭丧棒
        外功效果：对敌一击，命中则时刻驱使冤魂对其锁魂
        	  冷却 6 秒，不中则增加 4 秒
        外功条件：
        	  地府弟子
        	  人物等级30级	
                  哭丧棒300级
                  内力800点，消耗300点
                  气血500点，消耗100点，不中则增加100点消耗
LONG;
me->start_more(str);
return 1;
}

