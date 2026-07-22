// island3.c  沙滩 附加语言，以便更新
// Looklove 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"沙滩"NOR);
        set("long", @LONG
这是一大片沙滩。周围布满了贝壳，不少螃蟹在洞里冒着泡沫。暖暖的阳
光撒在身上，晒得你浑身懒洋洋的。蓝蓝的海水一遍遍漫过来，冲刷着你脚下
的小石子。远处有几块大礁石，立在那里经受着波涛的冲击。
LONG
        );
        set("outdoors","福州");
        set("exits",([
		"west" : __DIR__"island4",
		"east" : __DIR__"island1",
		"north" : __DIR__"rock",
        ]));
	set("objects", ([
                MISC_D("beike") : 1,
	]));
        setup();
}