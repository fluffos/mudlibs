// Room: /d/suzhou/jiudai.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "春在楼");
	set("long", @LONG
这是一座苏州城里有名的酒楼，整个楼面以雕刻为特色，
砖雕，木雕，石雕。走进楼内，一眼便看到一副八仙上寿图，
八仙人被描画的惟妙惟肖。楼内许多南北来往的门客正在聊天
品茶，只见店小二忙的不亦乐乎。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"beidajie2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2": 1,
	]));
	setup();
	replace_program(ROOM);
}

