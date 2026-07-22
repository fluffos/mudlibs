// /d/mingjiao/zhoulang7.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIC"长廊"NOR);
       set("long", @LONG
这是一条走廊。一边是青砖墙壁，另一边是古木雕成的围栏虽是普通过道，
却也隐射出江湖第一大教制端严。南边是练武场，北面通往锐金旗，东南边是
教内监狱入口。
LONG);    
	set("exits", ([		
		"south" : __DIR__"wu4",				
		"north" : __DIR__"jinqi",
		"northeast" : __DIR__"rukou",
	]));             
	set("objects",([
                CLASS_D("mingjiao") + "/peng" : 1,
	]));    
        set("outdoors", "明教光明顶");     
        set("coor/x",-270);
  set("coor/y",210);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",210);
   set("coor/z",120);
   setup();
}
