//by greenwc 2000.11
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
void snake_ok(object);
int perform(object me, object target)
{
	string msg;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「灵蛇」？\n");
                
        if(!me->is_fighting())
                return notify_fail("「灵蛇」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("你的飞雪映梅掌修为不够。\n");
         if((int)me->query_skill("hanshan-strike",1) < 150)
                return notify_fail("你的寒山掌法修为不够。\n");
         if((int)me->query_skill("doom-hand",1) < 150)
                return notify_fail("你的寒天神手修为不够。\n");                                
         if((int)me->query_skill("snowwhip",1) < 150)
                return notify_fail("你的寒雪鞭法修为不够。\n");   

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n"); 

        if((int)me->query_skill("snowwhip", 1) < 100)
                return notify_fail("你的寒雪鞭法不够熟练，使用这一招会有困难！\n");

          if(me->query_temp("no_snake"))
                        return notify_fail("看你大汗淋漓的样子，等会儿再用吧！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIC"\n$N手中鞭梢忽然抬起，如灵蛇之首嗫向$n\n"NOR,me,target);
me->set_temp("SS_perform", 7);  
        if (random(3)==0) target->start_busy(3);
               msg =  HIC  "第一鞭 寒星点点！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第二鞭 寒风起兮！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第三鞭 漫天飞雪！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第四鞭 雪花翩翩！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第五鞭 积雪三尺！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第六鞭 狂风骤雪！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                msg = HIC "第七鞭 风雪交加！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->delete_temp("SS_perform");
        me->receive_damage("jing", 50);
me->add("force", -50);

        me->add("neili", -390);
me->start_busy(3);
        me->set_temp("no_snake",1);
                call_out("snake_ok",1+random(2),me);

return 1;
}
void snake_ok(object me)
{ if (!me) return;
      me->delete_temp("no_snake");
}
