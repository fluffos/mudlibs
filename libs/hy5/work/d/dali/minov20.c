//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "碧鸡山顶");
	set("long", @LONG
碧鸡山坐在滇池的西岸上，与拓东城隔水相望。山势高耸入云，
山形有如公鸡，漫山树木苍翠欲滴。此处乃是极顶，已达云端，东眺
滇池一片汪洋，美不胜收。山下属大理国的昆州。东西皆有下山之路。
LONG
        );

	set("exits", ([
		"eastdown" : __DIR__"minov19",
		"down" : __DIR__"qingxi",
		]));

	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 5);
	setup();
}
