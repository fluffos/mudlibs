// tianji.c 天玑剑法  天玑无限 海上飘(piao)
// writted by piao 2001-10-1
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill, str;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
          myskill1= (int)me->query_skill("tianji-sword",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="sword")
        return notify_fail("你拿的武器不对，无法施展『天玑无限』。");
          if ( myskill1 < 150) return notify_fail("你的天玑剑法修为还不够，使用这一招会有困难！\n");
        if(me->query("family/family_name") != "峨嵋派" )
                return notify_fail("你是哪儿偷学来的武功，也想用『天玑无限』?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『天玑无限』只能在战斗中使用。\n");
        if ((int)me->query("force")< 500)
                return notify_fail("你的内力不够。\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIM"$N人剑合一，放出手中"+weapon->name()+HIM"化作一条彩虹，竟使出了峨嵋山天玑剑绝学--『"HIW"天玑飞虹"HIM"』！\n\n" NOR,me,target);        
     message_vision(HIC"$N飞身而起，身法之快追上握住"+weapon->name()+HIC"，只见无数剑影闪过。\n"NOR,me);
     message_vision(HIM"剑影随着彩虹直上云霄，『"HIW"天玑飞虹"HIM"』含劲欲发！\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = HIR"$n正看着入神，彩虹中的无数剑影纵然直下！\n"
                                "“嗖”的一声，从$n的身上穿体而过，血溅满地！\n\n"NOR;
	damage= (int)(((int)me->query("max_force")/2+myforce -  (int)target->query("max_force")/2 - tforce)/3);
 	if(damage<1)damage = 1;
 	target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
 	target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     	message_vision(msg, me, target);
        COMBAT_D->report_status(target);

     	}
     else {
            msg = HIW"$n情神一聚，知道天玑之中暗藏无限杀机。侧身闪过了这招『"HIM"天玑飞虹"HIW"』\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIM"$N身形转动，原来还有后招，转眼间又杀出一剑！\n" NOR,me,target);
     message_vision(HIM"这一招『"HIW"天玑再现"HIM"』比刚才那招更快，好像要一鼓作气，斩妖除魔！\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIR"$n还没有招架住刚才的攻势，就看杀招袭来竟不知所措！\n"
        "被$N的"+weapon->name()+HIR"刺的遍体鳞伤，突出一口鲜血！\n\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
     target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIW"$n临危不乱，使出浑身招数终于化解了$N的攻势。\n\n"NOR;
             message_vision(msg, me, target);
        }
          message_vision(HIM"$N突然收住身形，回步而立，撤锏于背后，无招胜有招，无形胜有形。\n"NOR,me);
          message_vision(HIM"这一招正是天玑剑的精华，尽在『"HIW"天玑无限"HIM"』！\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIR"$n以为$N破绽百出，大喜之下，急忙上前想抢攻。\n"
"竟不知$N这招杀机无限，$n刚一靠近，只见剑光一闪，从$n胸口穿体而过！\n"
"$n没有想到招中之招如此厉害，险些丢掉性命！\n\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);

                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用峨嵋山的绝招『"HIW"天玑无限"HIM"』杀死了。听说此招失传多年！";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
                       }

     }
else{
         msg = HIW"$n看破了这招的虚实，将计就计，假装冲上前，却在$N出剑的一瞬间腾空跃开，回手竟反攻一招！\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);

                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用峨嵋山的绝招『"HIW"天玑无限"HIM"』杀死了。听说此招失传多年！";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
	               }

        }
        
 me->start_busy(2);
        
     
        return 1;
}








