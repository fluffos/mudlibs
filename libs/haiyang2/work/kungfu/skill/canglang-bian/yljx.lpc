#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
int perform(object me, object target)
{
    string msg;
    int extra, celepower, i, skill,whippower, myexp, enemyexp,total;
    int exp_bonus,damage,damage1,damage2;
    object weapon;
    string *perform_msg = ({
        HIW "白练腾空"NOR WHT" － $N手中$W如白虹腾起天空，罩向$n。\n"NOR,
        HIW "浮游逍遥"NOR WHT" － $N身法飘摇，$W在奇幻的身影中抖出几个回环击向$n。\n"NOR,
        HIW "携雷掣电"NOR WHT" － $N手中$W化作一道闪电射向$n。\n"NOR,
        HIW "腾蛇乘雾"NOR WHT" － 在劈裂空气的爆响声中$W"NOR+WHT"如雾里现身的飞龙，击向$n。\n"NOR,
        HIW "龙见而雩"NOR WHT" － $W"WHT"如蛰龙初起，向$n"NOR+WHT"游动，霎时间化作一蓬鞭雨，洒向$n。\n"NOR,
        HIW "龙图出河"NOR WHT" － $N手中$W"WHT"折转空灵，在空中幻出一个个赤文篆字印向$n。\n"NOR,
        HIC "天行健，当自强不息"NOR WHT" － $N宁心提气，顿时天人合一，$W"NOR+WHT"平平常常一挥而出，却无可抵挡。\n"NOR,
        YEL "地势坤，以厚德载物"NOR WHT" － $N一盘手中$W"WHT"，一道道厚实柔韧的内劲如游龙般围上$n。\n"NOR,
        HIG "天道自然"NOR WHT" － $N凝鞭不发，忽然空中幻出众多生灵，种种天象展示在苍茫天地间。\n"WHT
        "$n不由得震慑于自然力的多彩与伟大。\n"NOR}); 

    weapon = me->query_temp("weapon");
    skill = me->query_skill("canglang-bian",1);   


        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");


        if (me->query_skill("force") < 150)
                return notify_fail("你的内功的修为不够，不能使用「云龙九现」！\n");

        if (me->query_skill("canglang-bian", 1) < 300)  
                return notify_fail("你的「沧浪鞭法 」未臻高妙境界，无法施出「云龙九现」！\n");  

        if (me->query_skill("bibo-shengong", 1) < 250)  
                return notify_fail("你的碧涛玄功修为不够，无法施出「云龙九现」！\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("你所用的并非「沧浪鞭法 」，施展不出「云龙九现」！\n");  

        if (me->query("neili") < 900)
                return notify_fail("你的真气不够，无法使用「夺命银龙」！\n");

    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail(WHT"［云龙九现］"NOR"只能对战斗中的对手使用。\n"); 
    celepower = me->query_skill("whip"); 
    
    exp_bonus = (me->query("combat_exp")-3000000)/6000000*celepower;
    if (exp_bonus<0) exp_bonus=0;
    if (exp_bonus>celepower) exp_bonus=celepower;
    
    damage = celepower+skill;
    
    myexp = me->query("combat_exp");
    enemyexp = target->query("combat_exp");
        message_vision(WHT"$N的鞭法一变，招式展开如层层密布的浓云，雨将落未落，风欲起未起\n"HIC"使出了天雷破的终极杀式  －  ［云龙九现］！！\n\n"NOR, me);
        for(i=0;i<9;i++)
        {
                msg = perform_msg[i];
                msg = replace_string(msg,"$W", weapon->name()+WHT);
                if (skill >= i * 20+10) {
                        if (i>6 && userp(me)&& (me->query_skill("whip")<300)) {
                                me->start_busy(2+i/2);
                                if (!random(1 + 8*i -i*i) && i!=8 ) 
                                        tell_object(me, YEL"\n你觉得鞭法似乎还有欠自然，不能一气呵成。\n"NOR);
                                return 1;       
                        }
                        message_vision("\n"+msg,me,target);
                        if (random(myexp)/150*celepower*(i/2+1)> enemyexp) {
                                message_vision("\n"MAG+weapon->name()+MAG"发出一丝丝幽幽的紫光，渗入$n"NOR+MAG"体内... ...\n"NOR, me, target);
                                damage1 = damage+ random(damage)*3/2;
damage2=damage1+ (int)me->query_skill("whip")+100; 
//                              total= damage1+total;
//                              message_vision(HIW"\t\tdamage is "+(string)(total)+" .\n"NOR,me);

                                target->receive_damage("qi", damage1);
                                target->receive_wound("qi",damage1);
                                target->receive_damage("jing", random(damage1/2));
                                target->receive_wound("jing",10 + random(celepower/2));
                                COMBAT_D->report_status(target);
                                COMBAT_D->win_lose_check(me,target,1);
                        if (i==8)       {
                                        message_vision(HIG"$N"+HIG"凝鞭收势，心神与天地融为一体，周身无懈可击。\n"NOR, me);
                                        me->start_busy(5);
                                        if ( target->is_busy()) target->start_busy(5);
                                           if ( !target->is_busy() ) target->start_busy(2);
                                        return 1;                       
                                        }       
                        } else 
                                message_vision(HIG"$N吐气旋身，闪过了$n的鞭影。\n\n"NOR,target,me);
                                                        
                }
        }
                i= (skill-10)/20-1;
                me->add("neili", -580);
                me->start_busy(4);
                return 1;       
                
} 

