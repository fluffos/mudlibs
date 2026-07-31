//毒龙穿心钻
//by junhyun@SK

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;

        int mkee;

        int ap, dp;

        int times, extra,i;
        string number;

        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("club",1);
        myskill1= (int)me->query_skill("bawang-qiang",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";

        if(!objectp(weapon)||(string)weapon->query("skill_type")!="club")
                return notify_fail("手里都没有枪，你往哪里钻？");
        if ( myskill1 < 180) return notify_fail("你的霸王枪法还不够火候！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『毒龙穿心钻』只能在战斗中使用。\n");
        if ((int)me->query("neili")<1300)
                return notify_fail("『毒龙穿心钻』过于费力，少用为妙！\n"); 

        if ((int)me->query("jing")<100)
                return notify_fail("你的精不够！\n"); 

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『毒龙穿心钻』只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("请使用太玄功!\n");

        if((int)me->query_skill("taixuan-gong",1) < 100)
                return notify_fail("你的太玄功还不够。。。\n"); 
        
        
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("neili");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("neili",-100);
        //me->receive_damage("jing", 50);
        message_vision(HIW"
$N单手握枪，纵身跃起，身随枪走，带起杀气滚滚！

            『毒龙穿心钻』 \n\n" NOR,me,target);        
        message_vision(HIY"
$N与手中枪化作一道金光犹如一条黑龙笔直的刺向对方！\n"NOR,me);
        
        if(random(myexp)>(int)(texp/5) || random(3)==0)
        {
                msg = HIR"
$n躲闪不及，金光大作中被$N连人带枪透体而过！\n"NOR;
                damage=300+(int)((int)(myskill1));
                if(damage<1)damage = 1;
                target->receive_damage("qi",damage*3,me);
                target->receive_wound("qi", damage*3,me);
                //target->start_busy(3);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                me->start_busy(1);
        }
        else
        {
                msg = HIW"$n自知不敌，身形一低,贴着地面平平的飞了出去！\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
                me->start_busy(2);
        }        
   
if (myskill > 600)
{
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        extra = (int)me->query_skill("bawang-qiang", 1);        
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
                     else{ 
                           times = 6;
                           number = "六";}


        damage = 300+me->query_str() + random(me->query_skill("club"));
message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);

                if (!target->is_busy()) target->start_busy(1);
        if (extra> 200) extra=200;
        for(i=1;i<=times;i++)
{
        me->add_temp("apply/attack", extra*2);
        me->add_temp("apply/damage", 2200);
                        msg = HIY "第"+chinese_number(i)+"枪-------> ”\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        
        me->add_temp("apply/attack", -extra*2);
        me->add_temp("apply/damage", -2200);
        me->receive_damage("jing", 20);
        me->add("neili", -(times*10));
me->start_busy(2);
}      
}               
     
        return 1;
}
