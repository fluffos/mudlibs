#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIR "无垠六斩" NOR "」"
string query_name() { return "无垠"ZJBR"六斩"; }
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

        if ((int)me->query_skill("taiyan-dijing", 1) < 200)
                return notify_fail("你太衍帝经火候不足，无法施展" XIAN "。\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("你基本内功修为不够，无法施展" XIAN "。\n");

        if ((int)me->query_skill("blade", 1) < 600)
                return notify_fail("你的基础刀法还修炼不到家，无法施展" XIAN "！\n");

        if( me->query("neili")<3000 )
                return notify_fail("你现在真气不够，无法施展" XIAN "！\n");

        if (me->query_skill_mapped("blade") != "taiyan-dijing")
                return notify_fail("你没有激发太衍帝经，无法使用" XIAN "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -3000);

        ap=me->query_skill("blade")+me->query_skill("tanyan-dijing")+me->query_skill("martial-cognize",1)+me->query("str");
        dp = target->query_skill("dodge") + target->query_skill("force") + target->query_skill("martial-cognize", 1);

        message_combatd(HIW "\n$N" HIW "一声长叹，似乎看尽凡尘沧桑，事态万千，持刀而立，遥望天际 ……\n\n", me, target);

        // 第一刀
        msg = HIY "$N" HIY "踏步向前，施展出无垠六斩「一斩」，" + weapon->name() + HIY
              "顺势劈过，狂风骤起，大地回归黑暗 ……\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 1/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,50+me->query("str")/6,
                                           HIR "$n" HIR "惊魂未定，竟然不知躲避，被$N"
                                           HIR "一刀劈过，刀气如体，口吐鲜血，接连后退。\n" NOR);
        }
        else
        {
                msg += CYN "$n" CYN "飞身一跃，滚在一边。\n" NOR;
        }

        // 第二刀
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，无垠六斩「二斩」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 2/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,55+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第三刀
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，无垠六斩「三斩」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 3/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,60+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第四刀
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，无垠六斩「四斩」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 4/5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,65+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第五刀
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，无垠六斩「五斩」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 3 / 2 + random(ap) > dp)
        {
                damage = ap * 5/6 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,70+me->query("str")/6,
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第六刀
        msg += HIY "\n$N" HIY "双眼一红，力量大增，猛然怒呵一声，手臂一挥，无垠六斩「六斩」已然使出，但见天地又重归黑暗，似乎整个尘世已经"
              "坠入无间地狱般，令人再无半点生念，突然，四周充斥着鬼哭狼嚎的巨响，$N" HIY "却早已没了踪影。\n" NOR;
        if (ap * 5 / 1 + random(ap) > dp)
        {
                damage = ap * 6/7 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,75+me->query("str")/6,
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

        target->add("neili", -3*damage/2);
        target->add("qi", -3*damage/2);
        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "早已十魂失了八魄，正惊疑间，眼前一闪，刀气透体而过。\n" NOR;

        target->receive_wound("jing", damage * 5 / 3, me);
        if (random(4) == 1)target->start_busy(5 + random(5));

        return msg;
}