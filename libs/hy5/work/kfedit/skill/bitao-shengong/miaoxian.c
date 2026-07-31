// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
int lvl;
lvl=(int)me->query_skill("bitao-shengong",1);
        if ((!target))
                return notify_fail("你要用真气为谁使用妙仙决？\n");

        if( (int)me->query_skill("bitao-shengong",1) < 300 )
                return notify_fail("你的这门武功修为不够。\n");

        if( (int)me->query("max_neili") < 550 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 550)
                return notify_fail("你的真气不够。\n");

        if( userp(me) && me->query("family/family_name") != "白云庵")
                return notify_fail("此绝技只有白云庵门人体悟佛心才能使用。\n");

      //  if(userp(me) && !wizardp(me) && me==target)
       //         return notify_fail("不能对自己使用。\n");

        if(userp(me) && !wizardp(me) && !userp(target))
                return notify_fail("不能对非玩家使用。\n");

        if( target->query_condition("jinghuifu"))
                return notify_fail("对方正在被妙仙决回复。\n");

        if( me->query_condition("gong_busy"))
                return notify_fail("你才对人使用过妙仙决 你的真气还没有恢复。\n");

        if( (int)target->query("jing") >= (int)target->query("max_jing") )
                return notify_fail( target->name() +
                        "没有受伤，不需要你疗伤！\n");

        message_combatd(
                HIB "$N运起碧涛心法，将手掌贴在$n背心，一瞬间 将十二道真气输入$n体内....\n"
                "阿弥陀佛，妙哉！妙哉！ $N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
                me, target );

    target->receive_curing("qi", 500 + (int)me->query_skill("force")/2 );
    target->add("qi", 500 + (int)me->query_skill("force")/2 );
    target->receive_curing("jing", 500 + (int)me->query_skill("force")/2 );
    target->add("jing", 500 + (int)me->query_skill("force")/2 );
    target->set_temp("huifusl",(lvl+100));   
   lvl=lvl/50;
   if (lvl>10) lvl=10;
    target->apply_condition("jinghuifu",lvl);    
    me->apply_condition("gong_busy",3);
if (target==me) me->apply_condition("gong_busy",7);
    if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( userp(target) && (int)target->query("jing") > (int)target->query("eff_jing") ) target->set("jing", (int)target->query("eff_jing"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi") ) target->set("qi", (int)target->query("max_qi"));


me->add("neili", -250);
me->start_busy(2);
    return 1;
}

