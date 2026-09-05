

#include <ansi.h>
inherit ITEM;
	

void create()
{
	seteuid(getuid());
	set_name(HIY"C4炸药包"NOR, ({ "c4" }));
	set_weight(1);
	set("no_get", 1);
//	set("no_put", 1);
	set_max_encumbrance(0);
	set("value", 1);
	set("unit", "包");
	set("plant_time", 10);
	set("defuse_time",10);
	set("bomb_time",50);
	set("damage",200);
	set("bomb_range",5);	//杀伤范围，每步递减，最后为0	
	set("cs/type",5);
	set("long", "这是匪徒专用的炸药包，威力强大。
你可以在合适的地点埋放(plant c4)\n");
}

void init()
{
	add_action("do_plant","plant");
	add_action("do_defuse","defuse");
	add_action("do_get","get");
}


int do_plant(string arg)
{
	object me = this_player();
	object referee;
	if(arg != "c4" && arg != "cancel")
		return notify_fail("什么？\n");
	if(!me->query_temp("cs/card") || me->query_temp("cs/team") != "t")
		return notify_fail("你研究了半天，也没搞清楚怎么埋。\n");
	referee = me->query_temp("cs/card")->query("referee");
	if(!referee)
		return notify_fail("系统错误（裁判），请通知巫师。\n");
	if(environment(this_object()) != me)
		return notify_fail("你还是先捡起来吧。\n");
	if(me->query_temp("cs/planting"))
		return notify_fail("你已经开始埋雷了！\n");
	if(arg == "c4")
	{
		if(me->is_busy())
			return notify_fail("看你慌慌张张的样子，有你这样的匪徒吗？\n");
		if(time() - referee->query("start_time") < 10)
			return notify_fail("稍等一会，警察还没有预备好呢！\n");
		if(!referee->IsValidBombRoom(base_name(environment(me))))
			return notify_fail("这里不能埋雷！\n");	
		message_vision(NOR"$N从背包中拿出" + query("name") + NOR"开始埋雷...\n", me);
		tell_object(me, "输入plant cancel可以中止埋雷。\n");
		referee->Declair("t", HIW + me->query("name") + "开始在" + environment(me)->query("short") + "埋雷！");
		me->set_temp("cs/planting", 1);
		set_temp("planting", query("plant_time"));
		set_temp("plant_place", environment(me));
		remove_call_out("plant_c4");
		call_out("plant_c4", 1, me);
		me->set_temp("cs/teamname",HIY" <匪徒> <埋雷中>"NOR);
	}
	if(arg == "cancel")
	{
		if(!query_temp("planting"))
			return notify_fail("什么？\n");
		set_temp("canceling", 1);
	}
	return 1;
}


int do_defuse(string arg)
{
	object me = this_player();
	object referee;
	if(arg != "c4" && arg != "cancel")
		return notify_fail("你想拆房子？\n");
	if(!me->query_temp("cs/card") || me->query_temp("cs/team") != "ct")
		return notify_fail("你研究了半天，也没搞清楚怎么拆，还是赶紧逃命吧。\n");
	if(!query_temp("planted"))
		return notify_fail("引信还没有被点着，拆什么拆？\n");
	referee = me->query_temp("cs/card")->query("referee");
	if(!referee)
		return notify_fail("系统错误（裁判），请通知巫师。\n");
	if(me->query_temp("cs/defusing"))
		return notify_fail("你已经开始拆弹了！\n");

	if(arg == "c4")
	{
		if(me->is_busy())
			return notify_fail("看你慌慌张张的样子，有你这样的警察吗？\n");
		message_vision(NOR"$N仔细观察" + query("name") + NOR"，开始拆弹...\n", me);
		tell_object(me, "输入defuse cancel可以中止拆弹。\n");
		me->set_temp("cs/defusing", 1);
		set_temp("defusing",query("defuse_time"));
		me->set_temp("cs/teamname",HIB" <警察> <拆弹中>"NOR);
		remove_call_out("defuse_c4");
		call_out("defuse_c4", 1, me);
	}
	if(arg == "cancel")
	{
		if(!query_temp("defusing"))
			return notify_fail("什么？\n");
		set_temp("canceling", 1);
//		message_vision(NOR"看来$N无法拆除" + query("name") + NOR"，$N还是选择了放弃。\n", me);

	}
	return 1;

}

int plant_c4(object me)
{
	object referee, bomb;
	bomb = this_object();
	referee = this_player()->query_temp("cs/card")->query("referee");
	if(bomb->query_temp("plant_place") != environment(me) || bomb->query_temp("canceling"))
	{
		bomb->delete_temp("canceling");
		bomb->delete_temp("planting");
		referee->Declair("t", HIW + me->query("name") + "放弃了埋雷！");
		me->set_temp("cs/teamname",HIY" <匪徒>"NOR);
		me->delete_temp("cs/planting");
		return 1;
	}
	bomb->add_temp("planting", -1);
	if(bomb->query_temp("planting") <= 0)
	{
		me->set_temp("cs/teamname",HIY" <匪徒>"NOR);
		message( "channel:" + "rumor",HIM+ "【谣言】某人：" + me->query("name")+"埋雷成功！\n"NOR, users());
		referee->set_temp("bomb_position", referee->RoomIndex(base_name(environment(me))));
		referee->Reward(me, "plant_c4", 0);
		delete_temp("planting");
		me->delete_temp("cs/planting");
		set_temp("planted", 1);
		set("long", "c4炸药包引信已经被点着，随时有可能爆炸。\n");
		set("name", HIR"C4炸药包"NOR);
		move(environment(me));
		remove_call_out("bomb");
		set_temp("bomb_time", query("bomb_time"));
		call_out("bomb", 1, referee);
		return 0;
	}	
	call_out("plant_c4", 1, me);
	return 1;
/*	
	if(!me || !me->query_temp("cs/card") || !me->query_temp("cs/card")->query("referee") )
		return notify_fail("系统错误（裁判），请通知巫师。\n");

	referee = me->query_temp("cs/card")->query("referee");	
	if(!referee->IsValidBombRoom(base_name(environment(me))))
		return notify_fail("系统错误（1），请通知巫师。\n");
	delete_temp("planting");
	set_temp("planted", 1);
	move(environment(me));
	me->start_busy(0);
*/
}


int defuse_c4(object me)
{
	object referee;
	if(!me || !me->query_temp("cs/card") || !me->query_temp("cs/card")->query("referee") )
		return notify_fail("系统错误（裁判），请通知巫师。\n");

	referee = me->query_temp("cs/card")->query("referee");	
	if(environment(me) != environment() || query_temp("canceling"))
	{
		me->delete_temp("cs/defusing");
		delete_temp("canceling");
		referee->Declair("ct", HIW + me->query("name") + "放弃了拆雷！");
		me->set_temp("cs/teamname",HIB" <警察>"NOR);
		return 1;
	}
	add_temp("defusing", -1);
	if(query_temp("defusing") <= 0)
	{
		me->set_temp("cs/teamname",HIB" <警察>"NOR);
		message( "channel:" + "rumor",HIM+ "【谣言】某人：" + me->query("name")+"成功的拆除了炸弹！\n"NOR, users());
		remove_call_out("bomb");
		referee->Reward(me, "defuse_c4", 0);
		referee->delete_temp("bomb_position");
		referee->DeclairCTWin();
		me->delete_temp("cs/defusing");
		delete_temp("defusing");
		destruct(this_object());
		return 0;
	}
	call_out("defuse_c4", 1, me);
	return 1;	
}


int do_get(string args)
{
	object me = this_player();
	if(args != "c4")
		return 0;
	if(!me->query_temp("cs"))
		tell_object(me, "你也想来拆雷？\n");	
	else if(query_temp("planted"))
		tell_object(me, "雷快要炸了，你还是赶紧逃命吧！\n");	
	else if(me->query_temp("cs/team") != "t")
		tell_object(me, "你似乎不会使用它，还是放在这里吧！\n");
	else if(args == "c4")
	{
		message_vision("$N捡起一"+query("unit") + query("name") +"。\n" NOR, me);
		move(me);
		return 1;
	}
	return 1;
}

int bomb(object referee)
{
//	referee->Declair("all", HIR+"只听轰的一声巨响，你感觉到周围的房屋都在震动。\n");
	int time_remaining, i, interval = 1;
	string msg, msg1;
	add_temp("bomb_time", -1);
	time_remaining = query_temp("bomb_time");
	interval = time_remaining / 10 + 1;
	if(time_remaining <= 0)
	{
		referee->Bombed();
		referee->DeclairTWin();
		destruct(this_object());
		return 0;
	}
	else if(time_remaining % interval == 0)
	{
		msg1 = "嘀";
		msg = "";
		for(i = 0; i < time_remaining / 2; i++)
			msg1 += "..";
		for(i = 0; i < 60 / sizeof(msg1) + 2; i++)
			msg += msg1;
		msg = msg[0..59];
		referee->Declair("all",msg);
	}
	call_out("bomb", 1, referee);
	return 1;
}

