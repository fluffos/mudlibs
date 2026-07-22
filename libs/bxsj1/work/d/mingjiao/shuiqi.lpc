// shuiqi.c  洪水旗
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"洪水旗"NOR);
       set("long", @LONG
这里是洪水旗。此旗有十分厉害的水阵，旗中弟子个个深通水性。向东就
是通往碧水寒潭的山间小路了。
LONG);    
	set("exits", ([
		"west" : __DIR__"cl2",
                "east" : __DIR__"didao/senlin-8",		
		"north" : __DIR__"wu4",
		"eastdown" : __DIR__"shanlu1",
	]));             
	set("objects",([
		__DIR__"npc/dizi4"  : 3,
                CLASS_D("mingjiao") + "/tang" : 1,	
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-270);
  set("coor/y",190);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",190);
   set("coor/z",120);
   setup();
}
