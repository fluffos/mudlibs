//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "天师洞");
	set("long", @LONG
天师洞以东汉张陵在此讲道修炼而得名，又名古常道观。洞在山腰混
元顶下峭壁间。中塑天师像，沿岩壁有廊可通。正殿名三皇殿，重檐回廊
，雄锯高台，气势宏伟。内供伏羲、神农、轩辕三皇石刻造像。
LONG
);
	set("exits", ([
		"northup"  : __DIR__"gulongqiao",
		"north"	: __DIR__"sanqingdian",
		"eastdown" : __DIR__"path2",
		"west"	 : __DIR__"yinxing",
		"east"	 : __DIR__"sandaoshi",
	]));

	setup();
	replace_program(ROOM);
}

