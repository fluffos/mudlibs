#ifndef CS_WEAPON_H_BY_BOOST
#define CS_WEAPON_H_BY_BOOST

#include <ansi.h>


#define CS_KNIFE	1
#define	CS_PISTOL	2
#define	CS_MAINGUN	3


//	武器应该设置的属性
//	set("bullets", 30);												//每个弹夹的子弹数
//	set("precision", 100);										//精确度， 除以100即为实际精确度
//	set("continue_shot_miss_interval", 1);		//连续发枪间隔，如果间隔小于此值，命中率减半，步枪、重机枪等应该设置该值，负数表示为分数间隔
//	set("damage",40);													//固定伤害
//	set("random_damage",20);									//附加随机伤害，总damage = query("damage") + random(query("random_damage"));
//	set("hs_rate",50);												//爆头率，伤害加倍，如果造成对方死亡则宣布爆头
//	set("busy_time",0);												//发枪后的busy，狙击类的枪应该设置该值, 负数表示 random(-busy_time)

void init()
{
	set("no_get",1);
	add_action("do_get","get");
	if(!query("msg_hs"))
		set("msg_hs", CYN "$N举起" + query("name")+CYN"，对准$n的头部就是一枪。只见$n的头部被打出一个大窟窿，$n眼看就不行了。\n" NOR);
	if(!query("msg_normal"))
		set("msg_normal",CYN "$N举起" + query("name") + CYN"，对准$n就是一枪。只见$n身上被打出一个大窟窿，$n眼看就不行了。\n" NOR);
	if(!query("msg_half"))
		set("msg_half",CYN "$N举起" + query("name")+CYN"，对着$n随意开了一枪。\n" NOR);
	if(!query("msg_missed"))
		set("msg_missed",CYN "$N举起" + query("name")+CYN"，对准$n就是一枪。糟糕，又打偏了！\n" NOR);
	if(!query("max_bullets"))
		set("max_bullets", query("bullets"));
}

int do_get(string args)
{
	object me, target;
	object *allitem;
	int i;
	me = this_player();
	target = present(args, environment(me));
	if(target && target->query("cs/type") && me->query_temp("cs"))
	{
		allitem = all_inventory(me);
		for(i = 0; i < sizeof(allitem); i++)
		{
			if(allitem[i]->query("cs/type") == target->query("cs/type"))
			{
				tell_object(me, "你已经带着"+allitem[i]->query("name")+"，不能再拿"+target->query("name")+"了。\n");
				return 1;
			}
		}
		message_vision("$N捡起一" + target->query("unit") + target->query("name")+"。\n", me);
		target->move(me);
		return 1;
	}
	return 0;
}



int shoot_player(object me, object target, int type);


int shoot(string arg)
{
	object me, target;
	me = this_player();
	target = present(arg, environment(me));
	if(!objectp(target))
		return notify_fail("你要攻击谁？\n");
	return shoot_player(this_player(), target, 1);
}
int shootall()
{
	return 1;
}
int knife(string args)
{
	object me, target;
	me = this_player();
	target = present(args, environment(me));
	if(!objectp(target))
		return notify_fail("你要攻击谁？\n");
	return shoot_player(this_player(), target, 0);
}

int shoot_player(object me, object target, int type)		//type 预留给shoot all
{
	int hit_rate, target_dodge;
	int damage;
	int hs_flag;
	int penality = 1;  //连发惩罚因子
	int interval; //发枪间隔
	int is_knife = 0;
	int busy_time;
	string msg;
	object weapon = this_object();
	object targetCard = target->query_temp("cs/card");
	int curtime = time();
	if(weapon->query("cs/type") == 1)
		is_knife = 1;

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(weapon->query("bullets") <= 0 && !is_knife)
		return notify_fail("糟糕，子弹打光了，赶紧换弹夹吧！(reload)\n");

	if(!target->query_temp("cs"))
		return notify_fail("不要乱杀无辜！\n");
	if(!target->query_temp("cs/card") || !targetCard || !targetCard->query("referee"))
		return notify_fail("系统错误，赶紧向wiz汇报吧。\n");
	if(!targetCard->query("referee")->query_temp("cs/allow_firendly_fire") && target->query_temp("cs/team") == me->query_temp("cs/team"))
		return notify_fail("看清楚点，他可是你的同伴你也杀？\n");

	if(!is_knife)
		weapon->add("bullets", -1);



	penality = weapon->query_temp("penality");
	if(penality <= 0)
		penality = 1;
	interval = weapon->query("continue_shot_miss_interval");
	if(interval < 0)		//考虑有些枪给1秒间隔太长了，给0又不合适，因此在此处给出相当于小于1秒的间隔，-4表示1/4秒
		interval = random(-interval) ? 0 : 1;
	if(curtime - weapon->query_temp("last_shoot_time") < interval)		//连发，提升惩罚因子
	{
		penality += 4;
		penality *= 1.2;
		if(penality > 100)				//最高惩罚到1/10（sqrt）
			penality = 100;
		weapon->set_temp("penality", penality);
	}
	else
	{		//超过间隔时间发枪，逐渐恢复惩罚到0
		penality = weapon->query_temp("penality") + weapon->query_temp("last_shoot_time") - curtime;
		if(penality <= 0)
			penality = 1;		
		weapon->set_temp("penality", penality);
	}
//	write(" "+penality+"\n");
	penality = sqrt(penality);
//	write(" "+penality+"\n");
	weapon->set_temp("last_shoot_time", curtime);
	hit_rate = weapon->query("precision") / penality;
	damage = 0;
	hs_flag = 0;
	
	hit_rate = hit_rate * (me->query_temp("cs/skill") + 1000) / 1000;
	target_dodge = (target->query_temp("cs/skill") + 1000) / 10;
	
	if(hit_rate > random(target_dodge))		//命中
	{
		damage = weapon->query("damage") + random(weapon->query("random_damage"));
		if(weapon->query("hs_rate") / penality > random(100))	//head shot, damage *= 2
		{
			damage = damage * 2;
			hs_flag = 1;
		}
		if(hs_flag)
			
			message_vision(query("msg_hs"), me, target);
		else
			message_vision(query("msg_normal"), me, target);
		target->query_temp("cs/card")->receive_damage(me, damage / penality, weapon, hs_flag);
	}
	else					//没有命中
	{	
		if(hit_rate * 2 > random(target_dodge))		//再给一次更高命中率的机会，但是伤害 / 5
		{
			message_vision(query("msg_half"), me, target);
			target->query_temp("cs/card")->receive_damage(me, random(damage / penality / 2), weapon, 0);				
		}
		else								//最后算作没打中
		{
			message_vision(query("msg_missed"), me, target);
		}		
	}
	busy_time = weapon->query("busy_time");
	if(busy_time < 0)
		busy_time = random(-busy_time) ? 0 : 1;
	if(busy_time)
	{
		tell_object(me, WHT"你突然觉得虎口一麻，" + weapon->query("name") + WHT"险些脱手。\n"NOR);
		me->start_busy(busy_time);
	}
	
	return 1;
}


#endif	//CS_WEAPON_H_BY_BOOST

