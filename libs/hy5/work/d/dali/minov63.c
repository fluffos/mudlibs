//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条贯通南北的大路，是由大理城往南边疆土的官道。沿路向南
丛林愈发茂密，大片雨林覆盖山岭，此间地势较平坦，大路笔直地连
接着北边的大理城和南边的喜州等城镇。
LONG
        );

	set("exits", ([
		"north" : __DIR__"shqiao",
		"south" : __DIR__"minov62",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
