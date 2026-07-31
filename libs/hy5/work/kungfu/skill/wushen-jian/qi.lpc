#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "奇剑诀" NOR; }

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
        int skill;
        int level;
                int i, attack_time;
                
        me = this_player();

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能在战斗中对对手使用。\n");

         if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
skill=(int)me->query_skill("wushen-jian", 1);
        if ((int)me->query_skill("wushen-jian", 1) < 160)
                return notify_fail("你逍遥五神剑法不够娴熟，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("sword") != "wushen-jian")
                return notify_fail("你没有激发逍遥五神剑法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force", 1) < 160)
                return notify_fail("你的内功火候不够，难以施展" + name() + "。\n");

        if (me->query("max_neili",1) < 1200)
                return notify_fail("你内力修为不足，难以施展" + name() + "。\n");

        if (me->query("neili",1) < 350)
                return notify_fail("你现在的真气不够，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIW "\n$N" HIW "将" + wn + HIW "斜指长空，猛地飞身跃起，"
              + wn + HIW "忽左忽右，飘忽不定，猛然间破空长响，" + wn + HIW
              "直指向$n" HIW "咽喉。\n这正是逍遥五神剑法之「" HIG "奇剑诀" HIW "」，"
              "当真是招招精奇，神妙无比。" NOR;

        //message_combatd(msg, me, target);

        ap = me->query_skill("sword",1) + me->query_skill("dodge");
        dp = target->query_skill("parry",1) + target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp || random(6)==0)
        {
                damage = me->query_skill("sword")+200;
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "\n$n" HIR "只见一道电光从半空袭来，"
                                          "心中惊骇不已，但鲜血已从$n胸口喷出。\n"
                                          NOR;
                me->start_busy(2);
                me->add("neili", -200);
        } else
        {
                msg = CYN "然而$n" CYN "眼明手快，侧身一跳"
                      "躲过$N" CYN "这一剑。\n" NOR;

                me->start_busy(2);
                me->add("neili", -200);
        }
        message_combatd(msg, me, target);
if (skill>200 && me && target)
{
 wn = weapon->name();

        msg = HIC "\n$n" HIC "陡然身法奇快，「" HIW "飞剑诀" HIC "」剑法灵动无比，手中" + wn + HIC "犹"
              "如脱手飞旋一般，将$N" HIC "周身笼罩。\n" NOR;

        //message_combatd(msg, me, target);

        level = me->query_skill("sword");


        ap = me->query_skill("sword",1);
        dp = target->query_skill("dodge",1);

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIY "\n$N" HIY "看不出$n" HIY "中招式中的虚实，连忙"
                      "护住自己全身，一时竟无以应对！\n" NOR;
if (!target->query_condition("zhua_poision")) target->apply_condition("zhua_poision",10);
                target->start_busy(5);
                me->start_busy(random(2));
        } else
        {
                msg = CYN "可是$N" CYN "镇定自若，小心拆招，没有被"
                      "$n" NOR + CYN "招式所困。\n" NOR;

                me->start_busy(2);
        }
        message_combatd(msg, target, me);
}

if (skill>300 && me && target)
{
 msg = HIW "\n$N" HIW "蓦的一声清啸，施出绝学「" HIM "快剑诀"
              HIW "」，手中" + weapon->name() + HIW "呼呼作响。霎时间"
              "奇妙的剑招连绵涌出。\n" NOR;

        attack_time = 4;

        ap = me->query_skill("sword",1);
        dp = target->query_skill("dodge",1);

        level = me->query_skill("wushen-jian", 1);
        attack_time += random(ap / 60);

        if (attack_time > 9)
                attack_time = 9;


	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 1000);
        message_combatd(msg, me, target);
me->set_temp("perform_wushenjian/qian", 1);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (! target->is_busy() && random(3) == 1)
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
me->delete_temp("perform_wushenjian/qian");        
	me->add_temp("apply/attack", -100);	
	me->add_temp("apply/damage", -1000);

}
        return 1;
}                                                                                                               