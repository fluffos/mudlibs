// Room: fozhaomen.c

inherit ROOM;

void create()
{
	set("short", "佛照门");
	set("long", @LONG
这里是吐蕃国皇城的西门，吐蕃是边陲小国，但历年重视军备城防，城墙修
筑得坚实高阔，比起中原重镇来竟也毫不逊色。出了城门是通向大雪山的道路。
LONG
	);

	set("exits", ([
		"east" : __DIR__"zanpugc",
		"west" : __DIR__"xiaolu3",
	]));
        set("outdoors", "雪山");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));

	set("coor/x",-230);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
