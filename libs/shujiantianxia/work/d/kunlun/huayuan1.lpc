#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long",@long
这里是一个小花园，何太冲素来爱花，这里遍地种着珍奇花卉，你只觉得
花香阵阵袭来。
    北面是一条石板路，南面过去就是内室走廊，过几步就可见到三
圣堂，西面有座小石桥，风景倒也不错。
long);
	set("exits",([
		"north" : __DIR__"shilu1",
		"south" : __DIR__"lang1",
		"west" : __DIR__"shiqiao",
		"east" : __DIR__"lang",
	]));
	set("outdoors", "昆仑");
	setup();
}
