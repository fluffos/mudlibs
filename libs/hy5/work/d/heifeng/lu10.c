// Room: /d/heifeng/lu10.c

inherit ROOM;

int being_yell = 0;

void create()
{
	set("short", "万丈悬崖");
	set("long", @LONG
这是山的最高处，前面是深不见低的万丈悬崖，凛冽的山风
急劲的从你身边吹过，向远处看去是浓浓的白雾。地上立着一块
小石板，上写着“黑风神威”四个字。石板后面的山壁上长满了
藤蔓。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"lu9",
]));

	set("outdoors","heifeng");

	setup();
}

void init()
{
	add_action("do_yell","yell");
	add_action("do_push","push");
}

int do_yell(string arg)
{
	object me = this_player();
	string passwd;

	if(!arg || arg == "" )
	{
		message_vision("$N扯开嗓子喊了几声，也不知道喊的是什么。\n",me);
		return 1;
	}

	if(arg != "黑风神威")
	{
		if(strlen(arg) <= 12)
			message_vision(sprintf("$N扯开嗓子喊道“%s！”，远处传来阵阵回声 %s %s...\n",
				arg,arg,arg),me);
		else
			message_vision(sprintf("$N扯开嗓子喊道“%s！”\n",arg),me);
		return 1;
	}

	message_vision(sprintf("$N高声喊道“在下%s，途经宝寨，久闻黑风大王威名，前来拜见！”\n",
		me->name()),me);

	if(being_yell || query("exits/north"))
		return 1;

	being_yell = 1;

	write("只听对面一个人说道：“稍等片刻，我去禀告大王。”\n");
	call_out("do_tongzhi",4,me);
	return 1;
}

void do_tongzhi(object me)
{
	if(!me || environment(me) != this_object())
	{
		being_yell = 0;
		return;
	}

	tell_room(__FILE__,sprintf("只听的对面一声高喊：“大王有话，请%s%s进寨一叙！”\n\n“得令！！”\n",
		me->name(),RANK_D->query_respect(me)));

	tell_room(__FILE__,"只听得对面一阵吱吱嘎嘎的乱响。\n");

	me->delete_temp("enter_heifeng");
	me->set_temp("can_enter_heifeng",1);

	call_out("open_cross",2,me);
	return;
}

int valid_leave(object who,string dir)
{
	if(dir == "north" && !who->query_temp("can_enter_heifeng"))
		return 0;
	else
		return ::valid_leave(who,dir);
}

void open_cross(object me)
{
	object ob;

	tell_room(__FILE__,"一架木吊桥从对面放了过来。\n");
	set("exits/north",__DIR__"cross");

	ob = find_object(__DIR__"gate");
	if(!ob)
		ob = load_object(__DIR__"gate");

	if(!ob->query("exits/south"))
	{
		tell_room(ob,"只听得对面一阵吱吱嘎嘎的乱响，吊桥被放了下来。\n");
		ob->set("exits/south",__DIR__"cross");
	}

	being_yell = 0;
	call_out("close_cross",20);
	return;
}

void close_cross()
{
/*
	object ob = find_object(__DIR__"gate");

	if(!ob)
		ob = load_object(__DIR__"gate");

	if(ob->query("exits/south"))
	{
		tell_room(ob,"只听一阵吱吱嘎嘎的乱响，吊桥又被吊了起来。\n");
		ob->delete("exits/south");
	}
*/
	if(query("exits/north"))
	{
		tell_room(__FILE__,"只听一阵吱吱嘎嘎的乱响，吊桥慢慢的被对面吊了起来。\n");
		delete("exits/north");
	}
}

int do_push(string arg)
{
	object me = this_player();

	if(!me || arg != "藤蔓")
		return 0;

	write("你扯开藤蔓发现了一条小路。\n");


	me->move(__DIR__"ling7");
	tell_room(__FILE__,sprintf("%s拉开藤蔓钻了进去。\n",me->name()));
	return 1;
}
