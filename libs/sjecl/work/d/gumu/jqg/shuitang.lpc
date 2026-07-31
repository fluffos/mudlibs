// shuitang.c 水塘
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","水塘");
	set("long",@LONG
穿过竹林，突然一阵清香涌至，眼前无边无际的全是水仙花，原来地下是
浅浅的一片水塘，深不逾尺，种满了水仙，这花是原是南方之物，不知何以竟
会在关洛之间的山顶出现。
LONG
);

	set("outdoors","绝情谷");
	set("exits",([
		"eastup": __DIR__"shanding",
		"westdown": __DIR__"qsroad",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;
	
	i = me->query("kar") + me->query_int();

	if (dir == "eastup") {
		write("东面是一大片竹林，北方很少见长得这般茂密的竹林，数量之大，确实罕见。\n");
		inv = filter_array(deep_inventory(me), (: userp :));
		if ( random(i) > 20 && ! sizeof(inv))
			write(HIW"\n你缓缓在绿竹篁中穿过，闻到一阵阵淡淡花香，登觉烦俗尽消。\n\n"NOR);
		else {
			tell_room(environment(me), me->name()+"往东边的"GRN"竹林"NOR"快步离开。\n"NOR, ({ me }));
			me->move(__DIR__"zhulin" + (random(6) + 1));
			tell_room(environment(me), me->name()+"从水塘快步走了过来。\n"NOR, ({ me }));
			me->look();
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
