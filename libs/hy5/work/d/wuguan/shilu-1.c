//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，从这里往东是物品房，你看见有不少人
手里拿着各样的工具，从那边过来，西面是武馆大厅。
LONG);
	set("exits", ([
	      "east" : __DIR__"wupinfang",
	      "westup" : __DIR__"dating",
              "north" : __DIR__"xuetang",
              "south" : __DIR__"zhangfang",
        ]));
        set("objects", ([
           __DIR__"npc/xiaojh" : 1,
        ]));
	set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

