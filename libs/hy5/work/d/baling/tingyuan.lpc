
inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
这里是一个宽敞的大院，院内干干净净，虽然谈不上奢华，但是一
眼也能看出来是一个大户人家。
LONG);

	set("exits", ([
                "west" : __DIR__"xiangfang1",
                "east" : __DIR__"xiangfang2",
                "south" : __DIR__"xiangfang3",
                "southeast" : __DIR__"houyuan",
                "north" : __DIR__"haozai",
	]));

 	set("outdoors", "baling");
      /*  set("objects", ([
		__DIR__"npc/jiading":2,
	]));*/
	setup();
	replace_program(ROOM);
}


