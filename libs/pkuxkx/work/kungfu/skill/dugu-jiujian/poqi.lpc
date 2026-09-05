// add no_perform by jpei06132008

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
    int damage, pflv;
    object weapon;
    int howlong=0;
    int npc_chance=0;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「破气式」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("dugu-jiujian", 1) < 150 )
        return notify_fail("你的独孤九剑不够娴熟，不会使用「破气式」。\n");

    if( !objectp(weapon = me->query_temp("weapon"))
     || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你必须使剑才能使用「破气式」！\n");

    if((int)me->query("neili") < 50)
          return notify_fail("你的内力不够呀!\n");

    me->add("neili",-50);
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;

    msg = HIC "\n$N使出独孤九剑" + HIW + "『破气式』" + HIC + "，刷的一剑直剌$n前胸膻中穴，$n急忙一挡，\n" +
	"却挡了个空，$N第二剑又刺了过来，长剑起处，劈、挑、切、刺，一剑连着一剑，\n" +
    "剑尖始终不离$n丹田、关元、膻中、印堂四大要穴！\n"  NOR;

    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6-((pflv>=3?1:0)), me, target) )
    {
        msg += HIR + "$n突然间感到小腹一凉，继而丹田上一阵刺痛，全身气血倒流，霎那间胸口、\n" +
        "锁骨、眉心又接连中剑！$n数道伤口中血喷三丈，已受致命外伤，四肢力量也\n"
        "随真气狂泻而出！$n心中莫名惊骇，口中不禁发出凄厉的惨叫！\n" + NOR;

        damage = (int)me->query_skill("dugu-jiujian", 1);
        damage = damage+random(damage);
		if (target->query("neili") > (me->query("neili")*3/2)) damage += random(damage*3/2);
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        me->start_busy(1+random(2));

        //加入no_exert no_perform效果
        if (!(int)target->query_temp("no_exert") || !(int)target->query_temp("no_perform"))
        {
            if ((!userp(target)))
            {
                npc_chance=target->query("chat_chance_combat");
                target->set_temp("chat_chance_combat",npc_chance);
                target->set_temp("no_exert",1);
                if ( F_KUNGFU->hit_rate( me->query("int"), target->query("int"), 6-((pflv>=3?1:0)), me, target) )
					target->set_temp("no_perform", 1);
                target->delete("chat_chance_combat");
                howlong=(int)me->query_skill("sword", "dugu-jiujian");
                howlong=howlong/40+5;
                if(howlong>30)  howlong=30;
				if (pflv>=2) howlong += pflv*5;
                if(me->query_temp("magic_set")) howlong+=howlong/2;
				remove_call_out("remove_effect_npc1");
                call_out("remove_effect_npc1",howlong,target,me);
             }
             else
             {
                howlong=(int)me->query_skill("sword", "dugu-jiujian");
                howlong=howlong/40+5;
                if(howlong>20)  howlong=20;
				if (pflv>=2) howlong += pflv*3;
                target->set_temp("no_exert",1);
                if ( F_KUNGFU->hit_rate( me->query("int"), target->query("int"), 9-((pflv>=3?2:0)), me, target) )
					target->set_temp("no_perform", 1);
				remove_call_out("remove_effect_player1");
                call_out("remove_effect_player1",howlong,target,me);
             }
			if (pflv>=5)
			{
				if(!target->query_temp("poqi_slow_eff")) {
					target->add_temp("apply/attack_speed", -300);
					target->set_temp("poqi_slow_eff", 300);
					target->set_temp("active_debuff/dugu-jiujian.poqi/name", "独孤九剑.破气式");     //buff名称
					target->set_temp("active_debuff/dugu-jiujian.poqi/last_time", time() + howlong ); //持续时间
					target->set_temp("active_debuff/dugu-jiujian.poqi/effect1", "攻击速度-300%");   //效果描述1
				}
				else if (target->query_temp("active_debuff/dugu-jiujian.poqi/name"))
					target->set_temp("active_debuff/dugu-jiujian.poqi/last_time", time() + howlong ); //持续时间
			}
             if (target->query_temp("no_perform"))
                    msg += MAG"$n不明所以，被剑气所伤，一口真气再也提不上来，特殊攻击也无法施展！\n"NOR;
             else   msg += MAG"$n不明所以，被剑气所伤，一口真气再也提不上来！\n"NOR;
       }
    } else
    {
        me->start_busy(2);
        if (random(2) == 0)
            msg += HIG + "$n微一迟疑，小腹上已经感到森森剑意！$n大惊之下两掌虚按，双脚前蹬，\n" +
                    "整个上身成折叠状拼命后射！$n正绝望时，突觉剑意顿去，却是$N招式用老，\n" +
                    "挺身收剑。$n双股战栗，只觉一丝斗志也无。\n" + NOR;
        else
            msg += HIG + "$n身经百战，于此性命攸关之际毫不慌乱。左掌猛斫，以排山倒海的攻势\n" +
                    "将$N身躯格在外门，同时小腹猛向内缩，竟然生生向后吸进两寸！$N情知对方内力\n"
                    "过于雄厚，徒劳无益。只得回剑守势。\n" + NOR;
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}

void remove_effect_npc1(object target)
{
	int eff;
       if (!target) return;
       target->set("chat_chance_combat",target->query_temp("chat_chance_combat"));
       if ( target->query_temp("no_exert") || target->query_temp("no_perform"))
               message_vision(HIC"\n$N真气逐渐聚集丹田，终于缓过气来！\n"NOR,target);
       target->delete_temp("no_exert");
       target->delete_temp("no_perform");
		if (eff = target->query_temp("poqi_slow_eff")) {
			target->add_temp("apply/attack_speed", eff);
			target->delete_temp("poqi_slow_eff");
			target->delete_temp("active_debuff/dugu-jiujian.poqi");     
		}
}

void remove_effect_player1(object target)
{
	int eff;
       if (!target) return;
       if ( target->query_temp("no_exert") || target->query_temp("no_perform"))
               message_vision(HIC"\n$N真气逐渐聚集丹田，终于缓过气来！\n"NOR,target);
       target->delete_temp("no_exert");
       target->delete_temp("no_perform");
		if (eff = target->query_temp("poqi_slow_eff")) {
			target->add_temp("apply/attack_speed", eff);
			target->delete_temp("poqi_slow_eff");
			target->delete_temp("active_debuff/dugu-jiujian.poqi");     
		}
}

