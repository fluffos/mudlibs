inherit ROOM;

void create()
{
	set("short", "玉女祠");
	set("long", @LONG
玉女祠里供奉的到底是哪位玉女，有许多不同的说法，现在所能看到
的只一尊呆板的石像。祠中大石上有一处深陷，凹处积水清碧，这是玉女
的洗脸盆，碧水终年不干。玉女祠左边是一处山崖(cliff)，很是陡峭。
LONG
	);
	set("outdoors", "huashan");
	set("exits", ([
		"west" : __DIR__"yunu",
	]));
	set("item_desc", ([
		"山崖" : ZJOBLONG"玉女祠下的山崖很是陡峭，似乎连接了一条小路。\n"ZJOBACTS2+ZJMENUF(2,2,10,32) + "跳下去:jump cliff\n",
	]));

set("resource/water", 1);
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
	int n = me->query("dex");

	if (!arg || arg != "cliff")
	{
		write("你打算往哪里跳？\n");
		return 1;
	}
	message_vision("$N深吸了一口气，飞身向山崖跳去。\n", me);
	if (n < 30)
	{
		message("vision", me->name() + "惨叫了一声，跌下了山崖。\n", me);
		me->move(__DIR__"kuihua_2");
		message("vision", me->name() + "一声惨叫，从上面的山峰上重重摔了下来。\n", me);
		me->unconcious(); 
	}
	else
	{
		message("vision", me->name() + "身法矫健，轻轻落至崖底。\n", me);
		me->move(__DIR__"kuihua_2");
		message("vision", me->name() + "从上面的山峰轻轻的落了下来。\n", me);
	}
	return 1;
}
