// dingshen.c 定身法

#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="定身法";
        return str;
}



void free(object target);

int exert(object me)
{
        string msg;
        int success, ap, dp, howlong;
object target;
        if( !target ) target = offensive_target(me);

   



        if((int)me->query_skill("taiyi",1) < 100)
                return notify_fail("你的太乙道法还不够。。。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想把谁定住？\n");


        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("jing") < 10 )
                return notify_fail("你无法集中精力！\n");

        me->add("neili", -500);
        me->receive_damage("jing", 10);
           if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        msg = HIC
"$N口中念了句咒文，太上老君 急急行律令 朝$n一指，大喝一声：定！\n" 
NOR;

        success = 1;
        ap = me->query_skill("taiyi");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_neili");
        dp = (int)target->query("max_neili");
        if( random(ap + dp) < dp ) success = 0;
//here we compared max_mana.

        ap = (int)me->query("neili");
        dp = (int)target->query("neili");
        if( random(ap + dp) < dp ) success = 0;
   //here we compare current mana. this is important. you need recover to try again.

        howlong = 0;        
        if(success == 1 ){
                msg +=  HIR "结果$n手足僵硬，果然动弹不得！\n" NOR;
                //target->set_temp("no_move", 1);
        
                howlong = 3 + random((me->query_skill("taiyi") -100)/5);
                if(howlong>20) howlong=20;
                        target->start_busy(howlong);
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
        }           
        else {
                msg +=  HIR "结果$n被吓了一跳！\n" NOR; 
        } 

        message_vision(msg, me, target);

//he'll try kill you...
        //if( living(target) ) target->kill_ob(me);

        if (success == 0) {
                //me->start_busy(1);
   

                return 1+random(2);
}

//      me->start_busy(5);        
        //if( howlong>0 ) call_out("free", howlong, target);
        
        return 3+random(5);
}

void free(object target)
{
        if(target) target->delete_temp("no_move");      
        return;
}


