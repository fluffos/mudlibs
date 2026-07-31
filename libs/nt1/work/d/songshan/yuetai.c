// Room: /d/songshan/yuetai.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "月台");
	set("long", @LONG
这里是法王寺的月台。从月台东望，太室山峦高耸入云，寺东
有双峰插云，中间阙如。因名 "嵩门" 。中秋佳节，明月自峰中升
起，正当嵩门之中，银光洒满山谷，这就是登封八景之一的 "嵩门
待月" 。
LONG );
	set("exits", ([
		"east" : __DIR__"fawangsi",
	]));
	set("objects", ([
		__DIR__"npc/fei" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

