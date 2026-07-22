// Room: /dali/nanmen.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "南门");
	set("long", @LONG
这是大理南城门，城楼建在高高的城台上，分上下两层，站在上面一看北
边就是大理繁华的街市，一条石板大道向南边延伸，远处是群山，不知通往哪
里,城墙下的武将和官兵正在检查着来往的行人。
LONG
	);

	set("exits", ([
		"south" : __DIR__"dalisouth/shanlu6",
		"north" : __DIR__"nanjie3",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "大理");

	setup();
}
