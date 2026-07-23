// guangming.c  圣火光明

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;


string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
}); 

string *limb=({
"颈部","后心","右腿","头部","小腹","胸口","腰间","裆部","右肩","右臂","右脚",
});

int perform(object me, object target)
{
        object weapon;
        int damage,p;
        string msg,name,dodge_skill,limbs;

        if(!target) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「圣火光明」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
         ||(string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
                
        if((int)me->query_skill("lieyan-dao", 1) < 100 )
                return notify_fail("你的烈焰刀法不够娴熟，不会使用「圣火光明」。\n");
                                        
        if ((int)me->query_skill("jiuyang-shengong", 1) < 120)
                return notify_fail("你的九阳神功火候太浅。\n");
                        
//        if((int)me->query_skill("piaoyi-shenfa", 1) < 100 )
//                return notify_fail("你的飘翼身法不够高，不能使用「圣火光明」。\n");

        if((int)me->query("max_neili", 1) < 800 )
                return notify_fail("你的内力修为不够，不能使用「圣火光明」。\n");

        if( me->query_skill_mapped("blade") != "lieyan-dao")
                return notify_fail("你现在的状态无法使用「圣火光明」。\n");

        if ((int)me->query("neili",1) < 500)
                return notify_fail("你的真气不够，无法使用「圣火光明」。\n");

        msg = HIC"\n$N大吼一声："HIR"为善除恶，惟光明故，喜乐悲愁，皆归尘土"HIC"。"+weapon->query("name")+HIC"和人合二为一，带着漫天杀气扑向$n。\n"NOR;

        if(((random(me->query("combat_exp",1)) > target->query("combat_exp",1)/4)
         &&(random(me->query_skill("blade")) > target->query_skill("parry")/4 ))
         ||!living(target)){
              limbs= limb[random(sizeof(limb))];
              msg +=CYN"$n只觉的所有退路都被这逼人的杀气笼罩，避无可避，不由大惊失色，登时眼前一花，"+weapon->query("name")+CYN"已从其"+limbs+"洞穿而出！\n"NOR;
              damage = (int)me->query_skill("blade");
              damage += (int)me->query_skill("dodge");
              damage *= 2;
              if(damage > 2500) damage = 2500;
              target->receive_damage("qi", damage);
              target->receive_wound("qi", damage/3);
              me->add("neili", -damage/4);
              me->add("jing", -20);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if( random(5)>2          && me->query_skill("sougu",1 ) > 100
          && me->query_skill_mapped("claw") == "sougu"
          && me->query_skill_prepared("claw") == "sougu"){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N紧跟着上前一步，乘对方不备之际，左手变掌为鹰爪之势，自左向右抓向$n的"+name+"。\n"NOR;
           if( random(me->query_skill("claw")) > target->query_skill("dodge")/2
            ||!living(target) ){
               me->add("neili", -150);
               target->start_busy((int)me->query_skill("lieyan-dao")/30 + 1);
               msg +=CYN"结果$n的"+name+"被抓个正着，全身不由自主的一颤，顿时不可动弹。\n"NOR;
           }
           else{
               dodge_skill = target->query_skill_mapped("dodge");
               if( !dodge_skill ) dodge_skill = "dodge";
               msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
               me->add("neili", -50);
           }
           message_vision(msg, me, target);
//           me->start_perform(5,"「圣火光明」");
           me->start_busy(2);
           return 1;         
         }
         }
        else{
              dodge_skill = target->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
              me->add("neili", -100);
              me->start_busy(2);
        }
        message_vision(msg, me, target);
//        me->start_perform(4,"「圣火光明」");
        return 1;
}
