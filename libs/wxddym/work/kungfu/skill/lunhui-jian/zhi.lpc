#include <ansi.h> 

#define CHAN "「" HIR "神剑指穴" NOR "」" 
string query_name() { return "神剑"ZJBR"指穴"; }
inherit F_SSERVER; 

int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 

        if( userp(me) && !me->query("can_perform/lunhui-jian/zhi") )
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target) 
        { 
                me->clean_up_enemy(); 
                target = me->select_opponent(); 
        }

        if (! target || ! me->is_fighting(target)) 
                return notify_fail(CHAN "只能对战斗中的对手使用。\n"); 

        if( !objectp(weapon=me->query_temp("weapon")) || 
            weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对，难以施展" CHAN "。\n"); 

        if (target->is_busy()) 
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n"); 

        if ((int)me->query_skill("force") < 180) 
                return notify_fail("你的内功火候不够，难以施展" CHAN "。\n"); 

        if ((int)me->query_skill("lunhui-jian", 1) < 120) 
                return notify_fail("你的释迦轮回剑还不到家，难以施展" CHAN "。\n"); 

        if (me->query_skill_mapped("sword") != "lunhui-jian") 
                return notify_fail("你没有激发释迦轮回剑，难以施展" CHAN "。\n"); 

        if( me->query("neili")<100 )
                return notify_fail("你的真气不够，难以施展" CHAN "。\n"); 

        if (! living(target)) 
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n"); 

        msg = HIY "$N" HIY "内息澎湃，手中" + weapon->name() + HIY "遥遥指向$n，" 
              "一股劲气自"+ weapon->name() + HIY "上激射而出，直指向$n的周身大穴。\n" NOR; 
        
        if (random(me->query_skill("sword")) > target->query_skill("parry") / 2) 
        {
                msg += HIR "$n" HIR "稍不留神，身上几处要穴已被内力透过"
                       "，一时间无法动弹。\n" NOR; 
                target->start_busy((int)me->query_skill("lunhui-jian") / 20 + 1); 
                me->add("neili", -60);
                me->start_busy(1); 
        } else 
        {
                msg += CYN "可是$n" CYN "小心应对，丝毫不乱，纵身" 
                       "跃出了$N" CYN "纵横剑气的包围。\n" NOR; 
                me->add("neili", -30);
                me->start_busy(2); 
        }
        message_combatd(msg, me, target); 

        return 1; 
}
