// shuangjue.c  拳腿双绝

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("chanyun-tui",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("拳腿双绝只能对战斗中的对手使用。\n");

               if( objectp(me->query_temp("weapon")) )
               return notify_fail("你必须空手使用「拳腿双绝」！\n");

        if (me->query_skill_mapped("unarmed") != "chuanyun-tui")
                return notify_fail("你现在无法使用「拳腿双绝」进行攻击.\n");                                                                                 

        if (me->query_skill_mapped("cuff") != "zhentian-quan")
                return notify_fail("你现在无法使用「拳腿双绝」进行攻击！\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("你的震天拳不够娴熟，无法施展出拳腿双绝。\n");
        
        if( (int)me->query_skill("chuanyun-tui", 1) < 150 )
                return notify_fail("你的穿云腿不够娴熟，无法施展出拳腿双绝。\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("你的内力不够，无法施展出拳腿双绝。\n");
        if ( (int)me->query("neili") < 1000)
                return notify_fail("你的真气不够，无法施展出拳腿双绝。\n");
	                 me->add_temp("apply/damage", extra);
                 me->add_temp("apply/attack", extra);

		 msg = RED "$N一声清啸，拳脚齐施，使出昆仑绝学「拳腿双绝」迅捷无伦地攻向$n！\n" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "左一拳！\n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "右一腿！\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "上一拳！\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "下一腿！\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "中间再是一拳！\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);
      me->add("neili",-200);
        me->start_busy(2);
        return 1;
}
