// Room: jushuimen.c

inherit ROOM;

void create()
{
	set("short", "巨水门");
	set("long", @LONG
这里是吐蕃国皇城的北门，吐蕃是边陲小国，但历年重视军备城防，城墙修
筑得坚实高阔，比起中原重镇来竟也毫不逊色。出了城门就是天云马场了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"tianyunmc",
		"south" : __DIR__"jiedao3",
	]));
        set("outdoors", "雪山");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));
	set("coor/x",-220);
  set("coor/y",140);
   set("coor/z",0);
   setup();
}
