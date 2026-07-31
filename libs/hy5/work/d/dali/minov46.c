//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "易溪部");
	set("long", @LONG
易溪部也是乌夷族乌杂蛮的部落。这里处半坡地，附近有不少农
田，但农业落后，需要换季轮耕，因而村民经常迁徙，镇子里除了祭
祀大屋外，其它房屋都很简陋。
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov45",
		"east" : __DIR__"minov54",
		"south" : __DIR__"minov55",
		]));

	set("objects", ([
		__DIR__"npc/wygirl.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
