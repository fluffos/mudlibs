// shaqiu2.c  小沙丘
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
       set("short",YEL"小沙丘"NOR);
       set("long", @LONG
这是一个堆满黄沙的小沙丘。你一踏上来就迷失了方向。看来要走出这块
沙漠并非易事。
LONG);
	set("exits", ([
		"east" : __DIR__"shaqiu1",
		"west" : __DIR__"shaqiu3",
		"south" : __DIR__"shaqiu"+(random(3)+1),
		"north" : __DIR__"shaqiu"+(random(3)+1),
	]));
        set("outdoors", "明教光明顶");
	set("coor/x",-300);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}
