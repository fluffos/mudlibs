// Room: /d/beijing/zijin/shangshufang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"上书房"NOR);
	set("long",
HIC"房中一排排都是书架，架子上放满了书，也不知几千几万本。正
中一张极大的紫檀木书桌(desk)，桌面金镶玉嵌。桌后有把椅子，上
面披了锦缎，绣了一条金龙，墙上挂了不少名人字画。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"west" : __DIR__"qianqingmen",
  	"east" : __DIR__"sikongchu",
]));
	set("count", 1);
	setup();
	set("item_desc", ([
		"desk": "这是一张紫檀木书桌，左手放着砚台笔筒，右手放着一只香炉(xianglu)，香炉下面压着一本书。\n",
		"xianglu": "香炉呈长方型，通体以蓝绿釉为底，饰湖景，盖顶饰酚丝锭形纹，中绕六角形蜂窝纹，下饰双龙戏珠图。\n",
		]) );
}
void init()
{
	add_action("do_move", "move");
}
int do_move(string arg)
{
	object book;
	object me = this_player();
	if (!arg || arg != "xianglu")	return 0;
	if (query("count") > 0 )
	{
		message_vision("$N你伸手小心搬动香炉，只听“啪”的一声，炉下压着的书掉在了地上。\n", me);
		tell_object(me, "突然门外传来一声喝斥：“什么人？”\n你心想不好，被人发现了，还是拿了书赶快逃命吧。\n");
		add("count", -1);
		book = new("/d/beijing/npc/obj/book42_2");
		book->move(this_object());
		me->apply_condition("bjkiller", 100 + me->query_condition("bjkiller"));
	}
	else
	{
		message_vision("$N你伸手小心搬动香炉，不过什么都没有发现。\n", me);
		tell_object(me, "你一不小心弄出了响声，只听门外传来一声喝斥：“什么人？”\n你心想不好，被人发现了，还是赶快逃命吧。\n");
		me->apply_condition("bjkiller", 50 + me->query_condition("bjkiller"));
	}
	return 1;
}