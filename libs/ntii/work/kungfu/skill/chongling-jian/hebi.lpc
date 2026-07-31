// chongling-jian perform hebi 双剑合璧

#include <ansi.h>
#define ME  "你现在不能使用双剑合璧。\n"
#define TAR  "对方现在不能使用双剑合璧。\n"

int check_fight(object me, object target, int amount);
private int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
        object *enemy;
        int i, j, amount;
        object wep1, wep2;
        wep1 = me->query_temp("weapon");

        if (! target || target == me) return notify_fail("你要和谁双剑合璧？\n");

        if (me->query_temp("hebi")) return notify_fail(ME);
        if (target->query_temp("hebi")) return notify_fail(TAR);
        if (me->query("jing") < 200) return notify_fail(ME);
        if (target->query("jing") < 200) return notify_fail(TAR);
        if (me->query("neili") < 1000) return notify_fail(ME);
        if (target->query("neili") < 1000) return notify_fail(TAR);
        if (! me->is_fighting()) return notify_fail("双剑合璧只能在战斗中使用。\n");
        if (me->is_fighting(target)) return notify_fail("你正在和对方打架，使用双剑合璧干什么？\n");

        if ((int)me->query_skill("liangyi-dao", 1) < 140)
                return notify_fail(ME);
        if ((int)me->query_skill("zixia-shengong", 1) < 140)
                return notify_fail(ME);
        if (! wep1 || wep1->query("skill_type") != "sword"
        ||  me->query_skill_mapped("sword") != "chongling-jian")
                return notify_fail(ME);
        
        enemy = me->query_enemy();
        i = sizeof(enemy);
        while (i--) if (target->is_fighting(enemy[i])) break;
        if (i < 0) return notify_fail(target->name() + "并没有和你的对手在交战。\n");

        if ((int)target->query_skill("chongling-jian", 1) < 140)
                return notify_fail(TAR);
        if ((int)target->query_skill("zixia-shengong", 1) < 140)
                return notify_fail(TAR);
                
        wep2 = target->query_temp("weapon");
        if (target->is_busy() || ! wep2 || wep2->query("skill_type") != "sword"
        ||  target->query_skill_mapped("sword") != "chongling-jian")
                return notify_fail(TAR);
       
        message_combatd(HIY "\n$N反手舞了个剑花，$n登时会意，两人同时从两侧欺上，威力顿时陡增。\n" NOR, me, target);
        me->set_temp("hebi", 1);
        target->set_temp("hebi", 1);
        me->receive_damage("jing", 100);
        target->receive_damage("jing", 100);
        me->receive_damage("neili", 300);
        target->receive_damage("neili", 300);
        me->start_busy(1);
        target->start_busy(1);
        
        i = (int)me->query_skill("chongling-jian", 1);
        j = (int)target->query_skill("chongling-jian", 1);
        amount = (i + j) / 10;
        
        me->add_temp("apply/dex", amount);
        me->add_temp("apply/str", amount);
        target->add_temp("apply/dex", amount);
        target->add_temp("apply/str", amount);
        
        if (me->query("couple/id") == target->query("id"))
        {
                message_combatd(HIY "\n$N和$n各自会意，$n一个侧身，$N手中$w" + HIY "迅捷无比地刺上一剑。\n" NOR, me, target);
                COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
                target->start_busy(random(6));
        }
        check_fight(me, target, amount);

        return 1;
}

int check_fight(object me, object target, int amount)
{  
        object wep1, wep2;
        if (! me) return 0;
        if (! target) return 0;
        wep1 = me->query_temp("weapon");
        wep2 = target->query_temp("weapon");
        if (! me->is_fighting() || ! living(me) || me->is_ghost() || ! wep1 || 
            ! target->is_fighting() || ! living(target) || target->is_ghost() || ! wep2)
                remove_effect(me, target, amount);
        else {
                call_out("check_fight", 1, me, target, amount);
        }
        return 1;
}

private int remove_effect(object me, object target, int amount)
{
        if (living(me) && ! me->is_ghost() && living(target) && ! target->is_ghost())
        message_combatd(HIY "\n$N和$n双剑合璧用完，灵犀互通，相视一笑，各自收招。\n" NOR, me, target);

        me->add_temp("apply/dex", -amount);
        me->add_temp("apply/str", -amount);
        target->add_temp("apply/dex", -amount);
        target->add_temp("apply/str", -amount);
        me->delete_temp("hebi");
        target->delete_temp("hebi");
        return 0;
}

