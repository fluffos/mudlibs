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
        extra = me->query_skill("xianglong-zhang",1);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIC"神龙三叠"NOR"」只能对战斗中的对手使用。\n");

        if(objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")) )
              return notify_fail("你必须空手使用「"HIC"神龙三叠"NOR"」！\n");
     
        if( (int)me->query_skill("xianglong-zhang", 1) < 350 )
              return notify_fail("你的降龙十八掌不够娴熟，无法施展出「"HIC"神龙三叠"NOR"」。\n");
       
        if( me->query_skill_mapped("strike") != "xianglong-zhang" )
              return notify_fail("你所使用的并非降龙十八掌，不能施展「"HIC"神龙三叠"NOR"」！\n");

        if( me->query_skill_prepared("strike") != "xianglong-zhang" )
              return notify_fail("你所备的并非降龙十八掌，不能施展「"HIC"神龙三叠"NOR"」！\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
              return notify_fail("你所激发的内功并非混天气功，施展不出「"HIC"神龙三叠"NOR"」！\n");
           
        if(me->query("family/master_id") != "hong qigong")
              return notify_fail("「"HIC"神龙三叠"NOR"」是洪七公不传之密，你现在不是洪七公的徒弟，不能使用这一招！\n"NOR);

        if ( (int)me->query("max_neili") < 3000)
              return notify_fail("你的内力不够，无法施展出「"HIC"神龙三叠"NOR"」。\n");
        
        if ( (int)me->query("neili") < 1000)
              return notify_fail("你的真气不够，无法施展出「"HIC"神龙三叠"NOR"」。\n");
                  
        me->add("neili", -500);

        me->add_temp("apply/damage", extra/3);
        me->add_temp("apply/attack", extra/3);
        
        msg = YEL "$N一翻身跳出五丈外，双掌平平提到胸前，一式「亢龙有悔」飞扑向$n！" NOR;         
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               
        me->add_temp("apply/damage", -extra/3);
        me->add_temp("apply/attack", -extra/3);
        
        me->add_temp("apply/damage", extra/2);
        me->add_temp("apply/attack", extra/2);
        
        msg = HIR  "三丈左右，$N又使出一招「亢龙有悔」，与前一次掌风叠加，继续扑向$n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               
        me->add_temp("apply/damage", -extra/2);
        me->add_temp("apply/attack", -extra/2);
        
        me->add_temp("apply/damage", extra);
        me->add_temp("apply/attack", extra);
        
        msg = HIB  "距$n一丈，$N再复使出一招「亢龙有悔」，三道掌风叠加，海啸般推向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               
        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);
 
        me->start_busy(3);
        return 1;
}

