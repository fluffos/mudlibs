// Room: /city/yamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌子分
放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前
巡逻。
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));
	set("action_list", ([
		HIY"悬赏通缉"NOR:"xuanshang",
	]));
	setup();
}

void init()
{
	add_action("xuanshang","xuanshang");
}

int xuanshang(string arg)
{
 string str;
	int money,i;
	object *ob,killer,me = this_player();

	if(!arg)
	{
		ob = filter_array(users(),(: $1->query_condition("killer")>0 :));
		if(!sizeof(ob))
			return notify_fail("目前没有可悬赏通缉的对象！\n");

		str = ZJOBLONG"请选择你要悬赏通缉的对象：\n"ZJOBACTS2+ZJMENUF(1,1,10,30);
		for (i = 0; i < sizeof(ob); i++)
		{
			str += (ob[i]->name()+"("+ob[i]->query("id")+")【通缉时间："+ ob[i]->query_condition("killer")/30 + "分钟】:xuanshang "+ob[i]);
			if(i<(sizeof(ob)-1)) str += ZJSEP;
		}
		tell_object(me,str+"\n");
		return 1;
	}

	if(sscanf(arg,"%s %d",arg,money)!=2)
	{
		if(!objectp(killer=find_player(arg)))
			return notify_fail("你要通缉悬赏谁？\n");
		if(!killer->query_condition("killer"))
			return notify_fail("该玩家目前没被通缉，不能被悬赏！\n");
		tell_object(me,INPUTTXT("你想用多少金币悬赏"+killer->name()+"("+killer->query("id")+")"ZJBR"(1-1000金，1两黄金20秒通缉时间，通缉时间超过150分钟会直接被抓进监狱)：","xuanshang "+arg+" $txt#")+"\n");
		return 1;
	}

	if(!objectp(killer=find_player(arg)))
		return notify_fail("你要通缉悬赏谁？\n");
	if(!killer->query_condition("killer"))
		return notify_fail("该玩家目前没被通缉，不能被悬赏！\n");
	if(money>1000||money<1)
		return notify_fail("请输入1-1000！\n");

	if(me->query("balance")<money*10000)
	{
		tell_object(me,ZJOBLONG"你钱庄里没有那么多的黄金去悬赏人！\n");
		return 1;
	}
	me->add("balance",-money*10000);
	killer->apply_condition("killer",killer->query_condition("killer")+money*10);
	tell_object(me,ZJOBLONG"悬赏成功，官府延长了对"+killer->query("name")+"的通缉时间！\n");
	tell_object(me,HIC"几个狱卒看到金灿灿的黄金，眉开眼笑的对你说：放心吧，只要犯人被带来，我保证让他把牢底坐穿！"NOR"\n");
	CHANNEL_D->do_channel(this_object(), "rumor", "听说有人重金打点了官府上下，牢头拍胸脯保证要让"+killer->query("name")+"把牢底坐穿。");

	return 1;
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north")
		return notify_fail("衙役喝道：“威……武……。”\n");
	return ::valid_leave(me, dir);
}