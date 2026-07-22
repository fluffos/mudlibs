// Room: /d/emei/shandong12.c 山洞12
// create by host dec,20 1997

inherit ROOM;
void init();

void create()
{
        set("short", "山洞");
	set("long", @LONG
你眼前骤然一黑，朦胧中，不时感到头顶一阵刺痛，只觉得洞内十
分狭窄和低矮。摸着洞内岩壁缓慢前行，从墙壁上散发出的阴冷潮湿气
息，使你不由自主的打了寒噤，浑身有说不出的难受。
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong13",
	]));
	setup();
}
void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

    object me = this_player();
    if ( !arg || (arg != "out") )
        return notify_fail("你想做什么，发痴吗？\n");
    if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");
    message_vision("$N从山洞里跳了出来，轻飘飘的落在了草地上。\n", me);
    me->move(__DIR__"yunvfeng");
     return 1;
}
