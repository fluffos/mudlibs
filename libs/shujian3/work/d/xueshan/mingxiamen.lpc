// Room: mingxiamen.c

inherit ROOM;

void create()
{
	set("short", "明霞门");
	set("long", @LONG
这里是吐蕃国皇城的南门，吐蕃是边陲小国，但历年重视军备城防，城墙修
筑得坚实高阔，比起中原重镇来竟也毫不逊色。此刻城门吊桥落下，由城门洞下
经过的行人熙熙攘攘，看形貌服色大多是在附近聚居的少数民族。
LONG
	);

	set("exits", ([
        "north" : __DIR__"jiedao1",
        "east" : __DIR__"tulu3",
	]));
        set("outdoors", "雪山");
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/wujiang" : 1,
			 __DIR__"npc/bing" : 2,]));

	set("coor/x",-220);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}
