// /d/emei/yunvfeng.c 峨嵋派 深谷
// create by host dec,20 1997
inherit ROOM;

void create()
{
	set("short", "深谷");
	set("long", @LONG
从山洞里爬了出来，山洞离地竟然不过丈许，轻轻一跃，便已著地，脚下
踏著的是柔软细草，鼻中闻到的是清幽花香，鸣禽间关，鲜果悬枝，哪想得到
在这黑黝黝的洞穴之后，竟会有这样一个洞天福地？放眼四望，旦见翠谷四周
高山环绕，似乎亘古以来从未有人迹到过。四面雪峰插云，险峻陡绝计无法攀
援而入。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ 
		"south" : __DIR__"taolin",
		]));
	set("objects", ([ 
	]));

	setup();
	
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{

   object me = this_player();
	
    if ( !arg || (arg != "shandong") )
        return notify_fail("你想做什么，发痴吗？\n");

    if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");

    message_vision("$N手脚并用，沿石而上，爬入了山洞。\n", me);
    me->move(__DIR__"shandong12");
     return 1;
}
