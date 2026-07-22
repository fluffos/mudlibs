// guangc.c 广场 
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"广场"NOR);
	set("long", @LONG
这是一个十分大的广场，它足于容下上千人，这里是当年张教主力拼六大
门派的地方，使得明教和六大门派之间的仇恨得以排除。这里平时可看到很多
的明教弟子在这练功。东西是通往练武场的走廊。
LONG);
	set("exits", ([
  	  "west" : __DIR__"zl1",
 	  "east" : __DIR__"zl2",
	  "south" : __DIR__"wu3",
	  "north" : __DIR__"wu1",
	]));
	set("objects",([
                CLASS_D("mingjiao") + "/wei" : 1,
                __DIR__"npc/m-dizi" : 1,
                __DIR__"npc/f-dizi" : 1,
	]));
        set("outdoors", "明教光明顶");
	set("coor/x",-290);
  set("coor/y",190);
   set("coor/z",120);
   set("coor/x",-290);
 set("coor/y",190);
   set("coor/z",120);
   setup();  
}

