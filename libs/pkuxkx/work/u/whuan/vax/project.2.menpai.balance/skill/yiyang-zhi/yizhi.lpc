// yizhi.c  一阳指的特殊招式－一指定乾坤
// Made by ysg (1997.10.22)
// notme 2004/04/13
// 文件名中间有-导致verify显示不对，故改为这个名字
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int level, combatexp;
    string msg;

    level = me->query_skill("yiyang-zhi", 1);
    combatexp = me->query("combat_exp");

    if( !target ) target = offensive_target(me);
    if( target == me ) return notify_fail("怎么，你想自杀啊？\n");

    if( !target || !target->is_character() )
        return notify_fail("你要对谁使用一指定乾坤？\n");

    if( level < 100 ) return notify_fail("你的一阳指等级不够，还不能使出这招。\n");

    if( (int)me->query("max_neili") < 800 
            || (int)me->query("neili") < 500 )
        return notify_fail("你的内力不够，使不出这一招。\n");

    if ( target->query("luding_monster"))
    return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);
    msg = YEL"$N心里充满悲天怜人之念，从袖中缓缓伸出右手食指，对准$n的眉心志堂穴一摁。\n";
    //具有正神
    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    if( !me->is_fight(target) ) me->fight_ob(target);
    me->start_busy(1);
    if( (int)me->query("shen") > 5000 )
    {
        if( (int)(random(combatexp)*3/2 ) > (int)target->query("combat_exp")*10 )
        {
            msg += "结果$n只觉一股浩然正气将全身罩住，一时之间，只觉得慌慌忽忽，"
                +"动弹不得，内心恶念尽消，自动罢手不战了。\n"NOR;
            message_vision(msg, me, target);
            target->command("halt");
            target->set("bellicosity", 0);
            message_vision(YEL"$N全身一颤，脸上露出一种很奇怪的神色，突然“哇”的吐出一口鲜血。\n"NOR,target);
            target->remove_call_out("unconcious");
            target->set_temp("last_damage_from", me);
            target->unconcious();
        }
        else{
            msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
            message_vision(msg, me, target);			
			me->start_busy(5);
        }
    }else{
        msg += "但是$N自己慧根不净，强施一阳指，突然间心魔大盛，两眼中异芒闪动"
            +"，显然是无法控制自己的心智了。\n"NOR;
        message_vision(msg, me, target);
        me->add("bellicosity", 200);
        me->apply_condition( "qiankun-zhi", (int)( (5000-random( (int)me->query("shen") ) )/10) );
    }
    me->add("neili", -500);
    return 1;
}
