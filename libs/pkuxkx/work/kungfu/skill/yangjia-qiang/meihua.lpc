#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
       string msg;
        string number,level;
        int effect,da;
        myskill = (int)me->query_skill("yangjia-qiang", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「梅花三弄」？\n");

        if(!me->is_fighting())
                return notify_fail("「梅花三弄」只能在战斗中使用！\n");
            
                
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="spear")
                return notify_fail("「梅花三弄」要用枪才能发挥威力。\n");

        if((int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不够！\n");

	      if((int)me->query("neili") < 500 )
		            return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < (int)(me->query("max_jing")/2) )
                return notify_fail("你的精神不足，没法子施展梅花三弄！\n");
        
        if(myskill < 50)
                return notify_fail("你的霸王枪法级别还不够。\n");
        else 
            if(myskill <100){
                times = 3;        
                number = "三";}
            else
                if (myskill <150){
                    times = 4;
                    number = "四";}
                else
                    if(myskill <200 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}
                           
           if( me->query_temp("no_meihua") > time() )
        	return notify_fail("你刚使用过绝招，用多了就不灵了！\n");
          me->set_temp("no_meihua",time()+random(2)+times/2);
	
	damage = me->query_str() + random(me->query_skill("spear"));
	damage = damage*8/10;

message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"枪，枪枪要命！\n"NOR,me,target);

	effect = 0;
        for(int i=1;i<=times;i++)
		{	da =COMBAT_D->do_attack(me, target, weapon);
			if(da > 0)
				effect ++;
		}
		
		effect = 3;
	if(!random(effect))
	{
		message_vision(HIY"\n枪势似尽尤存，$N倒转"+ weapon->query("name")+ HIY"竟使出“绊”字诀，搅的$n一阵手忙脚乱！\n"NOR,me,target);
		da = target->query_busy();
		target->start_busy(da+1+random(10-effect)/2);
	
	}
    //    COMBAT_D->report_status(target, 0);
        me->receive_damage("qi", 20);
        if((int)me->query("neili") > (times*50+50) )
        	me->add("neili", -(times*50+50));
        else	
        	me->set("neili",0);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && random(times)>2)
	{

                target->receive_damage("jing",damage/2, me);
                target->receive_wound("jing", random(damage)/2, me);
                target->receive_damage("qi",damage/2,me,);
                target->receive_wound("qi", random(damage)/2, me);
                  			
		message_vision(HIR"\n$n只觉得眼前一花，胸口已被$N的"+ weapon->query("name")+ HIR"搠出一朵灿烂的梅花！！！\n\n六个窟窿鲜血喷涌而出．．$n已经气息奄奄．．\n" NOR,me,target);
        COMBAT_D->report_status(target);
	}
	
        me->start_busy(2+random(2));
        return 1;
}



