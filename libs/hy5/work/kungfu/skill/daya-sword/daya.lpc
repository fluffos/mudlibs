//测试一下，不知道效果如何 by seng@2005-1-21
//参考了moon的pfm tian;gumu的pfm jiujian;daya的pfm qijian;和combat.h

#include <ansi.h>


#include "/kungfu/skill/eff_msg.h";

#include <combat.h>


inherit F_SSERVER;
string *daya= ({
HIR"热血真气"NOR,
HIB"冲天剑气"NOR,
HIC"冰魄寒气"NOR,
RED"先天一气"NOR,
YEL"天雷电光"NOR,
BLU"地炎雷火"NOR,
WHT"腐烂毒气"NOR,
HIW"三味炎火"NOR
});
int perform(object me, object target)
{
    string dodskill,msg;
    int extra,i,j,tmp,strength,howlong,str,damage,targetforce;
    object weapon = me->query_temp("weapon");
    mapping action;
    extra = me->query_skill("daya-sword",1);
    j =  1+random(7);

    // howlong=me->query_skill("daya-jian")/(300+j*2);
    // mudring change arithmetic Feb/04/2005
    howlong = 1 + j/3;
    
    damage = extra + j*60+100;
    if(damage > 3700) damage = 3700;

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，武器不对？\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wuzheng-xinfa")
                return notify_fail("请使用无争心法!\n");
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");


    if ( me->query_skill("sword",1) < 300) return notify_fail("你的基本剑法还不够纯熟，舞出来的剑法怎么能雅？！\n");  
    if ( extra < 300) return notify_fail("你的大雅剑法还不够纯熟！\n");  
       
        if( (int)me->query("neili") < 800 )      
                return notify_fail("你的内力不够。\n");


        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                 return notify_fail("［大雅剑法］只能对战斗中的对手使用。\n");

		// mudring change 3 to 4 Feb/04/2005
		// and moved here....
       if( time()-(int)me->query_temp("daya_end") < 4 ) 
               return notify_fail(HIR "绝招用多就不灵了！\n" NOR); 
               
               
        me->add_temp("apply/attack",200);
        me->add_temp("apply/damage",1200);


        me->add("neili", -100);

         call_out("remove_ansi",howlong,me,str); 
         me->set("actions",action); 
         me->reset_action();


        if(!target->is_busy()) target->start_busy(2);


        message_vision(HIW  "\n\n$N将手中的"+ weapon->name() +RED"抛向天际，手指不受控制的对着$n凌空划来划去 ！\n\n" NOR, me, target);



// modify by mudring Feb/04/2005
    message_combatd(HIY  "\n「大雅古剑削肉式」，$N手中"+ weapon->name() +HIM"化为万千幻影朝$n的身上疯狂划去！" NOR, me, target);
    message_combatd(RED  "\n\n$N伸手朝空中"+ weapon->name() +RED"一召，鲜血顺着"+ weapon->name() +RED"的剑锋滴滴答答流了下来。$N肃穆而立，心中默念："+HIW"“无量天尊”！" NOR, me, target);
    message_combatd(HIR  "\n$N身形飞转 将手中的"+ weapon->name() +HIM"来回舞动，忽然化出数道先天"+HIW"「剑气」"+HIM"对着$n疯狂射去！" NOR, me, target);
    target->receive_damage("qi", damage); 


	j=j+3;
	if (j > 8) j=8;
	for(i=0;i<j;i++) 
	{
        message_combatd(HIR  "\n$N将手中的"+ weapon->name() +HIM"舞动，忽然化出数道"+HIW"「"+daya[random(sizeof(daya))]+"」"+HIM"对着$n疯狂射去！" NOR, me, target);
        if (i/3==0)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        else
        if (i/3==1)
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        else
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);       
   }

// end 

           targetforce = target->query("neili");
           
// mudring change Feb/04/2004
           //if(targetforce < 0 ) targetforce = 0;
           //target->add("force",-targetforce/2);         
if (targetforce>100000) targetforce=100000;
           target->add("neili",-targetforce/2);
           if(targetforce < 0 ) targetforce = 0;
// end
me->start_busy(3);
         me->set_temp("daya_end",time()); 
         
        return 1;
}


int remove_ansi(object me,int extra) 
    {        
           object here; 
           extra = me->query_skill("daya-jian",1);  
           if(me->query_temp("apply/attack")) 
           me->add_temp("apply/attack",-200); 
           if(me->query_temp("apply/damage")) 
           me->add_temp("apply/damage",-1200); 
           message_vision(HIW"$N发觉手中宝剑恢复原样！\n"NOR,me); 
           return 1; 
    } 
