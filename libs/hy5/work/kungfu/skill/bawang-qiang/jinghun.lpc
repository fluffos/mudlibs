//惊魂霸王枪 BY Cigar 2002.04.05

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon; 
        int damage, ap, dp;

        int myskill,times, extra;
        string number;
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        extra = (int)me->query_skill("bawang-qiang", 1);  

        
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(CYN"你要对谁施展「惊魂霸王枪」？\n"NOR);

        if(!me->is_fighting()) 
                return notify_fail(CYN"「惊魂霸王枪」只能在战斗中使用！\n"NOR); 
        
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「惊魂霸王枪」只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("你的太玄功还不够。。。\n"); 
        if(me->query("max_neili") < 1500 || me->query("neili")<500)
                return notify_fail("你的内力修为甚浅，不足以用[惊魂霸王枪]。\n"NOR);

        if((int)me->query("qi") < 200 )
                return notify_fail(CYN"你身体太虚弱了，无法施展「惊魂霸王枪」！\n"NOR);
        if((int)me->query("jing") < 100 )
                return notify_fail(CYN"你身体太虚弱了，无法施展「惊魂霸王枪」！\n"NOR);

        if( time()-(int)me->query_temp("jinghun_end") < 3 ) 
                return notify_fail(CYN"你现在精神无法集中，再用此绝技恐有损元气！\n"NOR); 
        
        if((int)me->query_skill("bawang-qiang", 1) <120)
                return notify_fail(CYN"你的霸王枪法不够纯熟，无法使出这招「惊魂霸王枪」！\n"NOR);

 
        me->add("neili", -165);
        //me->receive_damage("qi", 100);

       msg = HIW "\n$N手举"+ weapon->query("name")+ HIW"直指苍天,只见枪头寒光点点,枪缨此时显得分外妖娆。";
        msg += "\n\n说时迟，那时快，$N双脚运力，急冲半空，稍是停顿，倒转枪头，俯冲而至，大喝一声≈≈\n\n" NOR;
        
        msg +=HIY "              ┏━┓                        ┏━┓  \n";       
        msg +=HIY "              ┃"+HIW"驚"+HIY"┃  ┏━━━━━━━━┓  ┃"+HIW"泣"+HIY"┃  \n";
        msg +=HIY "              ┃"+HIW"天"+HIY"┃  ┃"+HIR" 驚 魂 霸 王 槍 "+HIY"┃  ┃"+HIW"鬼"+HIY"┃  \n";
        msg +=HIY "              ┃"+HIW"地"+HIY"┃  ┗━━━━━━━━┛  ┃"+HIW"神"+HIY"┃  \n";
        msg +=HIY "              ┗━┛                        ┗━┛  \n";

      
        ap = me->query_skill("bawang-qiang", 1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("dodge");
        dp = ( dp * dp * dp / (4 * 300) );
        dp = dp*250 + target->query("combat_exp");
        if( random((ap + dp)/200) <  dp/1000 ) 

        {
                msg += "\n$n"+HIC"身体急速后退，踉踉跄跄的夺过了这致命的一招，此时浑身早已冷汗淋漓。\n"NOR;
                message_vision(msg, me, target);
              me->start_busy(2); 
        } else {
                damage = 800+(int)me->query_skill("club",1)  +
 		(int)me->query("jing") / 400 + random((int)me->query("jing") / 200 ) +
        (int)me->query("qi") / 400 + random((int)me->query("qi") / 200 );
                msg += HIW "\n只见寒光一闪，$N急冲几步，站定后远望山中景致，但见$n胸前已经被刺出一个血窟窿！\n\n" NOR;
                damage +=random(50);
                if(!target->is_busy()) target->start_busy(2);
                //target->receive_damage("jing", damage,me);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                me->improve_skill("bawang-qiang", 1, 1);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
        }

        

            if(myskill <170){
                times = 3;        
                number = "三";}
            else
                if (myskill <190){
                    times = 4;
                    number = "四";}
                else
                    if(myskill <210 ){
                           times = 5;
                           number = "五";}
            else
                    if(myskill <310 ){
                           times = 6;
                           number = "六";}
                     else{ 
                           times = 7;
                           number = "七";}

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        damage = 300+me->query_str() + me->query_skill("club");

message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);

                if (!target->is_busy()) target->start_busy(1);
        if (extra> 200) extra=200;
        for(int i=1;i<=times;i++)
{
        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", 2200);
                        msg = HIY "第"+chinese_number(i)+"枪-------> ”\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -2200);
        me->receive_damage("jing", 20);
        me->add("neili", -(times*10));
}
        if( times>5 && myskill> 360)
        {

                target->receive_damage("jing",damage,me);
                target->receive_wound("jing", damage,me);
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi", damage*2,me);
                                        
                message_vision(HIR"\n$n只觉得眼前一花，胸口已被$N的"+ weapon->query("name")+ HIR"搠出一朵灿烂的六出梅花！！！\n\n六个窟窿鲜血喷涌而出．．$n已经气息奄奄．．\n" NOR,me,target);
                COMBAT_D->report_status(target, 0);
        }
    	me->start_busy(3);
//        me->set_temp("jinghun_end",time()); 
        return 1;
}
