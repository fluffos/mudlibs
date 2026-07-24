#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string wn, msg;
        int i = me->query_skill("sword")/ 5;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        ||  !living(target))
                return notify_fail("「绕指柔剑」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("raozhi-roujian", 1) < 200 )
                return notify_fail("你的太极剑法功力太浅了。\n");
        if(me->query_temp("tjj/raozhi"))
                return notify_fail("你正在使用「绕指柔剑」。\n");

        if( (int)me->query_skill("sword", 1) < 200 )
                return notify_fail("你的基本剑法功力太浅了。\n");
        if( (int)me->query_skill("taiji-shengong", 1) < 180 )
                return notify_fail("你的本门内功功力太浅了。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够。\n");
        if (!objectp(weapon = me->query_temp("weapon")) ||        weapon->query("skill_type") != "sword" ||
            me->query_skill_mapped("sword") != "raozhi-roujian")
                return notify_fail("你使得了「绕指柔剑」么?\n");
                 
        me->add("neili", -300-random(100));
        me->add_temp("apply/sword", i);
        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 300);
        me->set_temp("tjj/raozhi",i);
        message_vision(HIR"$N施展出绕指柔剑，手中长剑竟成了一条软蛇，弯曲自如，攻势奇诡！\n"NOR, me);
         msg = HIG "$N逆转剑锋，从右弯剌出一剑！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         msg = HIY "$N逆转剑锋，从左弯剌出一剑！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         msg = HIR "$N逆转剑锋，最后弯剌出一剑！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        call_out("remove_effect", 1, me, i/5);
        return 1;
}

void remove_effect(object me, int count)
{
        int i;
        if (!me) return;
        if(me->query_skill_mapped("sword") != "raozhi-roujian" 
           || !me->is_fighting()
           || !me->query_temp("weapon")
           || count < 1){
           i = me->query_temp("tjj/raozhi");
           me->add_temp("apply/sword", -i);
        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -300);
           me->delete_temp("tjj/raozhi");
           message_vision(HIR"$N收起内力，停止了绕指柔剑。\n"NOR, me);
           return;
        }
        call_out("remove_effect", 1 , me, count -1);
}


