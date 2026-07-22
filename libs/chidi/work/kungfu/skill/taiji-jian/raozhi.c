#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("sword")/ 5;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("「绕指柔剑」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("taiji-jian", 1) < 200 )
                return notify_fail("你的太极剑法功力太浅了。\n");
        if( (int)me->query_skill("sword", 1) < 200 )
                return notify_fail("你的基本剑法功力太浅了。\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 200 )
                return notify_fail("你的内功功力太浅了。\n");
        if( (int)me->query("max_neili") < 3000 )
                return notify_fail("你的内力太浅了。\n");
        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够。\n");
        if( me->query_temp("tjj/raozhi"))
                return notify_fail("你的已经正在用了。\n");

        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你用什么为内功基础来使「绕指柔剑」？\n");
        if (!objectp(weapon = me->query_temp("weapon")) ||        weapon->query("skill_type") != "sword" ||
            me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("你使得了「绕指柔剑」么?\n");
                 
        me->add("neili", -300-random(100));
        me->add_temp("apply/sword", i);
        me->add_temp("apply/damage", i);
        me->set_temp("tjj/raozhi",i);
me->start_busy(3);
        message_vision(HIR"$N施展出绕指柔剑，手中长剑竟成了一条软蛇，弯曲自如，攻势奇诡！\n"NOR, me);
        call_out("remove_effect", 1, me, i/5);
//        me->start_perform(999, "「绕指柔剑」");
        return 1;
}

void remove_effect(object me, int count)
{
        int i;
        if (!me) return;
        if(me->query_skill_mapped("sword") != "taiji-jian" 
           || !me->is_fighting()
           || !me->query_temp("weapon")
           || count < 1){
           i = me->query_temp("tjj/raozhi");
           me->add_temp("apply/sword", -i);
           me->add_temp("apply/damage", -i);
           me->delete_temp("tjj/raozhi");
//           me->start_perform(0);
           message_vision(HIR"$N收起内力，停止了绕指柔剑。\n"NOR, me);
           return;
        }
        call_out("remove_effect", 1 , me, count -1);
}


