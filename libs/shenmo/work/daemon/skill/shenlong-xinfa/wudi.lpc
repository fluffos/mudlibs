// wudi.c 
// by emnil   98.8.12

#include <ansi.h>

inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
void remove_effect2(object me, int amount);

int exert(object me, object target)
{
	int skill,qi;
	string s;

	/*if( target != me )
		return notify_fail("你只能用神龙心法来提升自己的战斗力。\n");*/

        if(  !me->is_fighting() )
                return notify_fail("只有在打斗中才能使用!\n");
                
	if( (int)me->query_skill("shenlong-xinfa",1) < 100  )
		return notify_fail("你的神龙心法功力不够，无法施用「无敌」大法。\n");

	if( (int)me->query("neili") < 600  ) return notify_fail("你的内力不够。\n");
	if( me->is_busy()  ) return notify_fail("你正忙着呢。\n");
	if( (int)me->query("eff_qi")<me->query("max_qi")/2) 
	{
		if((int)me->query_temp("sld/wudi")==0)
			return notify_fail("你现在受伤过重，不能使用「无敌」大法。\n");
	}

	skill = me->query_skill("force");
	switch((int)me->query_temp("sld/wudi")) {
		case 2:return notify_fail("你已经发挥了你的最大潜力。\n");
		case 0: 	if( (int)me->query("neili") < 600  ) return notify_fail("你的内力不够。\n");
			me->add("neili", -400);
			me->set_temp("wdneili",0);
			s=HIR"$N大声叫道：“洪教主神通广大，我教战无不胜，攻无不克，无坚不摧，无敌不破，\n敌人望风披靡，逃之夭夭！”，双眼突然冒出一丝红光，似乎突然增加了功力！\n"NOR;
			me->set_temp("sld/wudi", 1);

			qi=me->query("max_qi");
			me->add("max_qi",qi/4);
			me->add("eff_qi",qi/4);
			me->add("qi",qi/4);
			if (skill > 500) skill=500;
			me->add_temp("apply/attack", skill/3);
			me->add_temp("apply/defense", skill/4);
			me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), 40);
			
			break;
		case 1:	if( (int)me->query("max_neili") < 1000  ) return notify_fail("你的内力不够。\n");
			me->add("max_neili",-5);
			s=
RED"$N发疯般的叫道：“洪教主神通护佑，众弟子勇气百倍，以一当百，以百当万。
洪教主神目如电，烛照四方。我弟子杀敌护教，洪教主亲加提拔，升任圣职。
我教弟子护教而死，同升天堂！”，突然喷出一口鲜血，似乎已经忘记了伤痛！\n"NOR;
			me->set_temp("sld/wudi", 2);			
			me->delete_temp("wdneili");
			me->set("eff_qi",me->query("max_qi"));
			me->set("qi",me->query("eff_qi"));
			me->set("jing",me->query("eff_jing"));
			me->set("neili",me->query("max_neili"));
			if (skill > 500) skill=500;
			me->start_call_out( (: call_other, __FILE__, "remove_effect2", me, skill:), 90);
			
			break;
//		defeat: break;
	}

	
	message_vision(s, me);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount )
{

	if(!objectp(me)) return;
	if ((int)me->query_temp("sld/wudi")>1) return;
	if(me->is_ghost())
	{
		me->delete_temp("sld/wudi");
		me->delete_temp("sld/shougong");
		me->delete_temp("wdneili");
		me->add_temp("apply/attack", -amount/3);	
		me->add_temp("apply/defense", -amount/4);	
		me->add("max_qi",-me->query("max_qi")/4);
		return;
	}
	if ( (int)me->query_temp("sld/wudi")>0 ) {
		if( ((me->query("neili")-me->query_temp("wdneili",1))<100) || (me->query_temp("sld/shougong")>0) )	{
			message_vision(HIR"$N好象虚脱了一样，突然垮了下来！\n"NOR,me);		
			
			me->add("neili",-me->query_temp("wdneili",1));
			if(me->query("neili")<0)
				me->set("neili",0);
			me->add_temp("apply/attack", -amount/3);	
			me->add_temp("apply/defense", -amount/4);	
			me->add("max_qi",-me->query("max_qi")/4);
			if(me->query("eff_qi")>me->query("max_qi")) 
				me->set("eff_qi",me->query("max_qi"));
			if(me->query("qi")>me->query("eff_qi")) 
				me->set("qi",me->query("eff_qi"));

			me->delete_temp("sld/wudi");
			me->delete_temp("sld/shougong");
			me->delete_temp("wdneili");
		}
		else {
			message_vision(HIR"$N大声叫道：“洪教主神通广大，我教战无不胜，攻无不克，无坚不摧，无敌不破，\n敌人望风披靡，逃之夭夭！”，双眼突然冒出一丝红光！\n"NOR,me);

			me->add_temp("wdneili",100);
			me->add("eff_qi",50);
			if(me->query("eff_qi")>me->query("max_qi")) 
				me->set("eff_qi",me->query("max_qi"));
			call_out("remove_effect",30,me,amount);
		}
	}
}

void remove_effect2(object me, int amount)
{
	if(!objectp(me)) return;
	if(me->is_ghost())
	{
		me->delete_temp("sld/wudi");
		me->add_temp("apply/attack", -amount/3);	
		me->add_temp("apply/defense", -amount/4);	
		me->add("max_qi",-me->query("max_qi")/4);
		return;
	}
	message_vision(RED"$N心神一松，再也支持不主！\n"NOR,me);		
	
	me->add_temp("apply/attack", - amount/3);
	me->add_temp("apply/defense",- amount/4);		
	me->add("max_qi",-me->query("max_qi")/4);
	if(me->query("eff_qi")>me->query("max_qi")) 
		me->set("eff_qi",me->query("max_qi"));
	if(me->query("qi")>me->query("eff_qi")) 
		me->set("qi",me->query("eff_qi"));
	me->delete_temp("sld/wudi");

//	me->unconcious();
}