// guangming.c  圣火光明

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
#include <combat.h>


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
        int extra;
        int i,skill;

	int ap, dp, neili_wound, qi_wound;
      
        
        skill=(int)me->query_skill("lieyan-dao",1);
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
              if(damage > 3500) damage = 3500;
              target->receive_damage("qi", damage);
              target->receive_wound("qi", damage/3);
              me->add("neili", -150);
              //me->add("jing", -20);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if( random(5)>2          && me->query_skill("sougu",1 ) > 100
          && me->query_skill_mapped("claw") == "sougu"
          && me->query_skill_prepared("claw") == "sougu"){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N紧跟着上前一步，乘对方不备之际，左手变掌为鹰爪之势，自左向右抓向$n的"+name+"。\n"NOR;
           if( random(me->query_skill("claw")) > target->query_skill("dodge")/3
            ||!living(target) ){
               me->add("neili", -150);
               target->start_busy(7);
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

if (skill>300 && me && target)
{
  msg = HIY "$N使出搜骨鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n的全身要穴。\n";
        message_vision(msg, me, target);

if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);
        msg =  HIW "第一爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "第二爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "第三爪\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);

}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 || random(3)==0) {
                msg = "结果$p被$P点中要穴，立时动弹不得！\n" NOR;
                target->start_busy( 7);

        } else {
                msg = HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
}	

if (skill>400 && me && target)
{
msg = HIC "$N突然如同「吸血青蝠」，欺近$n的身前，张嘴便向$n的咽喉咬去。\n"NOR;
	message_combatd(msg, me, target );
 if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 500);

        msg =  HIR "第一咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "第二咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "第三咬\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);    
        me->add_temp("apply/damage", -500);

}
	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp || random(3)==0)
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n只觉得咽喉一阵剧痛，$N正在狂吸$n的鲜血！\n"NOR;
		neili_wound = 800 + (skill*2);
		if(neili_wound > target->query("qi"))
			neili_wound = target->query("qi");
if (neili_wound> 60000) neili_wound=60000;

		qi_wound = neili_wound / 3;
		if (target->query("qi") > neili_wound)
		target->add("qi",-neili_wound);
		if (target->query("eff_qi") > neili_wound)
		target->add("eff_qi",-neili_wound);
		me->start_busy(2);
	       me->add("qi",qi_wound);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的利齿！\n"NOR;
		if(userp(me))

		me->start_busy(2);
		message_combatd(msg, me, target);
	}
}
        return 1;
}
