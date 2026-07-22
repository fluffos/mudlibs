// Room: /d/city/mingyufang.c

inherit ROOM;

void create()
{
	set("short", "鸣玉坊");
	set("long", @LONG
这便是扬州城里妓院最集中的鸣玉坊了，因为座落在瘦西湖边，所以往来
的游人、嫖客络绎不绝。南面是扬州的西大街，北面是一座大院子。
LONG
	);

	set("exits", ([
                "north" : __DIR__"lichunyuan",
                "south" : __DIR__"xidajie3",
	]));

/*	set("objects", ([
                __DIR__"npc/yanxiao" : 1,
	]));*/

	set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",10);
   set("coor/z",0);
   set("incity",1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("hooker") && dir == "south")
        return notify_fail("你已经是丽春院的人了，不可以随便上街。\n");
        return ::valid_leave(me, dir);
}
