// Room: wuxiuxi.c

inherit ROOM;

void create()
{
	set("short", "金牛武馆地下室");
	set("long", @LONG
这里是「金牛武馆」的地下室，虽然低洼，倒也干燥。只是有些昏暗，
靠墙有几张铺的好好的床，有些人正在休息，看来是疲倦坏了。
LONG );
	set("no_fight", 1);
	set("sleep_room", 1);
	set("exits", ([
		"up" : __DIR__"wuguan",
	]));
	setup();
}
