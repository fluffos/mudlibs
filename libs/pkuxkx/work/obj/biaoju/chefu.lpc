#pragma save_binary
#include <ansi.h>

inherit NPC;

void set_level(int level_number);
int make_robber();
string long_msg();

void create()
{
	set_name("车夫", ({ "che fu", "chefu", "fu"}));
	if (random(10)>2) set("gender", "男性" );
		else set("gender", "女性" );
	set("age", 16+random(30));
	set("has_goods", 1);
	set("long", (: long_msg :) );
	setup();
	
}

void set_level(int level_number)
{
	set("difficulty", level_number);
	set("chat_chance", 5+3*random(level_number+1)); //max 55
	set("chat_msg", ({
		(: make_robber :)
	}));
}

int make_robber()
{
	object room, me, escort, robber, ob,*inv;
	int level_number, i,number;
	me=this_object();
	inv=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="jie fei")
			number++;
	}
	if (number>8)
	{
		command("say 强盗太多了，咱们快点走吧!");
		return 1;
	}
		
	level_number=(int)me->query("difficulty");
	
	room=environment(me);
	
	if (random(10)>2)
		CHANNEL_D->do_channel(me, "rumor",sprintf("镖车正行驶在%s附近",room->query("short")));
	if (random(level_number)<1)
	{
		command("say 耀武扬威,镖车来了~~~~!");
		return 1;
	}
	if (!room->query("no_fight"))
		command("say 这里风高林暗,不要有强人出没才好....");
	// if has difficulty, make robbers
	if(objectp(escort=me->query_leader()) 
		&& random(escort->query_kar())<15) 
	{
		for(i=0;i<1+random(1+level_number/4);i++)
		{
			robber=new("/obj/biaoju/robber");
			robber->set_level(level_number);
			robber->move(room);
			robber->set_leader(this_object());
			message_vision(HIR"突然有人从斜刺里跳出来,拦住了$N的去路!\n"NOR, escort);
			robber->do_rob(me);
		}
	}
	return 1;
}

string long_msg()
{
	object escort;
	if(!objectp(escort=this_object()->query_leader())
		|| (this_player()!=escort))
	return "这是镖局雇佣的一名车夫.\n";
	return "这是你负责护送的镖车车夫,本次任务的目的地是"+
		(string)escort->query("biaoju/task")+"\n";
}
