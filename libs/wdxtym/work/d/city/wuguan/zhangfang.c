//test.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"帐房"NOR);
	set("long", @LONG
这里是武馆的帐房，四壁雪白的墙，中间有个大柜台，柜台前上方挂着一
块牌子（paizi）， 房里挤满了来存取钱款的武馆弟子，显得十分嘈杂。帐房
先生是个五十多岁的老头，看见你走了进来，他笑嘻嘻地迎了上来。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zoulang6",
	]));
	set("no_fight",1);
	set("objects", ([
	]));

	setup();
}
