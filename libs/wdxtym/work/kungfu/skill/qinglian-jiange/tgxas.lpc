// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define RI "「" HIW "青莲剑阵" NOR "」"
string query_name() { return "青莲"ZJBR"剑阵"; }
int perform(object me)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;

        if (me->query("max_neili") < 2000)
                return notify_fail("你的内力的修为不够，现在无法使用" RI "。\n");

        if (me->query_skill("qinglian-jiange", 1) < 250)
                return notify_fail("你的青莲剑歌还不够娴熟，难以施展" RI "。\n");

        if ((int)me->query("neili") < 2000)
                return notify_fail("你的真气不够，无法运用" RI "。\n");

        msg = HIY "只见$N" HIY "双目微闭，单手执剑。周围空间破碎，"
              "时空泯灭，正是奥\n义「" NOR + HIW "青莲剑阵" NOR + HIY "」。霎时"
              "青光四射，尘沙四起，空气炽热，几欲沸腾。$N" HIY "\n随即横剑身前"
              "，一剑挥出，无数剑气覆盖整片空间，剑气足以撕碎虚无!\n\n" NOR;

        message_combatd(msg, me);

        me->add("neili", -2000);
        me->start_busy(6);

        ap = me->query_skill("sword") + me->query_con();

        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") + obs[i]->query_con();

                if (ap * 10 / 1 + random(ap) > dp)
                {
                        switch (random(2))
                        {
                        case 0:
                                tell_object(obs[i], HIR "你只觉眼前青光四射，周围空气几乎"
                                                    "凝固，剑气便如光矢一般透体而入。\n" NOR);
                                break;

                        default:
                                tell_object(obs[i], HIR "你只觉眼前青光万道，周围空空间几乎"
                                                    "破碎，剑气如万丈神光一齐扎入身体般。\n"
                                                    NOR);
                                break;
                        }

                        damage = me->query_skill("force");
                        damage = damage * 10 / 1;

                        obs[i]->receive_damage("qi", damage, me);
                        obs[i]->receive_wound("qi", damage, me);

                        obs[i]->receive_damage("jing", damage * 10 / 1, me);
                        obs[i]->receive_wound("jing", damage * 10 / 1, me);

                        p = (int)obs[i]->query("qi") * 10 / (int)obs[i]->query("max_qi");

                        switch (random(5))
                        {
                        case 0:
                                msg = HIR "只听" + obs[i]->name() +
                                      HIR "一声惨嚎，接连退了数步，“"
                                      "哇”的呕出一大口鲜血。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 1:
                                msg = HIR "只见" + obs[i]->name() +
                                      HIR "向后飞出丈远，重重的跌落在"
                                      "地上，衣衫破碎，再也没力气站起"
                                      "。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 2:
                                msg = HIR "只见" + obs[i]->name() +
                                      HIR "跌跌撞撞向后连退数步，伏倒"
                                      "在地。全身被剑气所伤"
                                      "。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        case 3:
                                msg = HIR "剑光闪过，" + obs[i]->name() +
                                      HIR "却是呆立当场，动也不动，七"
                                      "窍流血，神情扭曲，煞是恐怖。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;

                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "急忙抽身后退，可只见眼前剑"
                                      "芒暴涨，一闪而过。全身已多了数"
                                      "个伤口，鲜血飞溅。\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        if (! obs[i]->is_busy())
                        obs[i]->start_busy(1);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -1000);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIY "你只觉眼前出现无数剑影，周围空间几乎"
                                            "破碎，大惊之下连忙急运内功，抵御"
                                            "开来。\n" NOR);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

        if (! flag) 
                message_vision(HIY "只见剑影顿敛，却没有任何人被$N"
                               HIY "这招击中。\n\n" NOR, me, 0, obs);

        return 1;
}

