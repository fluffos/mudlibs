
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage,extra, attp, defp;
        string msg,str; 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「暴雪天威」？\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "panshi-shengong")
                return notify_fail("请使用磐石神功!\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("你的磐石神功还不够。。。\n"); 
                
		
        if(!me->is_fighting())
                return notify_fail("「暴雪天威」只能在战斗中使用！\n");
        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("jing") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("aohan-liujue", 1) < 100)
                return notify_fail("你的这门刀法级别还不够，使用这一招会有困难！\n");

        message_combatd(HIW"\n$N运起寒气，身形一转，四周顿时冰冻数尺，空气中寒气逼人，$n只冻的忘记的抵抗！\n"NOR,me,target,"");
        me->set_temp("noauto",1);
        target->start_busy(1);
        damage=100+random(((int)me->query_skill("blade",1)))+(int)me->query_skill("aohan-liujue",1);

        message_combatd(HIW"\n$N嘿嘿一声冷笑，竟然隐入雪花之中。$n大急，四下找寻$N，忽然背后一阵寒气随着\n"NOR,me,target,"");
        message_combatd(HIW"\n刀光狂袭过来！！！\n"NOR,me,target,"");
        
        extra=(int)me->query_skill("aohan-liujue", 1)/2;
        if (extra> 200) extra=200;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra); 
                
        msg=HIY"飘雪式---$N手中$n"HIY"顺着雪势使出一招！\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIC"排雪式---$N手中$n"HIC"犹如扑风追影反撩！\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIB"劈雪式---$N手中$n"HIB"夹着翩翩刀光猛劈！\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
                
        if(random(me->query("combat_exp"))>random(target->query("combat_exp"))/4)
        {
                message_combatd(HIY"\n打斗中,一只金色大鹏鸟远远飞来！$N和$n都看呆了！\n"NOR,me,target,"");
                message_combatd(HIY"\n突然大鹏鸟用翅膀一扇,顿时狂风大作！\n"NOR,me,target,"");
                if(random(me->query("jiali"))>target->query("jiali")/4)
                {
                        message_combatd(HIR"\n$N见机不可失,连忙攻出一招！\n"NOR,me,target,"");
                        target->receive_damage("qi",damage*2); 
                        target->receive_damage("jing",damage/2); 
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage/2);
                        COMBAT_D->report_status(target);

                }  
                else 
                if(random(me->query("jiali"))>target->query("jiali")/2)
                {
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$n砸得遍体鳞伤！\n"NOR,me,target,"");
                        target->receive_wound("qi",damage);
                        COMBAT_D->report_status(target);
                }
                else  
                {
                        message_combatd(HIR"\n狂风夹杂着碎石漫天飞舞,把$N和$n砸得遍体鳞伤！\n"NOR,me,target,""); 
                        target->receive_wound("qi",damage);
                        target->receive_wound("jing",damage/2);
                        COMBAT_D->report_status(target);
                        me->receive_damage("qi",damage/10);
                        COMBAT_D->report_status(me);
                }        
        }
        me->delete_temp("noauto");
        //me->receive_damage("jing", 100);
        me->add("neili", -100);

if ((int)me->query_skill("aohan-liujue",1)> 680)
{
       message_combatd( HIR "$N聚气于刀，默运内力，只听“铮”的一声，忽然间银光闪耀，$N手中"+ weapon->name() + HIR"竟化为无数\n"
         + "截，如漫天红云般向$n激射而出！\n"NOR, me, target, "");

        attp = me->query_skill("panshi-shengong",1) + me->query_skill("aohan-liujue",1);
        defp = target->query_skill("dodge");

//      if( random( attp ) > random( defp ) )
        if(  attp  > random( defp ) )
        {
                damage =500+me->query_skill("aohan-liujue",1) + me->query_skill("blade",1)+ (int)me->query_skill("panshi-shengong", 1)*2;
                damage = damage - random( target->query_skill("dodge")/3 );
if (damage > 36000) damage=36000;
                target->receive_wound("jing", random( damage ));
                target->receive_damage("qi", 20 + random(damage)+damage);
                target->receive_wound("qi", 20 + damage);
                me->start_busy(3);
                target->start_busy(3 + random(4));
        }
        else 
        {
                message_combatd( HIY "可是$p晃动身形，迅速的闪过了无数刀屑。\n" NOR, me, target, "" );
                me->start_busy(2);
        }
}
      
        me->start_busy(4);
        
        return 1;
}


