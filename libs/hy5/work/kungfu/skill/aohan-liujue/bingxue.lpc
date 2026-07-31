//Created by Wuyou@Sanjie

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, mypot, tapot, ap, dp, def, extra;
        object weapon;
        weapon = me->query_temp("weapon");
        
        damage = (int)me->query_skill("aohan-liujue", 1) + (int)me->query_skill("blade", 1);
        //damage = damage/2 + random(damage/2);
        
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
                
        if( !me->is_fighting(target) )
                return notify_fail(HIR"“千里冰封漫天雪”"WHT"只能在战斗使用。\n"NOR);

        if( me->is_busy() )
                return notify_fail(HIR"你现在正忙。\n"NOR);

                    
            if (me->query_skill("aohan-liujue",1)<200)
                return notify_fail(WHT"你的这门武功不够纯熟，还得继续努力。\n"NOR);     

        if((int)me->query("neili") < 600 )
                return notify_fail(WHT"你的内力不足。\n"NOR);
        if( me->query("max_neili") < 1000 )
                return notify_fail(WHT"你的内力修为甚浅，不足以用"HIR"「千里冰封漫天雪」"WHT"。\n"NOR);     
        if( (int)me->query("qi") < 200 || (int)me->query("jing") < 200  )
                return notify_fail(WHT"你身体太虚弱了，无法施展"HIR"「千里冰封漫天雪」"WHT"！\n"NOR);


            
        msg = MAG "\n\t☆★☆★"HIW"玉雪"HIG"为"HIB"骨"HIW"冰"HIG"为"HIR"魄，"HIY"幻梦"HIW"冰雪"HIM"落"HIC"晴空！"NOR""MAG"★☆★☆\n" NOR;                      
                     
        me->add("qi", -50);
        me->add("jing", -50);
        me->start_busy(3); 
        msg += WHT "\n\t～～～六月飞霜～～～\n" NOR;
        msg += WHT "\t\t\t千里冰雪谁人怨？\n" NOR;
        msg += HIC "\n炎炎烈日，晴空万里。$N哀嚎一声，顿时瑞雪纷飞，怨气冲天！\n" NOR;
        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) 
        {
                msg += HIY "$n不知躲闪，被怨气包围了！\n" NOR;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target); 
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n运功相抗，将怨气阻止在身体外围。\n" NOR;
                message_combatd(msg, me, target, "");
        }               
        
        msg = MAG "\n\t～～～冰雪碎梦～～～\n" NOR;
        msg += MAG "\t\t\t万物成灰一场空？\n" NOR;
        
        mypot=(int)me->query_skill("aohan-liujue");
        mypot=mypot*mypot*mypot + (int)me->query("combat_exp");

        tapot=(int)target->query_skill("parry");
        tapot=tapot+(int)target->query_skill("dodge")/10;
        tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
        
        msg += HIW "\n天空闪现霞光万道，隐隐约约$n看见天宫中仙子嬉戏，众仙聚宴。
$n不禁看的出神，猛然间一股寒气从后背袭来。\n" NOR;
        
        if( random( mypot+tapot ) > tapot/4 || !living(target) ) 
        {
                msg += HIY "$n早已进入梦幻之中尚未清醒，被刺了一个透心凉。\n" NOR;
                COMBAT_D->do_attack_damage(me, target);
                damage=100+damage;
                target->receive_damage("qi",damage);
                target->receive_wound("qi", damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);                
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n不被幻象所迷惑，避开了这股寒气。\n" NOR;
                message_combatd(msg, me, target, "");
        }
                
        msg = HIR "\n\t～～～踏雪寻梅～～～\n" NOR;
        msg += HIR "\t\t\t曲尽知谁解"HIW"冰心？\n" NOR;        
        msg += HIM "\n冰雪将尽，寒梅盛开。点点梅花，阵阵飘香。万朵梅花齐飘落，如点点寒星袭向$n。\n" NOR;
        
        if (me->query_skill("force") > random(target->query_skill("force")))
        {
                msg += HIY "$n被梅花花瓣打的遍体鳞伤。\n" NOR;
                 damage=200+damage;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);      
                me->add("neili", -50);
        }
        else
        {
                msg += HIY "$n居然不可思议的躲过了万朵花瓣！\n"NOR;
                message_combatd(msg, me, target, "");
        }

                        
if ((int)me->query_skill("aohan-liujue",1)> 380)
{                         
      msg = HIW
 "\n$N身影慢慢的浮现在你面前，只见$N洒出无数晶莹剔透的"RED"雪玲珑"NOR"\n"HIW"围绕在你周围，刀光剑影的世界霎时间沉寂在这柔和的雪光之中，好一记温柔\n缠绵的"HIG"玲珑雪"NOR"\n"HIM"纵情山水间，挥洒天地情!\n"NOR;

        ap = me->query_skill("aohan-liujue", 1);
        ap = ( ap * ap * ap / (3 * 350) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (7 * 400) );
        dp = dp*250 + target->query("combat_exp");
        //if( random((ap + dp)/800+1) <  dp/2200 ) 
        if( random((ap + dp)/600+1) <  dp/2500 ) 
        {
                msg += HIY "可$n并没有被这绚丽的雪景所吸引,依然屹立在雪花飞舞的幻景中！\n\n"NOR;
                message_combatd(msg, me, target, "");
        } 
        else 
        {
                damage = 300+(int)me->query_skill("aohan-liujue",1)*5 ;
                msg += HIR "\n$n顿时沉寂在这梦一般的景象之中，如痴如醉中被雪玲珑击中了！\n\n" NOR;
                damage +=random(10);
                target->receive_damage("jing", damage/3);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
}           

if ((int)me->query_skill("aohan-liujue",1)> 680)
{
       msg = HIC "\n$N念了几句咒语，右手一挥，周围顿时变的其冷无比！
$N运起神功，一团刺骨的寒气向$n直逼而来！\n" NOR;
        
        
        if( random((int)me->query("max_neili")*4) > (int)target->query("max_neili"))
        {
                
                msg += HIW"\n$n被$N发出的这团寒气包了个正着！\n\n" NOR;
                
                target->start_busy(3); 
                
                msg +=  HIC ">>$N手中"+ weapon->name() + HIC"寒光一闪，身形也随着腾空而起，
随即一式"HIW"「寒光斩」"HIC"幻出无数刀光向$n迎面劈来！\n\n"NOR;
                                
                if (me->query_skill("parry") > random(target->query_skill("parry")))
                {
                        msg += HIC"$n还没想出该怎样拆招，一道血光已经象闪电一般，穿体而过！\n"NOR;
                        damage = (int)me->query_skill("parry", 1);
                        damage = damage + random(damage);
                        def=(int)target->query_temp("apply/armor");
                        //damage -=damage*def/3000;
                        damage -=damage*def/6000;
                        damage =  damage+100;
                        damage = damage + me->query("jiali");
                        if (damage > 6000) damage=6000;
                        target->receive_damage("qi", damage);
                        target->receive_wound("qi", damage/2);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else 
                {
                        msg += HIC"$n忙一运功，往后一撤，无形中化解了这招的威力。\n"NOR;
                        message_combatd(msg, me, target, "");
                } 
                
                msg =   HIC">>$N手中"+ weapon->name() +""HIW"--寒光又闪，"HIC"$N也由静转动。
一动便急如风，脚踏奇门，刀走奇招，式式从$n意想不到的方位奇快劈出！\n" NOR;                
                       
                if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
                {
                        msg += HIC"$n一阵手忙脚乱，不知该如何去招架这静若水、快如电的刀法！\n"NOR;
                        damage = damage + random(200)+200;
                        if(damage<1)damage = 1;
                        if (damage > 6000) damage=6000;
                        target->receive_damage("qi",damage*3/2);
                        target->receive_wound("qi", damage);
                        message_combatd(msg, me, target, "");
                        COMBAT_D->report_status(target);
                }
                else
                {
                        msg += HIC"$n却心静如水，见招拆招，瓦解了$N这无声的攻势。\n"NOR;
                        message_combatd(msg, me, target, "");
                        
                }

                me->add("neili", -50);

        }
        else 
        {
                msg = WHT"\n$n早已经看出$N的企图，身形一闪，已避开了这团寒气。\n" NOR;
                message_combatd(msg, me ,target, "");
                me->add("neili", -50);
        }

}
                     
me->start_busy(3);                        

        return 1;
}



