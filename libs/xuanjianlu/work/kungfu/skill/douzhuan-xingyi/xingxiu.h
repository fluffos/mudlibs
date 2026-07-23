//xingxiu sy+yj
//liu 2002

#include <ansi.h>

int xingxiu(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( !target->query_temp("huagong") )
	{

	        object weapon;
	        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
		string str,*limb,type;
		mapping myfam;

        	message_vision(HIB"$N挥右拳挡住$n拳头，跟着左爪猛力向$n抓去。\n\n"NOR, me,target);

        	myexp = me->query("combat_exp");
        	targexp = target->query("combat_exp");
        	skill = me->query_skill("douzhuan-xingyi",1);
        
        	merand   = random((myexp/1000)*(me->query_skill("force")/10));
        	targrand = (myexp/1000)*(target->query_skill("dodge")/10)/3;

        	if(merand>targrand) {

                	message_vision(HIW"$n转身不灵，难以闪避，只得挺右手相抵。到此地步，已是高手比拼真力。\n\n"NOR,me,target);
                	tell_object(me, HIG"你潜运内功，将对手的内力化去。\n"NOR); 
                	tell_object(target, HIR"你心下暗惊，但觉内力源源不绝的向外飞散，再也凝聚不起。\n\n"NOR);      
                	target->set_temp("huagong", 1);
                	target->add("neili",-skill*2);
                	targneili=target->query("neili");
                	if(!userp(target)) target->set("neili", 0);
	                target->add_temp("apply/damage", -skill/10);
        	        target->add_temp("apply/parry", -skill/20);
			target->add_temp("apply/armor_vs_force", -skill/6);
	        	target->add_temp("apply/speed", -skill/6);
		        target->add_temp("apply/defense",  -skill/2);
                	target->set("jiali",0);
	                target->start_busy(random(2)+1);                
                
        	} else {       
	                me->start_busy(random(3)+1);    
        	        message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
                	tell_object(me, HIY"你心中暗想：“糟糕，竟然被这"+RANK_D->query_rude(target)+"看破了。”\n\n"NOR);
	                me->add("neili",-250);
			me->delete_temp("tong");
        	        return 1;
        	}
		
		time=skill/12;
		if(time<5) time=5;
		if(time>20) time=20;
        
                if(userp(target)) call_out("remove_effect3", time, me, target, targneili, skill); 
                        else call_out("remove_effect3", time, me, target, targneili, skill);
		me->delete_temp("tong");
		return 1;

	} else {

	        object weapon;
        	int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
		string str,*limb,type;
		mapping myfam;

		if(me->query_skill("sanyin-zhua")) {
			me->set_temp("memory",me->query_skill("sanyin-zhua",1));
			me->set_skill("sanyin-zhua", dk/2+me->query_skill("sanyin-zhua",1)/2);
		} else me->set_skill("sanyin-zhua", dk);
		me->map_skill("claw", "sanyin-zhua");
		me->prepare_skill("claw", "sanyin-zhua");

		message_vision(HIR"\n$N脸色一沉，趁$n内力被化之机，五指陡张，大喝一声：“中！”\n"NOR,me,target);

		skill=me->query_skill("sanyin-zhua",1);
		skill=random(skill+random(200))*2;
		if (skill>400) skill=400;
		if (skill<120) skill=120;
		me->add_temp("apply/attack", skill);         
		me->add("jiali", (skill/10)*2);

	        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	        me->add("neili", -250);
        	me->add("jingli", -150);
        	me->add("jiali", -((skill/10)*2));
	        me->add_temp("apply/attack", -(skill));
	        	
		message_vision(HIY"\n$N一击之后，身行一晃，似乎略有疲惫。\n"NOR,me,target);		

		me->start_busy(1+random(2));

		if(me->query_temp("memory")) me->set_skill("sanyin-zhua",me->query_temp("memory",1));
		else me->delete_skill("sanyin-zhua");
		me->delete_temp("memory");
		me->prepare_skill("claw");
		me->map_skill("claw");
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}

private int remove_effect3(object me, object target, int neili, int skill)
{
        target->delete_temp("huagong");
        if(!userp(target)) {
                target->set("neili",neili);
        }
        target->add_temp("apply/damage", skill/10);
        target->add_temp("apply/parry", skill/20);
	target->add_temp("apply/armor_vs_force", skill/6);
        target->add_temp("apply/speed", skill/6);
	target->add_temp("apply/defense",  skill/2);
        message_vision(HIG"慢慢的，$n觉得漫散的内力又一丝丝地聚回丹田。\n\n"NOR,me,target);
        return 1;
}