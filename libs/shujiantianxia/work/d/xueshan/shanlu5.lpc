// Room: shanlu5.c

inherit ROOM;

void create()
{
	set("short", "雪积古道");
	set("long", @LONG
  天，阴郁，铅灰而低沉。
  雪，漫天，狂风迷人眼。
  左侧是万丈的高崖，陡峭不见顶；
  右侧是不测的山谷，深邃不见底。
  小径，上雪山必经之路。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu6",
		"southwest" : __DIR__"xuelingquan",
	]));
        set("outdoors", "雪山");
        set("objects", ([
         __DIR__"npc/xuebao" : 1,
        ]));
	set("coor/x",-290);
  set("coor/y",170);
   set("coor/z",20);
   setup();
}
