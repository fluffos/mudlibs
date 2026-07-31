//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "竹林小路");
	set("long", @LONG
一条小路穿竹林而过，西南方竹林深处是一大片台夷人聚居的村
镇，东北可遥遥望见喜州城的城墙。道路两边竹林茂密，时有台夷人
来砍伐。
LONG
);

	set("exits", ([
		"northeast" : __DIR__"minov61",
		"southwest" : __DIR__"minov67",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
