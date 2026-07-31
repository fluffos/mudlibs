// modified by vikee
// jieti.c 天魔解体大法。
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int success, ap, dp;
        
        if( me->query_level()<35 )
        	return notify_fail("你人物等级不够。\n");
	if(me->query("family/family_name")!="大雪山") 
        	return notify_fail("「天魔解体大法」只有雪山弟子才可以用！\n");

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
                return notify_fail("你要对谁施展「天魔解体大法」？\n");
	if( !me->is_killing(target->query("id")) )
		return notify_fail("不是性命相搏，不能用此招。\n");
        if((int)me->query("mana") < 1100 || (int)me->query_maxmana() < 1500 )
                return notify_fail("你的法力不够，不能有效施展「天魔解体大法」！\n");
        if((int)me->query("faith") < 1000  )
                return notify_fail("你在雪山时日尚浅，不能有效施展「天魔解体大法」！\n");
        if((int)me->query("force") < 600 || (int)me->query_maxforce() < 800 )
                return notify_fail("你的内力不够，不能有效施展「天魔解体大法」！\n");
        if((int)me->query("sen") < 100 || (int)me->query("sen") < (int)me->query_maxsen()/2 )
                return notify_fail("你无法集中精力施展「天魔解体大法」！\n");
        if( (int)me->query("daoxing") < (int)target->query("daoxing")/10
         || COMBAT_D->check_level(me,target)==-1 )
                return notify_fail("对方比你强太多了，还是别送死吧！\n");

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

	me->add("faith",-1000);
        msg = HIC"$N"HIC"口中念了几句咒文，双手捧住脑袋，仰天发出一声悲嘶！\n\n忽然间$N"HIC"将自己舌头狠命一咬，一道血雾向$n"HIC"喷了过去！\n" NOR;
        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /100 ;
        ap += (int)me->query("daoxing")/10;
        ap = 4*ap; 
        dp = target->query("daoxing")/10;
        if( random(ap + dp) < dp ) 
        	success = 0;
        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( ap < random(dp) ) 
        	success = 0;
//	if( COMBAT_D->attack_percent(me,target,TYPE_CAST)!=1 )
//		success = 0;
        if(success == 1 )
        {
                msg +=  HIR "结果$n"HIR"被血雾罩住，顿时发出一声惨叫！\n而$N"HIR"也身子一瘫，倒在地上。\n" NOR;
                message_vision(msg, me, target);
		target->receive_damage("sen",target->query_maxsen()+1,me,TYPE_CAST);
		target->receive_wound("sen",target->query_maxsen()+1,me,TYPE_CAST);
                target->receive_damage("kee",target->query_maxkee()+1,me,TYPE_CAST);
                target->receive_wound("kee",target->query_maxkee()+1,me,TYPE_CAST);
                COMBAT_D->report_status(target);
                COMBAT_D->report_sen_status(target);
		target->heart_beat();
                //target die here.

        	me->receive_damage("sen", (int)me->query_maxsen()+1, target,TYPE_CAST);
        	me->receive_wound("sen", (int)me->query_maxsen()+1, target,TYPE_CAST);
                me->receive_damage("kee", (int)me->query_maxkee()+1, target,TYPE_CAST);
                me->receive_wound("kee", (int)me->query_maxkee()+1, target,TYPE_CAST);
		COMBAT_D->report_status(me);
		COMBAT_D->report_sen_status(me);
  		me->heart_beat();
                //attacker die here.
        }
	else 
	{
                msg +=  HIR "结果血雾被$n"HIR"法力反激，反而罩住了$N"HIR"！\n$N"HIR"长叹一声，身子一瘫，倒在地上。\n" NOR;
                message_vision(msg, me, target);
        	me->receive_damage("sen", (int)me->query_maxsen()+1, target,TYPE_CAST);
        	me->receive_wound("sen", (int)me->query_maxsen()+1, target,TYPE_CAST);
                me->receive_damage("kee", (int)me->query_maxkee()+1, target,TYPE_CAST);
                me->receive_wound("kee", (int)me->query_maxkee()+1, target,TYPE_CAST);
		COMBAT_D->report_status(me);
		COMBAT_D->report_sen_status(me);
  		me->heart_beat();
        } 
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：天魔解体
        法术所属：登仙大法
        法术效果：与对方同归于尽
        	  不可越阶使用，切磋下不可用
        法术条件：
                  雪山弟子
        	  人物等级35级
                  法力1100点，最大法力1500点
 		  内力600点，最大内力800点                 
                  精神50点，消耗30点
                  登仙大法 100 级
                  门忠1000点，消耗1000点
                  
STR;
        me->start_more(str);
        return 1;
}