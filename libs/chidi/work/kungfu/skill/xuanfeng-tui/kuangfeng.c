// kuangfeng.c  狂风绝技

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object ob;
        string msg;
 
        if( !me->is_fighting() )
                return notify_fail("「狂风绝技」只能在战斗中使用。\n");
 
        if (me->query_temp("weapon") )
                return notify_fail("「狂风绝技」开始时不能拿着兵器！\n");

        if( (int)me->query("neili") < 100 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("bibo-shengong",1) < 80 )
                return notify_fail("你的碧波神功不够！\n");

        if( (int)me->query_skill("luoying-zhang",1) < 100 ||
            me->query_skill("xuanfeng-tui",1) < 100)
                return notify_fail("你的腿掌功夫还不到家，无法使用狂风绝技！\n");

        msg = HIY "$N使出桃花岛绝技「狂风绝技」，身法陡然加快！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("neili", -100);
        me->start_busy(2);

        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}

