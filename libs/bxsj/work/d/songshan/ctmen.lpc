// Room: /u/swl/songshan/ctmen.c

inherit ROOM;

void create()
{
	set("short", "朝天门");
	set("long", @LONG
走到这里，双峰中断，天然现出一个门户，疾风从断绝处吹出，云
雾随风扑面而至。
LONG);
	set("exits", ([ 
            "southeast" : __DIR__"shanlu4",
            "northeast" : __DIR__"shanlu5",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/lu" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("outdoors", "嵩山");
	set("coor/x",30);
  set("coor/y",230);
   set("coor/z",100);
   setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northeast")
               me->receive_damage("jingli", 10);
       return 1;
}


