// 腐尸毒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
inherit YIZHAOYUN;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object co;

    if (environment(me)->query("no_fight")) return notify_fail("这里不能攻击别人! \n");

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「腐尸毒」只能在战斗中对对手使用。\n");

/*    if (objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
        return notify_fail("你必须空手才能使用「腐尸毒」！\n"); */

    if ((int)me->query_skill("xingxiu-duzhang", 1) < 220)
        return notify_fail("你的星宿毒掌还不够娴熟，使不出「腐尸毒」绝技。\n");

    if ((int)me->query_skill("huagong-dafa", 1) < 120)
        return notify_fail("你的化功大法修为不够，不能使用「腐尸毒」。\n");

    if ((int)me->query_skill("poison", 1) < 120)
        return notify_fail("你积毒不够无法使用腐尸毒。\n");

    co = present("corpse", me);
    if (!co || !co->is_corpse())
    {
        co = present("corpse", environment(me));
        if ( !co || !co->is_corpse() ) 
            return notify_fail("你周围没有尸体，如何使用腐尸毒!\n");
    }
    // 腐烂的时间太快了，暂时屏蔽这个判断
    //if( strsrch(co->query("name"), "腐烂的") < 0 )
    //return notify_fail("尸体没有腐烂，无法使用腐尸毒。\n");
/*    if (me->query_skill_prepared("strike") != "xingxiu-duzhang"
        || me->query_skill_mapped("strike") != "xingxiu-duzhang"
        || me->query_skill_mapped("parry") != "xingxiu-duzhang")
        return notify_fail("你现在无法使用「腐尸毒」！\n"); */

    if ((int)me->query("max_neili") < 1200)
        return notify_fail("你内力太弱，使不出「腐尸毒」。\n");

    if ((int)me->query("neili") < 300)
        return notify_fail("你现在真气太弱，使不出「腐尸毒」。\n");

    message_vision(BLU"\n$N一声阴笑，右手突出，挟起一具尸体掷出，一股死鱼烂肉的臭气弥漫四周，闻者欲呕！\n"NOR, me);

    call_out("destroying", 1, co);

    if (!target->is_killing(me->query("id")))
        target->kill_ob(me);

    me->add("neili", -250);
//命中率级别是B-&&B-=E级
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 6, me, target) &&
        F_KUNGFU->hit_rate(me->query_skill("strike", "xingxiu-duzhang"), target->query_skill("dodge"), 6, me, target))
    {
        message_vision(HIB"\n$n见此怪异的招数，手足无措，躲闪无及，只见散发着恶臭的尸体，正击在自己身上。\n"NOR, me, target);
        //target->set_temp("last_damage_from", "腐尸毒入脑");
        //target->set_temp("death_cond_origin/fs_poison", me);
		F_POISON->poison_attack(me,target,"fs_poison",  random(3) + (me->query_skill("poison", 1) / 10) + target->query_condition("fs_poison"));
        target->receive_damage("qi", 0, me);
        if (random(5))
            // target->unconcious();
            yizhaoyun(target, me);
        else
            target->die();
        me->start_busy(3);
        return 1;
    }
//命中率级别是B+&&A-=C+级别
    else if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 4, me, target) &&
             F_KUNGFU->hit_rate(me->query_skill("strike", "xingxiu-duzhang"), target->query_skill("dodge"), 3, me, target))
    {
        message_vision(HIB"\n$n见事不好，连忙纵身直起，腐尸从身下掠过，没有打中。\n"NOR, me, target);
        tell_object(target, HIB"\n你虽然及时避开了毒尸，但一股腥臭气入鼻，你已中了剧毒了。\n"NOR);
        //target->set_temp("death_cond_origin/fs_poison", me);
		F_POISON->poison_attack(me,target,"fs_poison", random(3) + (me->query_skill("poison", 1) / 10) +
                                target->query_condition("fs_poison"));
        me->start_busy(2);
        if (!target->is_busy())
            target->start_busy(3);
        return 1;
    }
    message_vision(HIB"\n$n胸有成竹，一声长啸，双掌连环劈出，把毒尸毒气荡向来路。\n"NOR, me, target);
    tell_object(me, HIB"\n不好，毒尸反弹向你,你虽然躲开，但毒气也侵入你的身体。\n"NOR);
    //me->set_temp("death_cond_origin/fs_poison", target);
	F_POISON->poison_attack(target,me,"fs_poison", random(3) + (me->query_skill("poison", 1) / 10) +
                        me->query_condition("fs_poison"));
    return 1;
}

void destroying(object obj) 
{ 
    if (obj) destruct(obj); 
}

