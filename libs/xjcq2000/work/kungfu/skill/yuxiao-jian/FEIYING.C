// feiying.c
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int lvl;

        lvl = me->query_skill("yuxiao-jian", 1);
        lvl += me->query_skill("tanzhi-shentong", 1);
        lvl += me->query_skill("luoying-zhang", 1);
        lvl += me->query_skill("lanhua-shou", 1);
        lvl += me->query_skill("xuanfeng-tui", 1);
        lvl += me->query_skill("suibo-zhuliu", 1);
        lvl /= 6;

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用飞影。\n");
        weapon = me->query_temp("weapon");
        if (!weapon || !(weapon->id("xiao")))
                return notify_fail("你手里的兵器不是箫。\n");
        if( (int)me->query_skill("yuxiao-jian", 1) < 150 )
                return notify_fail("你的玉箫剑法不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("qimen-bagua", 1) < 150 )
                return notify_fail("你的奇门八卦不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("tanzhi-shentong", 1) < 150 )
                return notify_fail("你的弹指神通不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("lanhua-shou", 1) < 150 )
                return notify_fail("你的兰花拂穴手不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 150 )
                return notify_fail("你的落英神剑掌不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("xuanfeng-tui", 1) < 150 )
                return notify_fail("你的旋风扫叶腿不够娴熟，无法施展出飞影。\n");
        if ((int)me->query_skill("bihai-chaosheng", 1) < 150)
                return notify_fail("你的碧海潮生功火候不够，无法施展出飞影。\n");
        if ((int)me->query_skill("suibo-zhuliu", 1) < 150)
                return notify_fail("你的随波逐流火候不够，无法施展出飞影。\n");
        if ( (int)me->query("max_neili") < 1500)
                return notify_fail("你的内力不够，无法施展出飞影。\n");
        if ( (int)me->query("neili") < 1000)
                return notify_fail("你的真气不够，无法施展出飞影。\n");
        if ((int)me->query("jingli") < 200)
                return notify_fail("你的精气不够，无法施展出飞影。\n");

        message_vision(HIW"$N吸一口气，使出桃花绝技「飞影」攻向$n！\n"NOR,me, target);

        me->add("neili", -(300 +random(100)) );
        me->add("jingli", -150);

        me->add_temp("apply/attack",lvl/20);
        me->add_temp("apply/damage",lvl/30);
        message_vision(HIG"$N手中的"+weapon->query("name")+HIG"如行云流水一般，向$n潇洒的攻去！\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        message_vision(HIG"$n只觉得四面八方都是剑影，不知所措！\n\n"NOR,me, target);
        weapon->unequip(); 
        me->prepare_skill("hand");
        me->prepare_skill("strike");
        me->prepare_skill("cuff");
        me->prepare_skill("finger");
        me->prepare_skill("leg");
        me->prepare_skill("claw");
        if (present(target,environment(me)) && me->is_fighting(target)){
         message_vision(HIC"$N把箫插回腰间，双手如清风拂晓向$n拂去！\n"NOR,me, target); 
         me->prepare_skill("hand","lanhua-shou");
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIC"$N正好拂到了$n的小腹关元穴！$n觉得真气无法重新凝聚！\n\n"NOR,me, target);
        }
        if (present(target,environment(me)) && me->is_fighting(target)){
         message_vision(HIM"$N倏地转手为掌，$n觉得到处是掌影，虚虚实实无法捉摸。\n"NOR,me, target);
         me->prepare_skill("hand");
         me->prepare_skill("strike","luoying-zhang");
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIM"$N突然打在$n後心至阳穴上，$n不由得吐了口鲜血。\n\n"NOR,me, target);
        }
        if (present(target,environment(me)) && me->is_fighting(target)){
         message_vision(HIR"$N尚未收掌，旋风扫叶腿已经攻到$n面前！\n"NOR,me, target);
         me->prepare_skill("strike");
         me->prepare_skill("leg","xuanfeng-tui");
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIR"$N连环出好几腿$n，连连後退，无暇出力！\n\n"NOR,me, target);
        }
        if (present(target,environment(me)) && me->is_fighting(target)){
         message_vision(HIY"$N收掌出指，连点$n身前大穴！\n"NOR,me, target);
         me->prepare_skill("leg");
         me->prepare_skill("finger","tanzhi-shentong");
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
         message_vision(HIY"$N突然一指向$n太阳穴戳去！$n摇摇晃晃，举布为艰。\n\n"NOR,me, target);
        }
        if( random(me->query("combat_exp", 1)) > target->query("combat_exp", 1)/2){
            target->add("neili",-150);         
            target->set("jiali",0);
            target->add("jingli",-100);
            target->receive_wound("qi",100);
            target->start_busy(3);
        }
        message_vision(HIW"\n$N飞影运使完毕，手一晃将箫拿回手中。\n"NOR,me, target);
        weapon->wield();
        me->start_busy(random(2) + 1);
        me->add_temp("apply/attack", -lvl/20);
        me->add_temp("apply/damage", -lvl/30);
        me->start_perform(6,"「飞影」");
        return 1;
}

