//太乙神剑pfm剑气，通过set控制状态，后手busy和持续输出
// 2009.8.17 finished by zgbl

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage,cost;
	damage = me->query_skill("taiyi-jian",1) + me->query_skill("taiyi-shengong",1) + me->query_temp("apply/damage");
	damage = damage / 3 * 2 + random(damage);
	cost = damage/5;
//剑气伤害消耗计算
	if(cost > 200) cost = 200;

      if( !target ) target = offensive_target(me);

	  if ((int)me->query("family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	  if (me->query_skill("hunyuan-yiqi",1) > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	  if (me->query("betrayer") > 0)
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
	  if (me->query("family") || me->query("chushi/last_family"))
		  		return notify_fail("往矣，非曳尾涂中之士，如何领悟太乙正道？\n");
//有门派或者有过门派都无法使用，纯百姓技能
      if( me->query_skill("taiyi-jian",1) < 200 )
                return notify_fail("你的太乙神剑不够娴熟，无法使用「太乙剑气」制敌！\n");
      if( me->query_skill("taiyi-shengong",1) < 200 )
                return notify_fail("你的太乙神功火候不到，无法使用「太乙剑气」制敌！\n");  
      if( me->query_skill_mapped("parry") != "taiyi-jian")
                return notify_fail("「太乙剑气」必须使用太乙神剑作为招架。\n");  
	  

	  if( me->query("env/jianqi") != "破"
	  &&  me->query("env/jianqi") != "网")
		  return notify_fail("你要如何使用「太乙剑气」？(set jianqi 破/set jianqi 网)\n");

	  if( me->query("env/jianqi") == "破" )
	{
		  if( me->query_temp("taiyi-jian/jianqi"))
		{
			  me->delete_temp("taiyi-jian/jianqi");
			  message_vision(HIC"\n$N放缓了剑势，凌空纷飞的剑气渐渐的散去了，$n不由得舒了口长气。\n"NOR, me, target);
			  return 1;
		}
		else if( me->query("neili") > 1000)
		{
			me->set_temp("taiyi-jian/jianqi",1);
			me->add("neili", -200);
			message_vision(HIC"\n$N使出太乙神剑绝技「剑气凌空」，顿时场上凌厉的剑气四下纵横，压的$n喘不过气来！\n"NOR, me, target);
			remove_call_out("effect_taiyijian_jianqi_po");
			call_out("effect_taiyijian_jianqi_po", 0, me, target,damage,cost);
		}
		else
			return notify_fail("你的内力太少了，无法使用「剑气凌空」！\n");
	}
    
	   if( me->query("env/jianqi") == "网" )
	{
		   if( me->query_temp("taiyi-jian/wang") )
    	{
			   me->set_temp("taiyi-jian/cooldown",time());
   			   me->delete_temp("taiyi-jian/wang");
       		   call_out("effect_taiyijian_jianqi_wang_busy", 0, me, target);
   		}
   		else if( me->query("neili") > 1000)
    	{
		    if( time() < 5 + me->query_temp("taiyi-jian/cooldown") )
				return notify_fail("你刚用过「剑气纵横」，内息还没调理平顺！\n");
//冷却为busy时间+5回合
			else
			{
        		me->set_temp("taiyi-jian/wang",1);
        		me->add("neili",-200);
    	    	me->set_temp("taiyi-jian/num",0);
        		message_vision(HIC"$N使出太乙神剑绝技「剑气纵横」，整个人顿时被一层朦胧青光包围，仿佛随时都会射出凌厉的剑气！\n"NOR, me, target);
				     			remove_call_out("effect_taiyijian_jianqi_wang_start");
         		call_out("effect_taiyijian_jianqi_wang_start",0, me, target);
			}
    	}
   		else
    		return notify_fail("你的内力太少了，无法使用「剑气纵横」！\n");
	}
//函数调用
	
	return 1;
}

void effect_taiyijian_jianqi_po(object me,object target,int damage,int cost)
{
	if( !me->is_fighting())
	{
		me->delete_temp("taiyi-jian/jianqi");
	    message_vision(HIC"\n$N收剑而立，凌空纷飞的剑气渐渐散去，留下遍地深深的划痕。\n"NOR, me);
		return;
	}

    if( target && !objectp(present(target,environment(me))) ) 
    {
        me->delete_temp("taiyi-jian/jianqi");
        message_vision(HIC"\n$N收剑而立，凌空纷飞的剑气渐渐散去，留下遍地深深的划痕。\n"NOR, me);
        return;
    }

    if( !target ) 
    {
        me->delete_temp("taiyi-jian/jianqi");
        message_vision(HIC"\n$N收剑而立，凌空纷飞的剑气渐渐散去，留下遍地深深的划痕。\n"NOR, me);
        return;
    }

    if( me->query("neili") < cost || me->query("neili") < 100 )
    {
        me->delete_temp("taiyi-jian/jianqi");
        message_vision(HIC"\n$N内力不足，凌空纷飞的剑气渐渐的散去了，$n不由得舒了口长气。\n"NOR, me, target);
        return;
    }

    if( me->query("env/jianqi") != "破" )
	{
		me->delete_temp("taiyi-jian/jianqi");
		me->delete_temp("taiyi-jian/wang");
	    message_vision(HIC"\n$N收剑而立，凌空纷飞的剑气渐渐散去，留下遍地深深的划痕。\n"NOR, me);
		return;
	}
	if( !me->query_temp("taiyi-jian/jianqi"))
	{
		remove_call_out("effect_taiyijian_jianqi_po");
		return;
	}
	if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword")
	{
		remove_call_out("effect_taiyijian_jianqi_po");
		call_out("effect_taiyijian_jianqi_po", 1, me, target,damage,cost);
		return;
	}

	if( me->is_busy() )
	{
		remove_call_out("effect_taiyijian_jianqi_po");
		call_out("effect_taiyijian_jianqi_po", 1, me, target,damage,cost);
		return;
	}
	//B+
	if( F_KUNGFU->hit_rate( me->query_skill("taiyi-jian",1), target->query_skill("dodge",1), 4, me, target) )
    {
      F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
		me->add("neili", -cost);
		message_vision(HIC "$N眼中精光一闪，一抖手中之剑，发出一道青濛濛的剑气，直逼$n！\n"HIR"只听得「扑哧」一声，$n被$N剑气所伤，身上血冒三丈，！\n" NOR, me, target);
		COMBAT_D->report_status(target);
		remove_call_out("effect_taiyijian_jianqi_po");
		call_out("effect_taiyijian_jianqi_po", 1, me, target,damage,cost);
		return;
    }
	else
	{
		me->add("neili", -cost/3);
		message_vision(HIC"$N眼中精光一闪，一抖手中之剑，发出一道青濛濛的剑气，直逼$n！\n"HIW"$n危急关头激发全身潜力，在千钧一发之时一侧身，$N的剑气划着皮肤飞了过去，$n不由得吓出一身冷汗！\n" NOR, me, target);
		remove_call_out("effect_taiyijian_jianqi_po");
		call_out("effect_taiyijian_jianqi_po", 1, me, target,damage,cost);
		return;
	}
//破的函数
}

void effect_taiyijian_jianqi_wang_start(object me,object target)
{
	if( !me->is_fighting())
	{
		me->delete_temp("taiyi-jian/wang");
		tell_object(me,HIW"\n你收剑而立，四处埋伏的剑气纷纷散去，仿佛什么都没发生过\n"NOR);
		return;
	}
	if( me->query("env/jianqi") != "网" )
	{
		me->delete_temp("taiyi-jian/jianqi");
		me->delete_temp("taiyi-jian/wang");
		tell_object(me,HIW"\n你收剑而立，四处埋伏的剑气纷纷散去，仿佛什么都没发生过\n"NOR);
		return;
	}
	if( !me->query_temp("taiyi-jian/wang"))
	{
		remove_call_out("effect_taiyijian_jianqi_wang_start");
		return;
	}
	if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword")
	{
		remove_call_out("effect_taiyijian_jianqi_wang_start");
		call_out("effect_taiyijian_jianqi_wang_start", 1, me, target);
		return;
	}

	if( me->query("neili") < 100) 
	{
		me->delete_temp("taiyi-jian/jianqi");
	    tell_object(me,HIR "你丹田里突然一窒，内力供应不足，埋伏的剑气顿时消散\n"NOR);
		return;
	}
	if( me->is_busy() )
	{
		remove_call_out("effect_taiyijian_jianqi_wang_start");
		call_out("effect_taiyijian_jianqi_wang_start", 1, me, target);
		return;
	}
	me->add_temp("taiyi-jian/num",1);
	me->add("neili",-25);
	message_vision(CYN"\n$N手中长剑一抖，一道淡淡的青色剑气一闪即逝，仿佛什么都没发生过\n"NOR, me, target);
	tell_object(me,HIW "你已经埋伏了"+me->query_temp("taiyi-jian/num")+"条剑气\n"NOR);
    remove_call_out("effect_taiyijian_jianqi_wang_start");
	call_out("effect_taiyijian_jianqi_wang_start", 1, me, target);
	return;
//网的准备
}

void effect_taiyijian_jianqi_wang_busy(object me,object target)
{
	int lvl;

	if( !me->is_fighting())
	{
		me->delete_temp("taiyi-jian/wang");
		tell_object(me,HIW"\n你收剑而立，四处埋伏的剑气纷纷散去，仿佛什么都没发生过\n"NOR);
		return;
	}

	if( me->query_skill("taiyi-jian",1) >= target->query_skill("dodge",1) )
		lvl = 1;
	else
		lvl = target->query_skill("dodge",1) - me->query_skill("taiyi-jian",1);
	
	if( !F_KUNGFU->hit_rate( lvl, target->query_skill("dodge",1), 3, me, target) )
	{
		if( target->is_busy())
		{
			int damage,jianqi_num;
			jianqi_num = me->query_temp("taiyi-jian/num");
			damage = me->query_skill("taiyi-jian",1) + me->query_skill("taiyi-shengong",1) + me->query_temp("apply/damage");
			damage = damage / 3 * 2 + random(damage);
			damage = damage * jianqi_num;
  	      	tell_object(me,HIW "你眼中精光一闪，捕捉到了对方的一个破绽：是时候了！\n"NOR);
		    message_vision(HIC"\n只听得$N一声长笑，手中剑一抖，$n的四面八方不知道从哪里冒出了无数凌厉的剑气，上下激荡，把所有退路全部封死！\n"NOR, me, target);
     		message_vision(HIR"$n措手不及，一声惨嚎，全身被剑气刺得千疮百孔！\n"NOR, me, target);
      F_KUNGFU->hit_wound("qi", damage, damage/4, me, target);
			COMBAT_D->report_status(target);
			me->start_busy(random(2));
			me->add("neili",-50*jianqi_num);
//伤害计算
		}
		else
		{
	      	tell_object(me,HIW "你眼中精光一闪，捕捉到了对方的一个破绽：是时候了！\n"NOR);
		    message_vision(HIC"\n只听得$N一声长笑，手中剑一抖，$n的四面八方不知道从哪里冒出了无数凌厉的剑气，上下激荡，把所有退路全部封死！\n"NOR, me, target);
     		message_vision(HIR"$n大惊失色，忙收回全部攻势，提起毕生功力，竭尽全力苦苦抵御这无尽的剑气！\n"NOR, me, target);
	    	F_KUNGFU->hit_busy( "confuse", me->query_temp("taiyi-jian/num") * 2, target );
    		me->delete_temp("taiyi-jian/num");
		}
		return;
	}
	else
	{
    	tell_object(me,HIW "你眼中精光一闪，捕捉到了对方的一个破绽：是时候了！\n"NOR);
    	message_vision(HIC"\n只听得$N一声长笑，手中剑一抖，$n的四面八方不知道从哪里冒出了无数凌厉的剑气，上下激荡，把所有退路全部封死！\n"NOR, me, target);
    	message_vision(HIW"$n心中一凛，不敢大意，提起全身功力，前招后架，左躲右闪，$N辛苦布置的剑气居然全部落空！\n"NOR, me, target);
    	me->start_busy(random(5));
    	me->delete_temp("taiyi-jian/num");
		return;
	}
//网的发动
}