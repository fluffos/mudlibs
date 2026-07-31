#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
	int i=200;
	switch(random(4))
	    {

	    case 0 :
			tell_object(me, HIY "突然你身子一僵,一股热流从体内袭向各大要穴！\n" NOR );
			message("vision", me->name() + "脸色凝重,运功抵抗内伤的发作。\n",environment(me), me);
			me->add_busy(2);
			if(me->query_temp("sandie/jingshen"))
				me->add_condition("no_exert", 3);
			break;
	    case 1 :
			tell_object(me, HIY "忽然你全身剧痛无比,各大经脉象有千万支火热的针在扎一样！\n" NOR );
			message("vision", me->name() + "发起抖来，疼得全身缩成一团，运气抵挡伤痛。\n",environment(me), me);
			me->receive_damage("qi", 100);
			me->receive_wound("qi", 50);
			if(me->query_temp("sandie/jingshen"))
				me->add_condition("no_perform", 3);
			break;
	    case 2 :
			tell_object(me, HIY "你感觉到有一股完全不同于自己提内的内劲在各大经脉游走,扰乱你的内息！\n" NOR );
			message("vision", me->name() + "神色一滞,似乎体内有什么问题。\n",environment(me), me);
			if(me->query_temp("sandie/busy"))
				i+=i;
			me->receive_damage("neili", i);
			break;
	    case 3 :
			tell_object(me, HIY "一股炽热无比的内劲突然从体内直窜上头部各大要穴,你眼前一阵晕眩.\n" NOR );
			message("vision", me->name() + "身体一晃,象喝醉了酒似的,脸涨得通红。\n",environment(me), me);
			me->receive_damage("jing", 70);
			me->receive_wound("jing", 40+random(30));
			if(me->query_temp("sandie/busy"))
				me->add_condition("no_perform", 3);
			break;
	    }
	me->set_temp("last_damage_from", "内伤发作");
	me->apply_condition("yyz_hurt", duration - 1);
	if( duration < 2 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
