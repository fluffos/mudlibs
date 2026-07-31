// Room: /d/linzhi/lin69.c

inherit ROOM;

void create()
{
	set("short", "高原杂道");
	set("long", @LONG
你走到桃花沟西口，再向东去就进了桃花沟。那里长满了天
然的野生桃树，每年八月时，很多人都来这里采摘桃子。据说味
道特别的好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin48",

]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
