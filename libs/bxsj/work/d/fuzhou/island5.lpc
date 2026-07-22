// island5.c 沙滩
// By Looklove for a Quest
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"沙滩"NOR);
        set("long", @LONG
这是一大片沙滩。周围布满了贝壳，不少螃蟹在洞里冒着泡沫。暖暖的阳
光撒在身上，晒得你浑身懒洋洋的。蓝蓝的海水一遍遍漫过来，冲刷着你脚下
的小石子。远处有几块大礁石，立在那里经受着波涛的冲击。
LONG
        );
        set("outdoors","福州");
        set("exits",([
		"north" : __DIR__"island4",
		"eastup" : __DIR__"lagoon",
        ]));

	set("objects", ([
                MISC_D("beike") : 2,
	]));

        setup();
}