// tianlei.c 铁掌--凝血神抓

#include <ansi.h>
#include <combat.h>
#define Menpai "天地会"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        int damage, force;
        string msg;
        object weapon;
		int hit_rate;

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("凝血神抓只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("yunlong-zhua", 1) < 150 )
                return notify_fail("你的凝血神抓还未练成，不能使用！\n");

        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力不足，不能使用凝血神抓！\n");

        if( (int)me->query_skill("yunlong-zhua", 1) < 120 )
                return notify_fail("你的云龙抓不够娴熟，不能使用凝血神抓。\n");

        if((int)me->query_skill("cangming-gong", 1) < 100 )
                return notify_fail("你的浩气苍冥功火候不够，不能使用凝血神抓。\n");

    if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        && !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        && me->query_skill_mapped("force") != "cangming-gong" )
            return notify_fail("你不使用浩气苍冥功，怎么能使用「凝血神抓」？\n");                
   //门派大招影响
	if (me->query_temp("active_force_buffer/cangming-gong.zhengqi") && me->query_temp("cmg/zhengqi/times") < me->query_temp("cmg/zhengqi/point")&& !me->query_temp("cmg_zq_buff"))
	{
		hit_rate=1;
		me->add_temp("cmg/zhengqi/times",1);
		me->set_temp("cmg_zq_buff",1);
		me->add("neili",-600);
		msg = HIY "$N大气凛然，临战神勇！\n" NOR;
		message_vision(msg,me,target);

	}
	else
	{
		hit_rate=6;
	}
		
		msg = RED "\n$N把全身的劲力注入双掌,高高跃起，**凝血神抓**，一抓抓来，势不可挡！\n"NOR;



        if( (weapon = target->query_temp("weapon")) && 
        	  !me->query("env/ningxue") &&
        	  objectp(weapon) ) {
//命中率级别B-
                if( F_KUNGFU->hit_rate( me->query_str(), (int)target->query_str(), hit_rate, me, target ) ) {
                        msg += HIM"\n$p只觉得头皮发麻，全身血脉凝滞，手腕似要折断，手中"
                         + weapon->query("name") + "脱手而出。\n" NOR;
                        message_vision(msg, me, target);
                        weapon->unequip();   //picewolf修改，dest出错
                        destruct(weapon);
                        force = 200;
                 }
                 else{
                        msg += HIY"\n$p忽觉手腕冰冷，手臂急缩，使出吃奶的力气向后倒过去，这才保住了兵刃。\n" NOR;
                        message_vision(msg, me, target);
                        force = 100;
                 }
                 me->start_busy(2);
        }
        else{
                if( F_KUNGFU->hit_rate( me->query_str(), (int)target->query_str(), hit_rate, me, target ) ){
                        me->start_busy(3);
                        if (!target->is_busy()) target->start_busy(random(4));
                        damage = (int)me->query_skill("yunlong-zhua", 1);
                        damage = 3 * damage + 2 * random(damage);
                        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);           
                        if (!random(4)) 
                        {
                            //target->set_temp("death_cond_origin/nx_zhua", me);
							F_POISON->poison_attack(me,target,"nx_zhua",damage/50);
                        }
                        if( damage < 300 ) 
                        	msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
                        else if( damage < 400 ) 
                        	msg += HIY"\n结果胸口剧痛，$n「哇」地一声吐出一口鲜血！\n"NOR;
                        else if( damage < 500 ) 
                        	msg += RED"\n结果「呜哇！」一声惨叫，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
                        else 
                        	msg += HIR"\n结果只听见几声喀喀轻响，$n一声绝望的惨叫，翻着白眼如滩软泥塌了下去！\n"NOR;
                        
                        force = 500;
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(target);
                } else{
                        me->start_busy(1);
                        msg += HIY"\n$p危急中伏地连打几个滚，狼狈地避过了这凌厉的一招，已吓得倒抽凉气，脸色苍白！\n" NOR;
                        message_vision(msg, me, target);
                        force = 100;
                }
                if(wizardp(me)) tell_object(me, "ningxue damage: " + damage +"。\n\n");
        }
	if (me->query_temp("cmg_zq_buff"))
	{
		me->delete_temp("cmg_zq_buff");
	}     
	me->add("neili", - force);
        return 1;
}

