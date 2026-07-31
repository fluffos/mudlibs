// /d/mr/cufang.c
// by leontt
// update 1/5/2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"厨房"NOR);
	set("long",@long
这是一间小厨房, 虽然不大, 但是锅碗瓢盆, 油盐酱醋, 到很奇全。灶台
上堆满了新鲜瓜果蔬菜, 活鱼活虾, 不仅不脏不乱, 还十分干净整齐。
long);
	set("resource/water", 1);
         
	set("objects", ([
		FOOD_D("caiyeji") : 1,
		FOOD_D("yuyuan") : 1,
		FOOD_D("zaoya") : 1,
	]));
	set("exits",([
		"east" : __DIR__"didao1",
	])); 
	setup();
}
