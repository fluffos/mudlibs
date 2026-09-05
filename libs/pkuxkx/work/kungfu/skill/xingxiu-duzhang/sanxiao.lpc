#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object obj;
    string msg;
    int ap, dp;

    if (environment(me)->query("no_fight"))
        return notify_fail("这里不能攻击别人! \n");

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("三笑逍遥散只能在战斗中使用。\n");

    if ((int)me->query_skill("huagong-dafa", 1) < 100)
        return notify_fail("你的化功大法不够娴熟，不能施毒。\n");

    if ((int)me->query_skill("xingxiu-duzhang", 1) < 100)
        return notify_fail("你星宿毒掌不够娴熟，不能施毒。\n");

    if (!(objectp(obj = present("sanxiaoxiaoyao san", me))))
        return notify_fail("你身上没有三笑逍遥散。\n");

    msg = HIM "$N诡异的一笑，右手虚晃一招，突然间从左手上弹出一阵红色的烟雾射向$n。\n" NOR;
    message_vision(msg, me, target);

    if (target->query_skill("medical-skill", 1) > 70)
    {
        message_vision("$N怒道：臭贼竟敢用毒！看我怎么收拾你！\n", target);
        target->kill_ob(me);
    }

    ap = me->query_skill("force", "huagong-dafa") * 5 + me->query_skill("strike", "xingxiu-duzhang") * 9;
    dp = target->query_skill("force") + target->query_skill("dodge") + target->query_kar();
    if (!F_KUNGFU->hit_rate(ap + dp, 2 * dp, 9, me, target))
    {
        if ((int)(target->query("eff_qi") / target->query("max_qi")) < 1)
        {
            message_vision(CYN"$N觉得内息有些受阻，脸上的肌肉抽动了一下，过后感觉有恢复正常，所以也没有太在意。\n"NOR, target);
            me->start_busy(random(2));
            destruct(obj);
            //me->start_call_out( (: call_other, __FILE__, "sanxiao", me, target :), 3);
            me->start_call_out(__FILE__, "sanxiao", 3, me, target);
            return 1;
        }
        if ((int)(target->query("qi") / target->query("max_qi")) < 1)
        {
            F_KUNGFU->hit_wound("qi", (int)me->query_skill("xingxiu-duzhang", 1), 0, me, target);
            target->receive_wound("jing", 10, me);
            //target->set_temp("death_cond_origin/sanxiao_poison", me);
            target->apply_condition("sanxiao_poison",
                                    random(me->query_skill("xingxiu-duzhang", 1) / 3) + 1 + target->query_condition("sanxiao_poison"));
            if (!target->is_busy())
                target->start_busy(3 + random(2));
            me->start_busy(random(3));
            message_vision(HIR"$N只觉得呼吸困难，四肢无力，突然间口里一甜，竟呕出一大口鲜血来。\n"NOR, target);
            COMBAT_D->report_status(target);
        }
    }
    else
    {
        message_vision("$n识破了$N的企图，提前跃到一旁，反身向$N攻来。\n", me, target);
        me->start_busy(3);
    }

    if (!target->is_killing(me->query("id")))
        target->kill_ob(me);
    destruct(obj);
    return 1;
}

void sanxiao(object me, object target)
{
    int qi;

    if (!target || !living(target) || !me)
        return;

    message_vision("$N的脸上突然浮现出一丝诡异的笑容，连他自己也没有觉察出来。\n", target);
    message_vision("紧接着$N觉得四肢冰凉，全身不听使唤，嘴里一甜，竟呕出一大口鲜血来。\n", target);
    message_vision("$N这才恍然大悟：原来你用毒！\n", target);

    if (!target->is_killing(me->query("id")))
        target->kill_ob(me);
    qi = target->query("max_qi");
    qi = qi / 8;
    if (target->query("qi") < qi)
    {
        target->receive_damage("qi", 0, me);
        target->unconcious();
    }
    else
    {
        F_KUNGFU->hit_wound("qi", qi, 0, me, target);
        target->receive_wound("jing", 100, me);
        COMBAT_D->report_status(target); 
        //target->set_temp("death_cond_origin/sanxiao_poison", me);
        target->apply_condition("sanxiao_poison",
                                random(me->query_skill("xingxiu-duzhang", 1) / 3) + 1 + target->query_condition("sanxiao_poison"));
        if (!target->is_busy())
            target->start_busy(2 + random(2));
    }
}

