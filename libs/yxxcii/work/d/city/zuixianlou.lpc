// zuixianlou.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "醉仙楼");
	set("long", @LONG
方圆数百里内提起醉仙楼可以说是无人不知，无人不晓。当年苏学士
云游到此，对醉仙楼的花雕酒赞不绝口，欣然为其题匾，流下一段传遍海
内的佳话，从此醉仙楼名声大震。楼下布置简易，顾客多是匆匆的行人，
买点包子、鸡腿、米酒就赶路去了。楼上是雅座。
LONG );
	set("exits", ([
		"west" : __DIR__"beidajie2",
		"up" : __DIR__"zuixianlou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

