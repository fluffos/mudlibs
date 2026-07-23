 // silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int step,fist,extra;
        object weapon;
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［掌腿双飞］只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
        
        step = me->query_skill("bingxue-xinfa",1);
        fist = me->query_skill("doom-hand",1);



         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("你的飞雪映梅掌修为不够。\n");

         if((int)me->query_skill("doom-hand",1) < 50)
                return notify_fail("你的这门武功修为不够。\n");
        
        if (step< 100) return notify_fail("你的［寒天神手］不够熟练。\n");
        if (fist< 100) return notify_fail("你的［冰雪心法］不够熟练。\n");
        
        //if (me->query("class")=="fighter") {
                fist= fist*3/2;
                step=step*3/2;
        //}       
        if (fist>=300)  fist=300;
        if (step>=300)  fist=300;	
                
        me->add_temp("apply/attack", fist);     
        me->add_temp("apply/damage", fist*2);
        msg = HIR  "$N使出［九重寒天掌］，全身飞速旋转，双掌一前一后，闪电般的击向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -fist);
        me->add_temp("apply/damage", -fist*2);
        
        me->add_temp("apply/attack", step);     
        me->add_temp("apply/damage",step*2);
if (random(3)==0) target->start_busy(3);

        msg = HIC  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个侧身，迅捷无比地向$n踢出灭天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个转身，迅捷无比地向$n踢出穿天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "$N猛一个跃身，迅捷无比地向$n踢出毁天一腿！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", -step);
        me->add_temp("apply/damage",-step*2);
        me->add("neili", -300);
me->start_busy(3);
        return 1;
}
