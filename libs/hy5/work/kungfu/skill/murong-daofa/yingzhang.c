#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me,object target)
{
     int d=me->query_skill("yanling-shenfa",1)/5;
        int j=me->query_skill("murong-daofa", 1)/5;
     int i=me->query_skill("xingyi-zhang", 1)/5;
	string msg;

        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("刀影掌只能对战斗中的对手使用。\n");                
       
        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用刀影掌！\n");        
        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("你手里没有刀，无法使用刀影掌！\n");
        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("你的掌法还未练成，不能使用刀影掌！\n");  
        if((int)me->query("neili") < 600 )
                return notify_fail("你现在内力不足，不能使用刀影掌！\n");      
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");
        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的基本掌法不够娴熟，不能在刀招中夹杂使用刀影掌。\n");     
        msg = YEL"\n$N大吼一声使出刀影掌，掌随刀走，刀光中夹杂着阵阵掌风一起奔向$n！"NOR;
       me->add("neili", -250); 
     me->add("jing", -100);
   me->add_temp("apply/dodge", d); 
me->add_temp("apply/damage", (i+j)); 
  me->add_temp("apply/attack", (i+j)/2); 
if (random(2)==0) target->start_busy(3);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        weapon->unequip(); 
     msg = YEL"$N弃刀换掌，身形飞转！\n"NOR;
	me->add_temp("apply/strike", i/2); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N弃掌换刀，身形飞转！\n"NOR;
me->add_temp("apply/strike", -i/2); 
        weapon->wield(); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ((int)me->query_skill("murong-daofa", 1)> 280)
{
if (random(2)==0) target->start_busy(3);
      msg = YEL"$N星移斗转，身形飞转！\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N作壁上观，身形飞转！\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N刀人合一，身形飞转！\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

me->add_temp("apply/damage", -(i+j)); 
  me->add_temp("apply/attack", -((i+j)/2)); 
   me->add_temp("apply/dodge", -d); 
        me->start_busy(2);
        return 1;
}
