inherit ROOM;

void create()
{
        set("short", "渡口路");
        set("long", @LONG
这里向南是通往中州城的大道，向北是渡口。通过渡口可
以到达江北的扬州，这是连接南北的要道。
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"to_zhongzhou",
  		"north" : __DIR__"zhongzhoudu",
	]));
        set("outdoors", "zhongzhou");
        set("objects", ([
  		__DIR__"npc/boy1" : 1,
  		__DIR__"npc/girl2" : 1,
	]));
        set("no_sleep_room", 1);

        set("coor/x", -230);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
