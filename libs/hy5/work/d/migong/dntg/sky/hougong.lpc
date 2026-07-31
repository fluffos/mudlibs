// Room: /d/huanggong/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "后宫");
	set("long", @LONG
这是皇后的寝宫. 这里与前面皇上的乾清宫, 象征天地乾坤, 紫徵
正中. 坤宁意为大地安宁. 后宫的东西六院则象征十二星宿.
LONG
	);
	set("magicroom",1);set("exits", ([ /* sizeof() == 4 */
		 "west"  : __DIR__"hougong1",
		 "east"  : __DIR__"hougong2",
		 "south" : __DIR__"lingxiao",
		 "north" : __DIR__"yuhuayuan",
	]));
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/xiannu" : 2,
		__DIR__"npc/wangmu" : 1,	
	]));
set("no_npc",1);
	set("coor/x", -200);
	set("coor/y", 5310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}