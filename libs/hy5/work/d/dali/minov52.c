//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "山林");
	set("long", @LONG
你走在一片茂密的山林中，时而有飞禽走兽横过，百鸟在林间飞
鸣，南边乌夷部落里的村民经常来此狩猎。山林北面不远传来隆隆水
声，看来有大河流过，南边是一片低洼的河谷盆地，颇有人烟。
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov93",
		"southdown" : __DIR__"minov47",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
