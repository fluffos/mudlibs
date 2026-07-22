// Room: /d/huashan/shiwu.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long",@LONG
你走进石屋，屋内尘封蛛结，显然是许久没有人住了。
LONG);

	set("cant_hubiao", 1);
	set("exits", ([
		"west" : __DIR__"shulin4",
	]));

	set("objects",([
		__DIR__"npc/mu_renqing" : 1,
	]));

	setup();
}