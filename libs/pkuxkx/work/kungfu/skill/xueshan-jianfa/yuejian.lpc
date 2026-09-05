// File		: yuejian.c
// Created By	: iszt, 2006-09-03

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define Menpai "雪山派"

string perform_name(){ return HIY" 月  剑 "NOR; }
int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
	object weapon;
	string msg;
	int cd_time,last_time;
	int sk_lv1,sk_lv2;
	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) 
	|| !living(target))
		return notify_fail("「月剑」只能对战斗中的对手使用。\n");


    if ( !me->query("safari_skill/xs_yuejian") ) return 0;

	 if ( time() < me->query_temp("no_yuejian") )
        return notify_fail("你刚刚使用过「月剑」，气息还未平复。\n");


	sk_lv1 = me->query_skill("xueshan-jianfa", 1);
	sk_lv2 = me->query_skill("xueshan-neigong", 1);


	if( sk_lv1 < 400 )
		return notify_fail("你的雪山剑法功力不够，使不出「月剑」。\n");

	if( (int)me->query_skill("sword", 1) < 400 )
		return notify_fail("你的基本剑法还要多加练习才是！\n");
	if( sk_lv2 < 500 )
		return notify_fail("你的雪山内功功力太浅，使不出「月剑」。\n");
		
	if( (int)me->query("max_neili") < 3000 )
		return notify_fail("你的内力修为太浅，使不出「月剑」。\n");
	if( (int)me->query("neili") < 2000 )
		return notify_fail("你的真气不够，使不出「月剑」。\n");
    if( me->query("family/family_name")!=Menpai)
		return notify_fail("你不是雪山弟子，使不出「月剑」。\n");

	cd_time = 45 + sk_lv1/50;

	if (cd_time > 120)
	{
		cd_time = 120;
	}
	if (me->query("chushi/done"))
	{
		cd_time *= 2;
	}	

	me->set_temp("no_yuejian",time()+cd_time);
	me->add("neili", -sk_lv1/2);
	last_time = sk_lv2/150;
	if (last_time>18)
	{
		last_time = 18;
	}
	if (me->query("chushi/done"))
	{
		last_time /= 2;
	}	
  me->add_temp("apply/damage",me->query_skill("xueshan-jianfa",1)/4);
  me->set_temp("active_buffer/family","雪山派");
  me->set_temp("active_buffer/xueshan-jianfa.yuejian/name", "月剑");                          //buff名称
  me->set_temp("active_buffer/xueshan-jianfa.yuejian/last_time", time() + last_time );                //持续时间
  me->set_temp("active_buffer/xueshan-jianfa.yuejian/effect1", "大量缩减雪山剑法特殊招式的施展时间");         //效果描述1
	msg = HIY"\n$N剑法一转，剑影变得若隐若现，正是雪山剑法之「月剑」！\n"NOR;
	message_vision(msg,me,target);
	
	call_out("remove_effect", last_time , me);
	return 1;
}

void remove_effect(object me)
{
	if (!me) return;

	if( me->query_temp("active_buffer/xueshan-jianfa.yuejian") ){
    me->delete_temp("active_buffer/xueshan-jianfa.yuejian");
    if ( sizeof(me->query_temp("active_buffer"))==1 )
      me->delete_temp("active_buffer");
		message_vision(YEL"\n$N「月剑」剑法使毕，若隐若现的剑势也随之消失。\n" NOR,me);
		return;
	}
}

int help(object me)
{
        write(WHT"\n雪山剑法「月剑」："NOR"\n");
        write(@HELP
	雪山剑法的隐藏变化，由白自在在侠客岛归来后创出，可以有效缩短某些雪山perform的busy时间。
	
        要求：  内力 2000 以上；      
                最大内力 3000 以上；  
                基本剑法等级 400 以上；
                雪山剑法等级 400 以上；
                雪山内功等级 500 以上；    
                且使用雪山剑法。
HELP
        );
        return 1;
}
