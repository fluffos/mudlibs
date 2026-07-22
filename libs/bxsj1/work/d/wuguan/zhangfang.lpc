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

	set("item_desc",([
		"paizi" :
			"这里是帐房，目前我们提供的服务有：\n"
			"duihuan     兑换钱币。\n"
			"qu          提取存款。\n"
			"cun         存入钱币。\n"
			"check       查询存款。\n"
	]));

	set("exits", ([
		"north" : __DIR__"zoulang6",
	]));

	set("objects", ([
		__DIR__"npc/yan" : 1,
	]));

	setup();
}
