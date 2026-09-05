
// 活色生香 Zine Oct 28 2010
// 加强一些 by yhzzyahoo @2016.1.4
#include <ansi.h>
#include <char.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int remove_eff(object me)
{
    if (me)
    {
        me->delete_temp("tsz/huose");
    }
}

int perform(object me, object target)
{
    object weapon;
    int buff, huose, x, y, z, i = 5;
    int q = 0;
    int p = 0;
    string msg, dodge_skill;
    mapping attack_val = ([
                          "base" : ([ "weapon" : "staff", ]), //基本功夫类型
                           "skill" : ([ "weapon" : "tianshan-zhang", ]), //高级技能名称
                           ]);

    if (!(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name") != "星宿派") //判师出师不许用
    {
        return notify_fail("你离开星宿派的时候已承诺终生不再施展活色生香。\n");
    }
    if (me->query("newbiediaoyu") || me->query("newbie_hongdou"))
    {
        return notify_fail("你因为年少时候的肆意贪玩，对活色生香研究过少，无法施展活色生香。\n");
    }
	x=me->query_skill("poison", 1);

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target) || !living(target))
        return notify_fail("「活色生香」只能对战斗中的对手使用。\n");

    if ((int)me->query_skill("tianshan-zhang", 1) < 100)
        return notify_fail("你的天山杖法功力太浅，无法施展活色生香。\n");

    if ((int)me->query_skill("staff", 1) < 100)
        return notify_fail("你的基本杖法功力太浅，无法施展活色生香。\n");

    if ((int)x < 100)
        return notify_fail("你的基本毒技太差，无法施展活色生香。\n");

    if ((int)me->query_skill("huagong-dafa", 1) < 100)
        return notify_fail("你的内功功力太浅，无法施展活色生香了。\n");

    if ((int)me->query("max_neili") < 500)
        return notify_fail("你的内力太浅，无法施展活色生香。\n");

    if ((int)me->query("neili") < 200)
        return notify_fail("你的真气不够，无法施展活色生香。\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) && 
         me->query_skill_mapped("force") != "huagong-dafa")
        return notify_fail("你用什么为内功基础来使「活色生香」?\n");

    if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "staff" )
/*        || me->query_skill_mapped("staff") != "tianshan-zhang") */
        return notify_fail("你使得了「活色生香」么?\n");

    if (me->query_temp("tsz/huose"))
    {
        return notify_fail("你刚刚使用过「活色生香」，要休息一会才能再用。\n");
    }

    if (target->query_condition("xxfog-poison"))
    {
        p = p + 1;
    }
    if (target->query_condition("xx-poison-palsy"))
    {
        p = p + 1;
    }
    if (target->query_condition("xx_poison"))
    {
        p = p + 1;
    }
    if (target->query_condition("xxx_poison"))
    {
        p = p + 1;
    }
    if (target->query_condition("sanxiao_poison"))
    {
        p = p + 1;
    }
    if (target->query_condition("fs_poison"))
    {
        p = p + 1;
    }
    if (target->query_condition("chuanxin"))
    {
        p = p + 1;
    }
    if (p > 5)
    {
        p = 5;
    }
    huose = 100 + (int)me->query("xxpfm/huose");
    if (huose > 250)
    {
        huose = 250;
    }
    if (me->query("combat_exp") > 250000000)  //经验大于250M，威力回归
    {
        i = 5;
    }
	else
	{
		if (me->query("combat_exp") > 50000000)
		{
			i = 1;
		}
		else
		{
			if (me->query("combat_exp") > 30000000)
			{
				i = 2;
			}
			else
			{
				if (me->query("combat_exp") > 20000000)
				{
					i = 3;
				}
				else
				{
					if (me->query("combat_exp") > 5000000)
					{
						i = 4;
					}
				}

			}
		}
	}


    message_vision("\n$N幻化出漫天杖影，正是"HIW"[天山杖法]"NOR"不传之秘-"HIR"活色生香"NOR"。\n", me);
    if (me->query("xxnewbiequest"))
    {
        q = 2;
    }
    buff = (int)(me->query_skill("staff", 1) + me->query_skill("tianshan-zhang", 1)) / (8 - q);

    me->add_temp("apply/attack", buff * huose * i / 500);
    me->add_temp("apply/damage", buff * (i + p) / 4);
    message_vision("\n"HIR"活色生香"NOR"第一式"HIY"『画龙点睛』\n"NOR, me);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
    me->add_temp("apply/attack", -buff * huose * i / 500);
    me->add_temp("apply/damage", -buff * (i + p) / 4);

   /* x = 20 - (me->query("age"));
    if (x <= 0)
    {
        x = 1;
    }*/
    if (me->query("xxnewbiequest2"))
    {
        q = q + 1;
    }
//    buff = buff * (12 + q) * x;
	x=random(x*3/2);
    buff = buff * (12 + q);
    if (buff < 600)
    {
        buff = 600;
    }
    if (buff > 4500)
    {
        buff = 4500;
    }
    message_vision("\n"HIR"活色生香"NOR"第二式"HIG"『江天一色』\n"NOR, me);
//解谜新手任务稳定命中率C-，否则命中率级别是（B/2+B-/2）&（A到E-），实际级别在F+级别到C+级别浮动
    if ((me->query("xxnewbiequest") && me->query("xxnewbiequest2") &&
         F_KUNGFU->hit_rate(me->query_skill("tianshan-zhang", 1), target->query_skill("parry", 1), 8, me, target)) ||
        (F_KUNGFU->hit_rate(me->query_skill("tianshan-zhang", 1), target->query_skill("parry", 1), 4 + random(2), me, target) &&
         !F_KUNGFU->hit_rate(target->query("combat_exp") * 5 / (i + q), me->query("combat_exp") * 2, 8, me, target)))
    {
        message_vision("\n$N手上杖影连环，打在$n天灵盖上。\n", me, target);
        F_KUNGFU->hit_wound("qi", (buff * (i + p) * huose / 500)+x, buff * i * huose / 1000, me, target);
        COMBAT_D->report_status(target);
        y = 1;
    }
    else
    {
        message_vision("\n$N惊出一身冷汗，却险险避过了这一招。\n", target);
        y = 0;
    }
    buff = buff / 100;
    if (buff > 4)
    {
        buff = 4;
    }
    if (buff < 2)
    {
        buff = 2;
    }
    message_vision("\n"HIR"活色生香"NOR"第三式"HIB"『生离死别』\n"NOR, me);
//命中率级别从F+级别到A-级别
    if (F_KUNGFU->hit_rate(me->query("con") * (i + q) / 5, target->query("con") * 2 / 3, 9, me, target))
    {
        message_vision("\n$N掌中内力催动，杖影乱动，$n看得手忙脚乱。\n", me, target);
        F_KUNGFU->hit_busy("confuse", (buff + huose / 100), target);
        y = 1;
    }
    else
    {
        message_vision("\n$N掌中内力催动，杖影乱动，$n却丝毫不为所动。\n", me, target);
        y = 0;
    }
    message_vision("\n"HIR"活色生香"NOR"第四式"HIM"『暗香浮影』\n"NOR, me);
    if (y)
    {
        message_vision("\n$N暗中凝聚内力，放出毒雾，$n却迎风反击，破茧而出。\n", me, target);
    }
    else
    {
        message_vision("\n$N暗中凝聚内力，放出毒雾，$n目瞪口呆，被大片毒雾罩住。\n", me, target);
        //target->set_temp("death_cond_origin/xxfog-poison", me);
		F_POISON->poison_attack(me,target,"xxfog-poison", buff + huose / 100);
    }
    me->add("neili", -100);
    if (random(100) + p > 95 && target->query("combat_exp") > (me->query("combat_exp") * 19 / 20))
    {
        tell_object(me, HIR"你在实战中对活色生香的运用理解地更深刻了一些！\n"NOR);
        me->add("xxpfm/huose", 1); //熟练度对pfm的影响
    }
    me->set_temp("tsz/huose", 1);
    call_out("remove_eff", buff, me);
    return 1;
}

