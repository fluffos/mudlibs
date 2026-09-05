// File         : chandou.c
// Created By   : iszt@pkuxkx, 2006-11-23

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"
#define Menpai "雪山派"
inherit F_SSERVER;

string *xue_name = ({ 
"百会","印堂","风府","扶突","天牖","廉泉","翳风",
"膻中","气海","神阙","极泉","章门","中府","乳根",
"天枢","风门","天宗","志室","腰眼","命门","肩井",
"尺泽","曲池","内关","阳溪","承扶","风市","少海",
});

string perform_name(){ return HIR" 缠  斗 "NOR; }

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}
int perform(object me, object target)
{
        object weapon;
        string msg, xue1, xue2;
        int busynum;
        int skill = me->query_skill("xueshan-jianfa", 1);
        int ap, dp, damage;
        int p;
        string dodge_skill;

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「缠斗」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 60 )
                return notify_fail("你的雪山剑法修为太浅。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 100 )
                return notify_fail("你的雪山剑法基础太弱，还无法进行「缠斗」。\n");

        if( (int)me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法还要多加练习才是！\n");

        if( (int)me->query_skill("xueshan-neigong", 1) < 100 )
                return notify_fail("你的雪山内功功力太浅，无法进行「缠斗」。\n");

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力修为太浅，无法进行「缠斗」。\n");
        if( (int)me->query("neili") < 400 )
                return notify_fail("你的真气不够，无法进行「缠斗」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
                return notify_fail("你真气运转方式不对，无法进行「缠斗」。\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
//            || me->query_skill_mapped("sword") != "xueshan-jianfa")
                return notify_fail("你不装备一把剑，使不出剑法「缠斗」。\n");
        if( target->is_busy() )
                return notify_fail("对方正手忙脚乱，你且不必用「缠斗」制敌。\n");

        if( me->query_temp("chandou") )
                return notify_fail("你刚使完「缠斗」，连续出招极易露出破绽！\n");
        me->set_temp("chandou", 1);

        xue1 = xue_name[random(sizeof(xue_name))];
        switch(random(3))
        {
        case 0: xue1 = HIW"「" + xue1 + "穴」"NOR; break;
        case 1: xue1 = HIB"「" + xue1 + "穴」"NOR; break;
        case 2: xue1 = HIY"「" + xue1 + "穴」"NOR; break;
        }
        xue2 = xue_name[random(sizeof(xue_name))];
        switch(random(3))
        {
        case 0: xue2 = HIW"「" + xue2 + "穴」"NOR; break;
        case 1: xue2 = HIB"「" + xue2 + "穴」"NOR; break;
        case 2: xue2 = HIY"「" + xue2 + "穴」"NOR; break;
        }

        msg = HIW"\n$N"HIW"默默循着雪山剑法之「缠斗」剑意，隐隐笼罩住了$n身上几处大穴！\n\n";
        switch(random(4))
        {
        case 0:
                msg += HIM"突然间$N"HIM"身形一晃，手中"+weapon->query("name")+HIM"连递数个虚招，迅速欺近$n"HIM"身旁，\n伸指点向$n"+xue1+xue2+HIM"！"NOR;
                ap = skill * (me->query_dex()-10) * me->query_skill("sword", 1);
                dp = target->query("combat_exp");
                damage = me->query_skill("force") / 2 - target->query_str();
                break;
        case 1:
                msg += HIG"$N"HIG"辗转腾挪中招招指向$n"+xue1+HIG"，却趁着$n"HIG"着意防护之时，\n"+weapon->query("name")+HIG"突然间夹着劲风直取$n"+xue2+HIG"！"NOR;
                ap = skill * skill * (me->query_int()-10);
                dp = target->query("combat_exp") / 2 * (1 + target->query("int") / 20);
                damage = skill / 4 + me->query_temp("apply/damage") - target->query_skill("force", 1) / 3;
                break;
        case 2:
                msg += HIC"$N"HIC"激斗中瞅准$n"HIC"的破绽，从当中大开的空门中和身而上，左手持剑，\n右手拂向$n"+xue1+xue2+HIC"！"NOR;
                ap = skill * me->query_skill("dodge", 1)/10 * me->query_skill("sword", 1);
                dp = target->query_skill("parry", 1) * target->query_skill("dodge", 1)/10 * target->query_str();
                damage = skill / 4 + me->query_str() * 3 - target->query("jiali")/2;
                break;
        case 3:
                msg += HIR"电光火石间$N"HIR"倒转剑身，以剑刃抵挡住$n"HIR"猛如疾风骤雨般的攻势，\n剑柄向$n"+xue1+xue2+HIR"重重撞去！"NOR;
                ap = skill * (me->query_con()-10) * me->query_skill("parry", 1);
                dp = target->query("combat_exp");
                damage = skill - target->query_con() * 3;
                break;
        }

        msg += "\n";
        message_vision(msg, me, target);
        msg = "";
//B-        
        if( F_KUNGFU->hit_rate( ap, dp, 6, me, target) )
        {
                if(damage >= 300)
                {
                        msg += HIG"\n结果$N"HIG"一击命中，戳在$n"HIG"的"+xue2+HIG"上，封住了$n"HIG"的穴道，造成了相当严重的内伤！";
                        msg += HIR"\n$n"HIR"只觉"+xue2+HIR"受到强大无匹的内力猛烈的撞击，痛哼一声，吐出一口鲜血！\n";
                        me->start_busy(random(2));
                        busynum = 4 + skill/25 - target->query_skill("force")/75;
                        if(busynum < 4)
                                busynum = 4;
                        F_KUNGFU->hit_busy( "jiemai", busynum, target );
                        me->add("neili", - busynum * 40);
                        damage = random(damage) + damage/2;
                        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(target);
                }
                else if(damage >= 0)
                {
                        msg += HIB"\n结果$N"HIB"一击命中，戳在$n"HIB"的"+xue2+HIB"上，封住了$n"HIB"的穴道，令$n"HIB"动弹不得！";
                        msg += HIW"\n$n"HIW"只觉"+xue2+HIW"微微一麻，真气立时受阻，手脚不灵，已然受制于敌。\n";
                        me->start_busy(1);
                        busynum = 3 + skill/25 - target->query_skill("force")/60;
                        if(busynum < 3)
                                busynum = 3;
                        F_KUNGFU->hit_busy( "dianxue", busynum, target );
                        me->add("neili", - busynum * 25);
                        damage = random(damage) + damage/2;
                        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(target);
                }
                else
                {
                        damage = -damage;
                        damage *= 4;
                        damage += random(damage);
                        msg += HIB"\n$N"HIB"一击命中，戳在$n"HIB"的"+xue2+HIB"上，却被$n"HIB"以内力反击了回来！";
                        msg += "\n"HIR;
                        msg += COMBAT_D->damage_msg(damage, "反弹伤");
                        me->start_busy(3);
                        me->add("neili", -200);
                        F_KUNGFU->hit_wound("qi", damage, damage/2, target, me);
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(me);
                }
        }
        else
        {
                dodge_skill = target->query_skill_mapped("dodge");
                if(!dodge_skill)
                        dodge_skill = "dodge";
                msg += HIG + SKILL_D(dodge_skill)->query_dodge_msg(target, 1) + NOR;
                me->start_busy(3);
                me->add("neili", -200);
                message_vision(msg, me, target);
        }

        
        // modified by jpei 05022008
		if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
		{
             me->add("neili", -200);
			 if (skill > 1400)
			 {
				p=3;
			 }
			 else
			{
				p=10-skill/200;
			}
			if (random(p)==0)
			{
				me->start_busy(0);
				me->add("neili", -100);
			}
			else
			{
				me->start_busy(1);
			}
		}
		p=target->query("int");
		if (p<39)
		{
			busynum=40-p;
		}
		else
		{
			busynum=2;
		}
        call_out("remove_effect", busynum, me);

        return 1;
}

void remove_effect(object me)
{
        if (!me)
                return;
        me->delete_temp("chandou");
}
