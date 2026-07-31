// Room: /d/tianshui/taishang.c
// by 发现号(find)

inherit ROOM;

int max_skill = 45;

mapping skill = ([
"zhuge" : "literate",
"zhangfei" : "fork",
"guanyu" : "blade",
]),

act = ([
"zhangfei" : "拿着枪耍了一通",
"zhuge" : "拿着鹅毛扇比划了几下",
"guanyu" : "拿着刀耍了一通",
])
;

protected void time_counter()
{
	object *players;
	int time;

	call_out("time_counter", 5);

	if(!sizeof(players = filter_array(all_inventory(), (: userp :))))
		return;

	time = time();

	foreach(object ob in players)
	{
		int n;

		if(!ob)
			continue;

		if(!n = ob->query_temp("tianshui_time_counter"))
		{
			ob->set_temp("tianshui_time_counter", time);
			continue;
		}

		if(time - n > 12)
		{
			object room;
			message_vision("观众一起大喊“怎么还不唱！”，说着把$N轰下台来。\n",ob);
			room = find_object(__DIR__"houtai");
			if(!room)
				room = load_object(__DIR__"houtai");

			if(room)
				room->do_xie(ob);

			ob->delete_temp("tianshui_time_counter");
			ob->move(__DIR__"xitai");
	                tell_room(__DIR__"xitai",sprintf("%s从台上掉了下来，摔了个大马爬。\n",ob->name()),ob);
		}
	}
}

void create()
{
	set("short", "台上");
	set("long", @LONG
这是一个简陋的戏台，戏子们在这里咿咿呀呀地唱着。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"houtai",
  "eastdown" : __DIR__"xitai",
]));
	
	setup();
	call_out("time_counter", 5);
}

void init()
{
	add_action("do_chang","chang");
	add_action("do_quit","quit");
}

int do_chang(string arg)
{
	object me = this_player(),room;
	int plevel,pper,pint;
	string play;

	if( !stringp(play = me->query_temp("tianshui_playing")) )
		return notify_fail("你嘴里哼哼叽叽的也不知道在唱些什么。\n");

	pper = me->query("per");
	pint = me->query("int");

	if(me->is_busy())
		return notify_fail("你正在忙！");

	me->start_busy(2);

	if(me->query("kee") < 20)
	{
		message_vision("$N累得满头大汗，连唱腔都发颤了，观众一声吆喝，把$N轰下台来。\n",me);
		room = find_object(__DIR__"houtai");
		if(!room)
			room = load_object(__DIR__"houtai");

		if(room)
			room->do_xie(me);

		me->delete_temp("tianshui_time_counter");
		me->move(__DIR__"xitai");
                tell_room(__DIR__"xitai",sprintf("%s从台上掉了下来，摔了个大马爬。\n",me->name()),me);
		return 1;
	}
		
	me->receive_damage("qi", 20);

	if(me->query_skill(skill[play],1) > max_skill)
		return notify_fail(sprintf("你已经不能通过唱戏增长%s了。\n",to_chinese(skill[play])));

	if( !me->query_skill(skill[play], 1) )
		me->set_skill(skill[play], 0);
	plevel = me->query_skill(skill[play], 1);
	me->improve_skill(skill[play],(pper+pint)/5+plevel);

	message_vision(sprintf("$N咿咿呀呀地唱了一段，又%s，台下一片叫好！\n",act[play]),me);
	me->set_temp("tianshui_time_counter", time());

	return 1;
}

int valid_leave(object me,string dir)
{
	if( (dir == "eastdown") && me->query_temp("tianshui_playing"))
		return notify_fail("你还没卸妆，怎么能走呢？\n");
	me->delete_temp("tianshui_time_counter");
	return ::valid_leave(me,dir);
}

int do_quit(string arg)
{
	object me = this_player(),room;

	room = find_object(__DIR__"houtai");
	if(!room)
		room = load_object(__DIR__"houtai");

	if(room)
		room->do_xie(me);
	return 0;
}
