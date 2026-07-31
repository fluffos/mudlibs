// zhulin.c 
// 小竹林

inherit ROOM;
#include <ansi.h>
#include "zhulin.h"
void create()
{
	set("short", GRN "小竹林" NOR);
	set("long",@long
这是一片密密的竹林。这里人迹罕至，惟闻足底叩击路面，有僧敲木鱼
声；微风吹拂竹叶，又如簌簌禅唱。令人尘心为之一涤，真是绝佳的静修所
在。
long);
	set("outdoors", "峨嵋山");
	set("exits",([
		"east" : __DIR__"zhulin",
		"west" : __DIR__"zhulin",
		"south" : __DIR__"zhulin",
		"north" : __DIR__"zhulin",
]));
	set("no_sleep_room", 1);
	setup();
}
