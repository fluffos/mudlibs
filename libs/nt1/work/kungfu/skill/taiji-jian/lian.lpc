// lian.c 连字诀

#include <ansi.h>

#define PFM_NAME        "连字诀"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
        int time;
        int count;
        int skill;

        if (userp(me) && ! me->query("can_perform/taiji-jian/lian"))
                return notify_fail("你还没有受过高人指点，无法施展「" PFM_NAME "」。\n");
                        
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「" + PFM_NAME + "」只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("必须拿剑才能施展「" + PFM_NAME + "」。\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("你的真气不够，无法施展「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的太极神功火候不够，难以施展「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("taiji-jian", 1) < 200)
                return notify_fail("你的太极剑还不到家，无法使用「" + PFM_NAME + "」。\n");

        time = me->query_skill("taiji-jian") / 20;
        if (time > 10) time = 10;
        if (time < 1) time = 1;

        msg = HIC "$N" HIC "一声长啸，灵台清明，凝神归元，使出太极剑中的「" + PFM_NAME + "」。\n"
              HIY "手中" + weapon->name() + HIY "招式陡然变得凌厉无比，一转念"
              HIY "间已然攻出" + chinese_number(time) + "招！\n" NOR;

        message_combatd(msg, me, target);
        skill = me->query_skill("taiji-jian", 1) / 5;
        me->add("apply/attack", skill);
        me->add("neili", -(time * 100));

        for (i = 0; i < (time); i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add("apply/attack", -skill);
        me->start_busy(time / 2 + random(time / 2));
        return 1;
}

