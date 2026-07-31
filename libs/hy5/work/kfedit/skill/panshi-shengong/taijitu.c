// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

//taijitu.c

#include <ansi.h>

inherit F_SSERVER;

string get_name(string str)
{
        str="太极图";
        return str;
}



int check_damage(object me, object target, int time);
int generate_msg(object me);

int exert(object me)
{
        int time;
        string msg;
        object target;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg,j;

        if( !target ) target = offensive_target(me);


        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展太极图？\n");

   if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展太极图？\n");

        if((int)me->query_skill("panshi-shengong",1) < 200)
                return notify_fail("你的磐石神功不足！\n");
             
        if((int)me->query_skill("taoism",1) < 200)
                return notify_fail("你的基本道术还不能自由运用太极图！\n");
        if( me->query_temp("cast_taiji"))
                return notify_fail("你已经在使用太极图！\n");        

        if((int)me->query("neili") < 2500 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("jing") < 500 )
                return notify_fail("你无法集中精力！\n");
     
        me->add("neili", -2*(int)me->query_skill("taoism"));
        me->receive_damage("jing", 200);
        if( random(me->query("max_neili")) < 500 ) 
        {
                write("你失败了！\n");
                return 1;
        }
        me->set_temp("cast_taiji",1);
        message_vision(HIR "\n$N口中念了句咒文，大喝一声：呔！。。。【太极无形】。。。\n空中金云陡起，迅速弥漫开来，将$N的身形隐去,周围顿时杀机四伏。\n"
        NOR,me,target);
        //me->set("env/invisibility", 1);
        time=(int)me->query_skill("panshi-shengong",1)/10 ;
if ((int)me->query_skill("panshi-shengong",1)> 600)
{
	
if (random(3)==0 && userp(me))
{
	      me->set("qi",me->query("max_qi"));
	      me->set("eff_qi",me->query("max_qi"));
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
me->add("neili",-300);
}
        

        msg = HIR"\n只听一声爆喝，$N伸手向天一指，招来滚滚天雷，纵身跳入雷电之中
用自己一身内力催动着雷电使出一招焚天化地的————

                     ┏━┓
                     ┃天┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃雷┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃焚┃
                     ┗━┛
                       ┃
                     ┏━┓
                     ┃火┃
                     ┗━┛
"
                 +"雷电化做一道烈火，般扑向$n！\n" NOR;
        ap = me->query_skill("panshi-shengong", 1);
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp = target->query_skill("parry",1);
        dp = dp * dp * dp /10;   
        dp = dp + target->query("combat_exp");
        dp = dp*qi_pcg/50;
        if( random(ap + dp) <  dp ) {
              msg += HIB "$n一见情势不妙，连忙就地一滚，虽于千钧一发之际躲过雷霆一击，却也狼狈不堪，吓得魂飞魄散，一时间动弹不得。\n"NOR;
              message_vision(msg, me, target);
         } else {
                  j=(int)me->query("max_neili")/20;
                  if (j>1500) j=1500;
                  damage=500+(int)me->query_skill("panshi-shengong",1)*3+j;
                  if (damage > 32000) damage=32000;
                  if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                  target->receive_wound("qi",damage,me);
                  msg += HIR "$n不料$N有如此一招，为此气势所慑，竟然楞在当地，忘了招架。\n
说时迟，那时快，这道白光已在$n身上当胸穿过！\n"NOR;
                   message_vision(msg, me, target);
                   COMBAT_D->report_status(target); 
           }
          me->start_busy(3);

}		
	

        if(time>30) time=30;
        check_damage(me, target, time);
        me->start_busy(3);
        return 10+random(5);

}

int check_damage(object me, object target, int time)
{
        int ap,dp,damage,success,j;

        if( !target
        || !me 
        || environment(me) != environment(target)) 
        {
                remove_call_out("check_damage");
                if (me) me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }

        if( !target
        || !me 
        || environment(me) != environment(target)) 
        {
                remove_call_out("check_damage");
                me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }

        ap= (int)me->query_skill("taoism",1);
        ap= ap*ap*ap/10;
        ap= ap+(int)me->query("combat_exp",1);

        dp= (int)target->query_skill("parry",1);
        dp= dp*dp*dp/10;
        dp= dp+(int)target->query("combat_exp",1);
        j=(int)me->query("max_neili",1)/20;
        if (j>1500) j=1500;
        damage=(int)me->query_skill("panshi-shengong",1)+j;
        success=1;
        if( damage < 0 ) success = 0;
        if( random(ap+dp) < dp ) success = 0;
        if( (int)me->query("neili") < 30 ) success = 0;
        if( (int)me->query("qi")  < 30 ) success = 0;
        if( environment(me)->query("no_fight")
        || environment(me)->query("no_magic") ) success = 0;

        if( success )
        {
                if(random(2))
                {
                        message_vision(HIC"\n云层中跳出个五大三粗的光膀子仙将，举起大锤朝$n砸来。\n"NOR,me,target);
                        message_vision(HIR"\n$n被仙将的大锤砸得七晕八素，差点摔倒在地！\n"NOR, me, target);
                        if (damage > 28000) damage=28000;
                        if (!target->is_busy()) target->start_busy(1);
                        if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                        target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage/2,me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("jing", 25);
                        me->add("neili", -25);
                        //if(!me->is_busy()) me->start_busy(2); 
                } 
                else 
                {
                        message_vision(HIC"\n雷公电母双双跳出，霎时间飞沙走石。\n"NOR, me, target);
                        message_vision(HIR"\n$n被雷声惊得差点站立不稳，神智不清了！\n"NOR, me, target);
                       if (damage > 25000) damage=25000;
                       if (damage > target->query("eff_jing")/2) damage=target->query("eff_jing")/2;
                        if (!target->is_busy()) target->start_busy(1);
                        target->receive_damage("jing", damage,me);
                        target->receive_wound("jing", damage/2,me);
                        COMBAT_D->report_sen_status(target);
                        me->receive_damage("jing", 25);
                        me->add("neili", -25);
                        //if(!me->is_busy()) me->start_busy(2);      
                }
        }
        time--;
        if( time ) 
        {
                call_out("generate_msg", 4, me);
                call_out("check_damage", 8, me, target, time);
        }
        else 
        {
                me->delete_temp("cast_taiji");
                //me->set("env/invisibility", 0);
                return 1;
        }
      
        return 1;
}

int generate_msg(object me)
{
        string *msgs=({
                HIR"\n四周人影重重，无数仙将蠢蠢欲动。\n"NOR,
                HIY"\n天空中飘荡着大旗，遮天蔽日……\n"NOR,
                HIB"\n天地混沌中，阴阳二气四处弥漫。\n"NOR,
                MAG"\n周围无数人影，已经看不清楚方向……\n"NOR,
        });
        if( !me ) return 1;
        tell_room( environment(me), msgs[random(sizeof(msgs))]);
        return 1;
}

