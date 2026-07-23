 // counterattack.c
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int cps,skill;
        int extra, bonus, i, n, num;
        
        object *enemy,weapon;
               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『"HIG"月神一刀"NOR"』只能对战斗中的对手使用。\n");
        if((int) me->query_skill("tmdao",1) <= 300)
                return notify_fail("你的天魔刀还不够精纯，不能发出『"HIG"月神一刀"NOR"』。\n"); 

      if ( (int)me->query_dex() < 50 )
        return notify_fail("你的先天速度不足，不能领悟天魔刀的精髓招式"RED"〖月神一刀〗！\n"NOR);
        
        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("你的天魔剑法不够娴熟！\n"NOR);
        
        if( (int)me->query_skill("tmdao",1)<199)
        return notify_fail("你的天魔刀法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmquan",1)<199)
        return notify_fail("你的天魔拳法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmzhang",1)<199)
        return notify_fail("你的天魔掌法不够娴熟！\n"NOR);

        if( (int)me->query_skill("pmshenfa",1)<199)
        return notify_fail("你的飘渺身法不够娴熟！\n"NOR);

        if( (int)me->query_skill("tmdafa",1)<199)
        return notify_fail("你的天魔大法不够娴熟！\n"NOR);


        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你手中没有装备刀类武器！\n");
        if( (int)me->query("neili")<500)
        return notify_fail("你现在内力太弱，不能使用！\n"NOR);

 msg = HIR "\n$N"+HIR"将刀横于胸前，左手中指在刀背上一弹，右手借力挥刀。。。\n"NOR;
        message_vision(msg,me);
		skill=(int)me->query_skill("tmdao",1);
		extra=skill;
		n = skill/200;
		if(n==1) n=2;
		if(n > 6) n = 6;

        for(i=0;i<n;i++)
        {
            if(random(target->query("combat_exp")) < (int)me->query("combat_exp")/2) {
                message_vision(HIW"只见一道亮光从$N"+HIW"身前划过！！\n"NOR,target);
                target->receive_wound("qi",random(extra/2)+extra/2);
                target->receive_damage("qi",extra+extra/2);
                COMBAT_D->report_status(target);
			}
}
        message_vision(HIC"突然间天地昏暗，$N手中的刀锋幻花出淡淡月光，绚烂的光芒中，美丽的月神\n翩翩起舞，美妙的舞姿让人忘却了世间所有的恩恩怨怨。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(2)+1);
        me->start_busy(2);
        cps = (int)target->query("dex");
        if( random(cps) < 30 ) target->start_busy(1+random(1));
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        object weapon;
        int cps,myexp,tarexp,damgin,damsen,targin,tarsen;
        targin=target->query("max_qi");
        tarsen=target->query("max_jing");
        damgin = targin/2;
        damsen = targin/2;
        if (damgin>=30000) damgin=30000;
        if (damsen>=30000) damsen=30000;
        cps = (int)target->query("dex");
        myexp=me->query("combat_exp");
        weapon=target->query_temp("weapon");
        tarexp=target->query("combat_exp");
        
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
        	if ( (2*myexp+random(myexp/4)) >= tarexp ){
        		if(random(cps) < 30 && objectp(weapon)){
				message_vision(HIG "$N被眼前的景象迷惑，呆呆的放下手中的"NOR+weapon->query("name")+HIG"。\n"NOR,target);
				weapon->unequip();
				message_vision(HIG "突然之间，美丽的月神随着$N光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
                	} else if( !objectp(weapon) ){
                		message_vision(HIG "$N被眼前的景象迷惑，竟然放慢了进攻速度。\n"NOR,target);
				message_vision(HIG "突然之间，美丽的月神随着$N手中的光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
			} else {
				message_vision(HIG "突然之间，美丽的月神随着$N手中的光芒散去，漫漫月光凝成一道刀锋刺入$n喉咙！！\n"NOR,me,target);
			}
			//target->set_temp("last_damage_from",me);							
                	//target->die();
                	target->receive_damage("jing",damsen);
                	target->receive_damage("qi",damgin); 
                target->start_busy(8);
                }
                else{
                	message_vision(HIR"$N收心凝神，突然发现茫茫的月光中$n的刀锋竟向自己的咽喉刺来！！\n"NOR,target,me);
                	if(objectp(weapon)){
                		weapon->unequip();
                	        message_vision(HIR"千钧一发之疾，$N放下手中兵器，飞纵急退，$n的刀锋擦身而过！！！茫茫刀光让人心神荡漾！！！！\n"NOR,target,me);
                	}
                	else message_vision(HIR"千钧一发之疾，$N飞纵急退，$n的刀锋擦身而过！！！茫茫刀光让人心神荡漾！！！！\n"NOR,target,me);
                	target->receive_damage("jing",damsen);
                	target->receive_damage("qi",damgin); 
//                        target->receive_wound("gin",10 + random(celepower),me);
                        COMBAT_D->report_status(target);
                        COMBAT_D->win_lose_check(me,target,1);
                }                         
        }
        me->add("neili",-500);
        me->start_busy(3);        
        return ;
}     
