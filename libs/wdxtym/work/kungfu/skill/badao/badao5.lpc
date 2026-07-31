#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIR "地狱三斩" NOR "」"
string query_name() { return "地狱"ZJBR"三斩"; }
inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能在战斗中对对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "blade" )
                return notify_fail("你使用的武器不对！\n");

        if ((int)me->query_skill("badao", 1) < 500)
                return notify_fail("你开天仙经火候不足，无法施展" XIAN "。\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("你基本内功修为不够，无法施展" XIAN "。\n");

        if( me->query("neili")<1000 )
                return notify_fail("你现在真气不够，无法施展" XIAN "！\n");
			
			        if( me->query("qi")<2000 )
                return notify_fail("你现在气血不够，无法施展" XIAN "！\n");

        if (me->query_skill_mapped("blade") != "badao")
                return notify_fail("你没有激发开天仙经，无法使用" XIAN "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -1000);
		me->add("qi", -2000);

        ap=me->query_skill("blade") *2/3 +me->query_skill("badao") *2/3 +me->query_skill("martial-cognize",1) *2/3 +me->query("str") *2/3;
        dp = target->query_skill("dodge") *1/3 + target->query_skill("force") *1/3 + target->query_skill("martial-cognize", 1) *1/3;

        message_combatd(HIW "\n$N" HIW "一声长叹，似乎看尽凡尘沧桑，事态万千，持刀而立，遥望天际 ……\n\n", me, target);

        // 第一刀
        msg = HIY "$N" HIY "踏步向前，施展出地狱三斩「凶魔」，" + weapon->name() + HIY
              "顺势劈过，狂风骤起，大地回归黑暗 ……\n" NOR;

        if (ap * 1 / 3 + random(ap) > dp)
        {
                damage = ap * 2/3 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,500+me->query("str")/2,
                                           HIR "$n" HIR "惊魂未定，竟然不知躲避，被$N"
                                           HIR "一刀劈过，刀气如体，口吐鲜血，接连后退。\n" NOR);
        }
        else
        {
                msg += CYN "$n" CYN "飞身一跃，滚在一边。\n" NOR;
        }

        // 第二刀
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，地狱三斩「炼狱」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 1 / 3 + random(ap) > dp)
        {
                damage = ap * 2/3 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,525+me->query("str")/2,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第三刀
        msg += HIY "\n$N" HIY "双眼一红，力量大增，猛然怒呵一声，飞天而起，但见天地又重归黑暗，似乎整个尘世已经"
              "坠入无间地狱般，令人再无半点生念，突然，四周充斥着鬼哭狼嚎的巨响，$N" HIY "却早已没了踪影。\n" NOR;
        if (ap * 1 / 3 + random(ap) > dp)
        {
                damage = ap * 2/3 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,550+me->query("str")/2,
                                           (: attack2, me, target, damage :));


        }
        else
        {
                msg += CYN "$n" CYN "收摄心神，小心应对，竟将此招化解与无形。\n" NOR;
        }

        me->start_busy(4 + random(4));
        message_combatd(sort_msg(msg), me, target);
        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "只觉心中一阵凄凉，胸口却已翻腾不息，说不出的难受。\n" NOR;

        target->add("neili", -5*damage/2);

        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "早已十魂失了八魄，正惊疑间，眼前一闪，刀气透体而过。\n" NOR;

        target->receive_wound("jing", damage / 5, me);
        if (random(4) == 1)target->start_busy(5 + random(5));

        return msg;
}