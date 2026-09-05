// chan.c 玉箫剑法「缠」字诀
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    object weapon;
	int rate_fix,k,pflv;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() ||  !me->is_fighting(target) )
         return notify_fail("「缠」字诀只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword") */
        return notify_fail("你右手无剑，如何使得出剑法绝招？\n");

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

    if( (int)me->query_skill("bihai-shengong", 1) < 50 )
        return notify_fail("你的碧海神功不够，无法体会「缠」字诀的神髓。\n");

    if( (int)me->query_skill("yuxiao-jian", 1) < 50 )
        return notify_fail("你的玉箫剑法不够娴熟，不会使用「缠」字诀。\n");

    if( (int)me->query("neili") < 400  )
        return notify_fail("你的内力不够。\n");

	pflv = me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "桃花岛") 
			pflv=0;

	msg = HIY "$N"HIY"剑招忽急忽缓，举手投足间竟有箫声隐隐，其势抑扬顿挫柔肠百转，
$n"HIY"听在耳中说不出的受用，恍惚间似乎身处"+GRN+"竹林幽径"+HIY+"闭目浅呷香茗，
出招也慢了下来！\n\n"NOR;

    me->start_busy(2);
    //完成新手任务，对初期有帮助。后期基本忽视。

	rate_fix=9;
	k=me->query_temp("active_buff/qimen-baguazhen.buzhen/cengshu");
	if (k>0)
	{
		if (me->query("safari_skill/thd_huoxin"))
		{	
			if (!me->query_temp("qmbgz.huoxin_done"))
			{
				if (k<18)
				{
					rate_fix -= (int)(k>>1);
				}
		        message_vision(HIG"$N在奇门八卦阵的影响下，越战越有灵性！\n"NOR,me,target);
				me->set_temp("qmbgz.huoxin_done",1);
			}
		}
	}
	if (pflv>=5) rate_fix -= 2;
	else if (pflv>=3) rate_fix -= 1;

	if( F_KUNGFU->hit_rate( me->query("combat_exp")+me->query("exp/taohuanewbie"), target->query("combat_exp"), rate_fix, me, target) )
    {
        msg +=HIR "$p"HIR"已经来不及反应，$P"HIR"手中玉箫连指，已经封住了$p"HIR"四肢各大要穴，
$p"HIR"明知已经一败涂地，脸上却还兀自挂着痴迷的微笑不能醒来。\n\n" NOR;
        F_KUNGFU->hit_busy( "jiemai", (int)me->query_skill("yuxiao-jian") /10, target );
    }
    else 
    {
        msg +=HIW "$p"HIW"正欲翩翩起舞，突觉剑气袭体，定睛看去$P"HIW"的剑尖已经探到自己章门穴上！
$p"HIW"大惊后跃总算跳出了危险范围，背后已经出了一身冷汗！\n\n" NOR;
    }
    me->add("neili", -100);
    message_vision(msg, me, target);

    return 1;
}

