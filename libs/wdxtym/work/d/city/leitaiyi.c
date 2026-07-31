//luoyun 2016.7.14

inherit ROOM;

void create()
{
    set("short", "擂台");
    set("long", @LONG
加油! 加油! 加油! 加油! 加油! 加油! 加油! 加油! 加油! 加油! 
LONG
    );
	/*
    set("exits", ([  
        "down" : __DIR__"duobaoleitai",	
    ]));
	*/
	set("no_new_clean_up", 0);
	set("type", "balance");
	set("fight_room", __DIR__"shangjinleitai");	//设置玩家昏迷后移到该房间
	set("no_sleep_room",1);
	set("action_list", ([
		"离开":"outleitai",
	]));
	setup();
}
void init()
{
	add_action("out_leitai","outleitai");  
	
	remove_call_out("out_time");
	call_out("out_time", 180);
}
void out_time()
{
	object *obs, ob;
	int k, unit;
	
	obs = all_inventory(this_object());
	foreach(ob in obs) {
		if (userp(ob))
		{
			unit = ob->query("bet/balance/unit");
			if (unit > 1) {
				ob->add("balance", unit);
				ob->delete("bet/balance/unit");
				tell_object(ob, ("系统退还你金钱："+MONEY_D->money_str(unit)+"。\n"));
			}
			if (ob->move("/d/city/shangjinleitai")) {
				ob->set_temp("biwu_time", time() + 10);
				tell_object(ob, "你超时被系统自动请离了擂台。\n");
			}
			else
				k++;
		}
	}
	if (k > 0) {
		remove_call_out("out_time");
		call_out("out_time", 5);
	}
}
/*
void relay_message(string msg)
{
	object look_fight_room;
	string *msgs;
	int i;

	if (!look_fight_room=find_object(__DIR__"duobaoleitai"))
		look_fight_room=load_object(__DIR__"duobaoleitai");
	msgs=explode(msg, "\n");
    for (i=0;i<sizeof(msgs);i++)
    if (strlen(msgs[i])>5)
	message("vision",NOR+"@@ -->"+msgs[i]+"\n",look_fight_room);
}*/
int out_leitai(string arg)
{
	object me = this_player();
	string str;
	int unit;
	
	if (me->is_fighting())
		return notify_fail("临阵脱逃，非大丈夫所为呀！\n");
	
	if (me->is_busy())
		return notify_fail("你正忙呢！\n");
	
	if (!arg || sscanf(arg, "%s", arg) != 1) {
		str = sprintf("%s", "离开擂台:outleitai yes" + ZJSEP);
		str += sprintf("%s", "取消离开:outleitai no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	}
	if (arg == "yes") {
		unit = me->query("bet/balance/unit");
		if (unit > 1) {
			//unit = unit /100 * 99;
			me->add("balance", unit);
			me->delete("bet/balance/unit");
			tell_object(me, ("系统退还你金钱："+MONEY_D->money_str(unit)+"。\n"));
		}
		tell_object(me, "你决定离开擂台。\n");
		me->set_temp("biwu_time", time() + 10);
		me->move("/d/city/shangjinleitai");
	} else
	{
		tell_object(me, "你决定继续呆在擂台上。\n");
	}
	
	return 1;
}
