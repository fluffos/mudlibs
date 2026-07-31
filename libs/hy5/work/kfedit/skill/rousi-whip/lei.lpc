//rousi-whip
//perform lei 雷殛怒火
//writted by jie 2001-2-10

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("mace",1);
        myskill1= (int)me->query_skill("rousi-whip",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        
     if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "baiyun-xinfa")
                return notify_fail("请使用白云心法!\n");

        if((int)me->query_skill("baiyun-xinfa",1) < 200)
                return notify_fail("你的白云心法还不够。。。\n"); 

        if((int)me->query_skill("rousi-whip", 1) < 350)
                return notify_fail("你的柔丝乐鞭级别还不够！\n");
                
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『雷殛怒火』只能在战斗中使用。\n");
        if ((int)me->query("neili")<800)
                return notify_fail("你的内力不够。\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("neili",-300);
        me->receive_damage("jing", 20);
        message_combatd(HIC"$N招式一缓，手中"+weapon->name()+HIC"仿佛挽了千斤似的，使出了柔丝鞭法的绝学--『雷殛怒火』！\n\n" NOR,me,target,"");        
        message_combatd(CYN"$N气运丹田，平平砸出一鞭，慢，却嘶嘶作风雷之声。\n"NOR,me,target,"");
        message_combatd(CYN"这一招『雷霆薄击』挟着内力，却象密云乍现，惊雷含劲欲发！\n\n"NOR,me,target,"");
        if (random(myexp)>(int)(texp/8) && random(myforce) > (int)(tforce/4)) 
        {
                msg = HIC"$n只觉得一股劲气象闪电一般，穿体而过！\n"
                      "“哇”的一声，$n喷出一大口鲜血，看来是受了内伤！\n\n"NOR;
                damage= 100+(int)(((int)me->query("max_neili")/5+myforce -  (int)target->query("max_neili")/5 - tforce)/2);
                if (!userp(me) && damage>25000) damage=25000;
                if (damage >35000) damage=35000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else 
        {
                msg = HIC"$n忙运功向抗，深厚的内力将$N的攻势都激散了。\n\n"NOR;
                message_combatd(msg, me, target, "");
        }


        message_combatd(CYN"$N由静转动，一动便急如风，脚踏奇门，鞭走奇招，鞭鞭从$n意想不到的方位无声无息地砸出！\n" NOR,me,target,"");
        message_combatd(CYN"这一招『天雷荡邪』好似天公作怒，要把天下妖孽尽数劈死，使得个痛快淋漓\n\n" NOR,me,target,"");
        if(random(myexp)>(int)(texp/7)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
        {
                msg = HIC"$n马上手忙脚乱，不知该如何去招架这静若水、快如电的鞭法！\n"
                      "果不然，$N的"+weapon->name()+HIC"招招命中，$n浑身上下被砸的遍体鳞伤！\n\n"NOR;
                damage=200+random(50)+me->query("jiali")+((int)me->query_skill("rousi-whip")*2);
                                if (!userp(me) && damage>25000) damage=25000;
                if (damage >45000) damage=45000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$n却心静如水，丝毫不显慌乱，见招拆招，瓦解了$N这无声的攻势。\n\n"NOR;
                message_combatd(msg, me, target, "");
        }


        message_combatd(CYN"$N突然收住身形，回步而立，撤鞭于背后，无招胜有招，无形胜有形。\n"NOR,me,target,"");
        message_combatd(CYN"这一招『雷殛怒火』把柔丝鞭法的精髓要旨发挥地酣畅爽快！\n\n"NOR,me,target,"");
        if(random(myexp)>(int)(texp/2))
        {
                msg = HIC"$n果然杀薇，以为$N露出破绽，大喜之下，急忙上前想抢攻。\n"
                      "$N微微一笑，待$n靠近，长袖一抖，袖尽鞭出，直探$n的胸口。\n"
                      "$n连鞭影还没看到，就差点儿被穿的透心凉！\n\n"NOR;
                damage=100+(int)(random((int)(myskill1/10))+me->query("jiali")+((int)me->query_skill("rousi-whip")*2));
                if (!userp(me) && damage>25000) damage=25000;
                if (damage >45000) damage=45000;
                if(damage<100)damage = 100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                message_combatd(msg, me, target, "");
                COMBAT_D->report_status(target);
        }
        else
        {
                msg = HIC"$n看破了这招的虚实，将计就计，假装冲上前，却在$N出鞭的一瞬间腾空跃开，回手竟反攻一招！\n\n"NOR;
                message_combatd(msg, me, target, "");
                COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(2);
        me->add("neili",-300);
     
        return 1;
}

