// guangming.c 光明

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
string *songs = ({"五行之气调阴阳","损心伤肺摧肝肠","藏离精失意恍惚","三焦齐逆兮魂魄飞扬"});

string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
}); 

string *limb=({
"颈部","后心","右腿","头部","小腹","胸口","腰间","裆部","右肩","右臂","右脚",
});
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count, i;
	int skill;
        int damage,p;
      string song;                                   
        string name,dodge_skill,limbs;
      song = songs[random(sizeof(songs))];
        if( !target) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("只能在战斗中对对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你没有装备武器。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("qishang-quan", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("shenghuo-ling", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyang-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通明教武学，使出了明教的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	skill = me->query_skill("jiuyang-shengong", 1);
        message_combatd(HIR "$N" HIR "默念九阳神功的口诀：\n他"
                            "强由他强，\n清风拂山冈。\n他横任他横，\n"
                            "明月照大江……\n刹那间只见$N" 
                        HIR "全身顿时浮现出一层刚猛的劲气，将$P"
                        HIR "全全笼罩。\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill);
	me->add_temp("apply/strength", skill/3);
	weapon = me->query_temp("weapon");
if (random(3)==0) target->start_busy(3);
        msg =  HIW  "$N大喝一声：「" + HIR "焚我残躯，熊熊圣火" + HIW"」，真气所至，顿时四周狂风大作，\n$n身子不觉一震！" NOR;
   	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIR  "$N口中长吟到：“"HIR"焚我残躯，熊熊圣火。生亦何欢，死亦何苦"HIC"？" NOR;
      	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIY "$N口中长吟到：“"HIR"为善除恶，唯光明故。喜乐悲愁，皆归尘土"HIC"。" NOR;
      	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIC "$N口中长吟到：“"HIR"怜我世人，忧患实多！怜我世人，忧患实多"HIC"！”\n" NOR;
   	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill);
	me->add_temp("apply/strength", -skill/3);

	me->start_busy(4);
        msg = HIC"\n$N大吼一声："HIR"为善除恶，惟光明故，喜乐悲愁，皆归尘土"HIC"。"+weapon->query("name")+HIC"和人合二为一，\n带着漫天杀气扑向$n。\n"NOR;

        if(((random(me->query("combat_exp",1)) > target->query("combat_exp",1)/3)
         )
         ||!living(target)){
              limbs= limb[random(sizeof(limb))];
              msg +=CYN"$n只觉的所有退路都被这逼人的杀气笼罩，避无可避，不由大惊失色，登时眼前一花\n，"+weapon->query("name")+CYN"已从其"+limbs+"洞穿而出！\n"NOR;
              damage = (int)me->query_skill("sword");
              damage += (int)me->query_skill("jiuyang-shengong");
              damage *= 5;
              if(damage > 6500) damage = 6500;
              target->receive_damage("qi", damage/2);
              target->receive_wound("qi", damage/2);
              p = (int)target->query("qi")*100/(int)target->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
         if(  me->query_skill("shenghuo-ling",1 ) > 100
){
              name = xue_name[random(sizeof(xue_name))];
              msg += HIC"\n$N紧跟着上前一步，乘对方不备之际，左手变掌为鹰爪之势，\n自左向右抓向$n的"+name+"。\n"NOR;
           if( random(me->query("combat_exp")) > target->query("combat_exp")/3
             ){
              target->receive_wound("qi", damage/2);
               msg +=CYN"结果$n的"+name+"被抓个正着，全身不由自主的一颤，顿时不可动弹。\n"NOR;
           }
           message_vision(msg, me, target);
         }
         }
        message_vision(msg, me, target);
      message_vision(HIR"\n突然$N眼射精光，朗声念出句似歌非歌、似诗非诗的拳诀：“"+song+"”，接着走上前去，砰的一拳击向$n！\n"NOR,me, target);

     if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 
         ){         
            target->receive_damage("qi", me->query_skill("force")/2);            
                 target->apply_condition("qishang_poison", 30+target->query_condition("qishang_poison"));
            if(me->query("neili")*2 < target->query("neili"))  
                 tell_object(me, HIR"你只觉"+target->name()+"体内内力极强，你暗藏在拳内的各种力道根本送不出去！\n"NOR);
            else{
                 tell_object(me, HIW"在刚一触到"+target->name()+"的身体时，你便暗暗发力，将隐藏在在拳内的七种力道送了过去！\n"NOR);
                 tell_object(target, HIW"你一晃眼，只见"+me->name()+"的拳已经打在你的身上，跟着几股说不出的暗劲顺势传了过来！\n"NOR);
                }
            target->receive_damage("qi", me->query_skill("force")*2);    
            p = (int)target->query("qi")*100/(int)target->query("max_qi");
            msg = damage_msg(me->query_skill("force")*3, "内伤");
            msg += "( $n"+eff_status_msg(p)+" )\n";                
            } 
            else 
               {       
                msg = "只见$p轻轻一转身，已经绕到了$P身后。而$N却因劲力打空不受控制，头脑眩晕！\n";
               }
            message_vision(msg, me, target);
 	return 1;
}