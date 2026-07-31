// /u/beyond/mr/hc4.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"花丛中"NOR);
	set("long",@long
你信步观赏, 只见花林中除山茶花外更无别样花卉, 连最常见的牵牛花，
月月红, 蔷薇之类也是一朵都无。走出数十丈后, 只见山茶品种渐多, 偶而也
有一两本还算不错, 却也栽种不得其法。南面就是前院。
long);
	set("outdoors","曼佗罗山庄");
	set("exits",([
		"south" : __DIR__"qianyuan",
		"west" : __DIR__"hc1",
	]));

	set("objects",([
		__DIR__"../obj/chahua" : 1,
		__DIR__"../obj/chahua3" : 1,
		__DIR__"../obj/chahua1" : 1,
	]));
	setup();
}
