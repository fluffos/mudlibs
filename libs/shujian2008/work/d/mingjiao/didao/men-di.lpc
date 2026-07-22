// men-di.c 地字门
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"地字门"NOR);
       set("long", @LONG
这是紫杉林外的地字门，插在正中央巨大的土坪上的是一面“地”字大旗。
几十名地字门中原女子教众正在埋头苦干，四周堆满了各式衣物装备，地字门
门主正在一旁指导着她们。
LONG);    
	set("exits", ([
		"northwest" : __DIR__"senlin-"+(1+random(8)),	
		"southwest" : __DIR__"senlin-"+(1+random(8)),
                "southeast" : __DIR__"senlin-"+(1+random(8)),
                "northeast" : __DIR__"senlin-"+(1+random(8)),
	]));           
        set("objects",([
		"/d/mingjiao/npc/dizi10" : 1,
                "/d/mingjiao/npc/dizi7" : 2,
	]));  	
        set("outdoors", "明教光明顶");
        set("mj_xl", "xin");
        set("mj_xl2",4);
        set("coor/x",-250);
  set("coor/y",210);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",210);
   set("coor/z",120);
   setup();
}

#include "mj_xunluo.h";
