// /d/mingjiao/zhoulang6.c
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
却也隐射出江湖第一大教制端严。南边是练武场，北面通往厚土旗。
LONG);    
	set("exits", ([		
                "north" : __DIR__"tuqi",
		"south" : __DIR__"wu2",
	]));
        set("objects",([
                CLASS_D("mingjiao") + "/shuo" : 1,
	])); 
        set("outdoors", "明教光明顶");         
        set("coor/x",-250);
  set("coor/y",250);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",250);
   set("coor/z",120);
   setup();
}
