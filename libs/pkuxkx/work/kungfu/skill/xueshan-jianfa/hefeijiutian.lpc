// File         : hefeijiutian.c
// Created By   : iszt, 2006-09-03

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;
#define Menpai "雪山派"

string perform_name(){ return HIC"鹤飞九天"NOR; }
int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        object weapon;
        string msg;
        string weaponName;
        int ap, dp;
        int damage = 0;
        int p;
        
        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「鹤飞九天」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xueshan-jianfa", 1) < 300 )
                return notify_fail("你的雪山剑法功力不够，使不出「鹤飞九天」。\n");

        if( (int)me->query_skill("sword", 1) < 300 )
                return notify_fail("你的基本剑法还要多加练习才是！\n");

        if( (int)me->query_skill("xueshan-neigong", 1) < 300 )
                return notify_fail("你的雪山内功功力太浅，使不出「鹤飞九天」。\n");
                
        if( (int)me->query("max_neili") < 4000 )
                return notify_fail("你的内力修为太浅，使不出「鹤飞九天」。\n");
        if( (int)me->query("neili") < 2000 )
                return notify_fail("你的真气不够，使不出「鹤飞九天」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
                return notify_fail("你真气运转方式不对，使不出「鹤飞九天」。\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
//            || me->query_skill_mapped("sword") != "xueshan-jianfa")
                return notify_fail("你不装备一把剑，使不出剑法「鹤飞九天」。\n");

        weaponName = weapon->query("name");
        me->add("neili", - 100 - me->query("jiali") - me->query_skill(me->query_skill_mapped("force"), 1));
        msg = YEL"\n$N"YEL"提起手中$w"YEL"，运劲向$n"YEL"掷去，这一招"HIC"「鹤飞九天」"NOR+YEL"使得既狠且准，$w"YEL"伴着破空之声直射向$n"YEL"！\n"NOR;

        ap = me->query_skill("xueshan-jianfa", 1);
        ap = ap * ap / 20 * ap + me->query("combat_exp")/2;
        dp = target->query("combat_exp"); 
//C-
        if ( F_KUNGFU->hit_rate( ap, dp, 9, me, target) )
        {
                msg += HIR"$n"HIR"眼见$w"HIR"飞来却无法避开，结果$w"HIR"在$n"HIR"身上对穿而出，鲜血溅得满地！\n"NOR;
                me->start_busy(3);
                if(!target->is_busy()) 
                	target->start_busy(2);
                damage = me->query_skill("force") + me->query_skill("sword","xueshan-jianfa");
                damage += me->query("jiali")*4;
                damage += weapon->query("weapon_prop/damage");
                damage = damage * me->query("con") / target->query("con");
                if (damage < 4000 ) damage = 4000;
                F_KUNGFU->hit_wound("qi", damage, damage, me, target);
                if(!weapon->query("no_drop"))
                        weapon->move(environment(me));
                else
                {
                        weapon->unequip();
                        destruct(weapon);
                }
//B-
        } else if( F_KUNGFU->hit_rate( ap, dp, 6, me, target) )
        {
                msg += RED"$n"RED"眼见$w"RED"飞来，连忙提气纵跃闪躲，却还是被划出一道深及见骨的可怕伤口！\n"NOR;
                me->start_busy(2);
                if(!target->is_busy())
                	target->start_busy(1);
                damage = me->query_skill("force") + me->query_skill("sword","xueshan-jianfa");
                damage += me->query("jiali")*4;
                damage += weapon->query("weapon_prop/damage");
                damage -= target->query_skill("dodge");
                damage -= target->query_skill("parry");
                damage = damage * me->query("dex") / target->query("dex");
             //   damage = damage/2;
                if (damage < 3000 ) damage = 3000;
                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                if(!weapon->query("no_drop"))
                        weapon->move(environment(me));
                else
                {
                        weapon->unequip();
                        destruct(weapon);
                }
        }
        else
        {
                msg += HIG"$n"HIG"眼见$w"HIG"飞来，伸手将其抓了过去放在自己身上，攻势毫不减弱！\n"NOR;
                me->start_busy(1);
                if(!target->is_busy())
                  target->start_busy(1);
                if(!weapon->query("no_give"))
                        weapon->move(target);
                else
                {
                        weapon->unequip();
                        destruct(weapon);
                }
        }
		if (me->query_temp("active_buffer/xueshan-jianfa.yuejian"))
		{     
			me->add("neili", -200);

			if (random(10)==0)
			{
				me->start_busy(0);
				me->add("neili", -100);
			}
			else
			{
				me->start_busy(1);
			}
		}
        if(wizardp(me))   printf("\tdamage: %d", damage);

        msg = replace_string(msg, "$w", weaponName);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}

