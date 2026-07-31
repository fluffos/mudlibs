// Room: /d/heifeng/ling7.c

inherit ROOM;

void create()
{
	set("short", "陡峭山路");
	set("long", @LONG
这是一条陡峭的小路，窄得只能容一个人走，左面是万丈悬
崖，右面是长满藤蔓的石壁。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ling6",
]));

	set("outdoors","heifeng");
	setup();
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me = this_player();

	if(!me || arg != "藤蔓")
		return 0;

	write("你扯开藤蔓钻了出去。\n");
	me->move(__DIR__"lu10");
	tell_room(__FILE__,sprintf("%s拉开藤蔓钻了进去。\n",me->name()));
	return 1;
}
