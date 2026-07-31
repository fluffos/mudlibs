// feiying.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon,obj;
        int lvl,dmg;

        lvl = (me->query_skill("yuxiao-jian", 1)+me->query_skill("tanzhi-shentong", 1)+me->query_skill("luoying-zhang", 1)+me->query_skill("lanhua-shou", 1)+me->query_skill("xuanfeng-tui", 1))/5;
        lvl = lvl + me->query_skill("anying-fuxiang", 1);

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用飞影。\n");
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

  
	//if (!objectp(obj=present("yuxiao", me))
	//&& userp(me))
         //   return notify_fail("你身上没有玉萧。\n");

        if( (int)me->query_skill("yuxiao-jian", 1) < 180 )
                return notify_fail("你的玉箫剑法不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("qimen-wuxing", 1) < 180 )
                return notify_fail("你的奇门八卦不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("tanzhi-shentong", 1) < 180 )
                return notify_fail("你的弹指神通不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("lanhua-shou", 1) < 180 )
                return notify_fail("你的兰花拂穴手不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 180 )
                return notify_fail("你的落英神剑掌不够娴熟，无法施展出飞影。\n");
        if( (int)me->query_skill("xuanfeng-leg", 1) < 180 )
                return notify_fail("你的旋风扫叶腿不够娴熟，无法施展出飞影。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 200)
                return notify_fail("你的碧波神功生功火候不够，无法施展出飞影。\n");
        if ((int)me->query_skill("anying-fuxiang", 1) < 200)
                return notify_fail("你的暗影浮香火候不够，无法施展出飞影。\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，无法施展出飞影。\n");
        if ( (int)me->query("neili") < 500)
                return notify_fail("你的真气不够，无法施展出飞影。\n");

//        me->start_perform(2, "飞影");
        message_vision(HIW"$N吸一口气，使出桃花绝技「飞影」攻向$n！\n"NOR,me, target);
        me->add("neili", -(400 +random(100)) );
	if (lvl>2000) lvl=2000;
	me->add_temp("apply/attack", lvl/10);	
	me->add_temp("apply/damage", 500);
        me->add_temp("apply/dexerity",lvl/10);
        me->add_temp("apply/strength",lvl/20);
        me->start_busy(1);
        message_vision(HIG"$N手中的箫如行云流水一般，向$n潇洒的攻去！\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3)
{
        message_vision(HIG"$n觉得四面八方都是剑影，不知所措！\n\n"NOR,me, target);
        if (!target->is_busy())
        target->start_busy(2);
}
        weapon->unequip(); 
        me->prepare_skill("hand");
        me->prepare_skill("strike");
        me->prepare_skill("cuff");
        me->prepare_skill("finger");
        me->prepare_skill("leg");
        me->prepare_skill("claw");
        message_vision(HIC"$N把箫插回腰间，双手如清风拂晓向$n拂去！\n"NOR,me, target);
        me->prepare_skill("hand", "lanhua-shou");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        message_vision(HIC"$N正好拂到了$n的小腹关元穴！$n觉得真气无法重新凝聚！\n\n"NOR,me, target);
        target->add("neili",-(target->query("neili")/5));
     message_vision(HIM"$N倏地转手为掌，$n觉得到处是掌影，虚虚实实无法捉摸。\n"NOR,me, target);
        me->prepare_skill("hand");
        me->prepare_skill("strike","luoying-zhang");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
     message_vision(HIM"$N突然打在$n後心至阳穴上，$n不由得吐了口鲜血。\n\n"NOR,me, target);
        target->receive_wound("qi",100,me);

        message_vision(HIR"$N尚未收掌，旋风扫叶腿已经攻到$n面前！\n"NOR,me, target);
        me->prepare_skill("strike");
        me->prepare_skill("leg","xuanfeng-leg");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        message_vision(HIR"$N连环出好几腿$n，连连後退，无暇出力！\n\n"NOR,me, target);

        target->set("jiali",0);

        message_vision(HIY"$N收掌出指，连点$n身前大穴！\n"NOR,me, target);
        me->prepare_skill("leg");
        me->prepare_skill("finger","tanzhi-shentong");
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
       message_vision(HIY"$N突然一指向$n太阳穴戳去！$n摇摇晃晃，举步为艰。\n\n"NOR,me, target);
        dmg=target->query("jing",1)/5;
        if (dmg>40000) dmg=40000;
        target->add("jing",-dmg);

        message_vision(HIW"$N飞影运使完毕，手一晃将箫拿回手中。\n"NOR,me, target);
        weapon->wield();
        me->start_busy(2);
	me->add_temp("apply/attack", -lvl/10);	
	me->add_temp("apply/damage", -500);
        me->add_temp("apply/dexerity",-lvl/10);
        me->add_temp("apply/strength",-lvl/20);
        return 1;
}

