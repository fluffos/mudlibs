// File         : liuchu.c
// Created By   : iszt@pkuxkx, 2006-10-12

#include <ansi.h>
#include <combat.h>
#define Menpai "雪山派"
inherit F_SSERVER;

string perform_name(){ return HIR"六 出 诀"NOR; }

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, level;
        int hitnum;
        int skill = me->query_skill("xueshan-jianfa", 1);
		mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "xueshan-jianfa" ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「六出诀」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 60 )
                return notify_fail("你的雪山剑法修为太浅。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 100 )
                return notify_fail("你的雪山剑法修为不够，使不出「六出诀」。\n");

        if( (int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法还要多加练习才是！\n");
        if( (int)me->query_skill("xueshan-neigong", 1) < 100 )
                return notify_fail("你的雪山内功功力太浅，使不出「六出诀」。\n");

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力修为太浅，使不出「六出诀」。\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("你的真气不够，使不出「六出诀」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
                return notify_fail("你真气运转方式不对，使不出「六出诀」。\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
//            || me->query_skill_mapped("sword") != "xueshan-jianfa")
                return notify_fail("你不装备一把剑，使不出「六出诀」。\n");
 
        level = 10;
        if ( (int)me->query_skill("xueshan-neigong",1) > 600) level = 4;
        else if ( (int)me->query_skill("xueshan-neigong",1) > 400) level = 7;
        else level = 10;
        hitnum = 2 + ( skill<100 ? 0 : (skill>180 ? 4 : (skill-100)/20) );
        me->add("neili", -200 - hitnum*20);
        msg = HIR "\n$N手腕一抖，使出雪山剑法"HIW"「六出诀」"HIR"，快如电闪般向$n连续击出"
                        +chinese_number(hitnum)+"剑！\n" NOR;
        message_vision(msg, me, target); 
        // 需要配合其他perform提高damage或者attack，这里不能太高。 added damage/attach by jpei
        me->add_temp("apply/damage", (int)me->query_skill("sword","xueshan-jianfa")/level);       
        me->add_temp("apply/attack", (int)me->query_skill("sword","xueshan-jianfa")/level); 
        for(i=0; i<hitnum; i++)
                if(me->is_fighting(target))
				{
						me->set_temp("attack_val", attack_val);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
                }
				else
                        break;   
        me->add_temp("apply/damage", -(int)me->query_skill("sword","xueshan-jianfa")/level);
        me->add_temp("apply/attack", -(int)me->query_skill("sword","xueshan-jianfa")/level); 
        msg = HIY"$N"HIY + chinese_number(i) + "招使毕，不再抢攻，凝神注视着$n"HIY"的动作。\n"NOR;
        message_vision(msg, me, target);
		if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
		{
			me->add("neili", -200);
			me->start_busy(1);
		}
		else
		{
			me->start_busy(2+random(2));
		}

        return 1;
}

