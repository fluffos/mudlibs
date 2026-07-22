// island4.c 沙滩
// Looklove 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"沙滩"NOR);
        set("long", @LONG
这是一大片沙滩。周围布满了贝壳，不少螃蟹在洞里冒着泡沫。暖暖的阳
光撒在身上，晒得你浑身懒洋洋的。蓝蓝的海水一遍遍漫过来，冲刷着你脚下
的小石子。远处有几块大礁石，立在那里经受着波涛的冲击。
LONG
        );
        set("outdoors","福州");
        set("exits",([
		"east" : __DIR__"island3",
		"south" : __DIR__"island5",
		"west" : __DIR__"island1",
        ]));
	set("objects", ([
		__DIR__"npc/dylaozhe" : 1
	]));
        setup();
}


