// sroad3.c
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
这里是靠近川西的崇山峻岭，怪石嶙峋。再往东去就是川西边缘了。
往西有一座雪山高耸入云。路边上有一个大雪坑(hollow)。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"sroad2",
		"northdown"  : __DIR__"nroad1",
		"westup"    : __DIR__"sroad4",
	]));

	set("item_desc",([
		"【雪坑】"  : "一个雪坑，似乎可以跳(jump)下去。\n"
		ZJOBACTS2"跳下去:jump hollow\n",
	]));
	set("outdoors", "xuedao");
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object guo;
	if (arg == "hollow")
	{
		message_vision("$N刚想往下跳，脚在雪地上一滑，啪叽一下摔到坑底。\n",this_player());
		this_player()->move(__DIR__"hollow");
	}
	else
	{
		message_vision("$N跳了起来，脚在雪地上一滑就趴在地上了。\n",this_player());
	}
	return 1;
}

