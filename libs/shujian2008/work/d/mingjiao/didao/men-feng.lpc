// men-feng.c 风字门
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"风字门"NOR);
       set("long", @LONG
这是紫杉林外的风字门，插在正中央巨大的土坪上的是一面“风”字大旗。
几十名风字门释道家出家人正在埋头苦干，四周堆满了各式法器装备，风字门
门主正在一旁指导着他们。
LONG);    
	set("exits", ([
		"northwest" : __DIR__"senlin-"+(1+random(8)),	
		"southwest" : __DIR__"senlin-"+(1+random(8)),
                "southeast" : __DIR__"senlin-"+(1+random(8)),
                "northeast" : __DIR__"senlin-"+(1+random(8)),
	]));           
        set("objects",([
		"/d/mingjiao/npc/dizi10" : 1,
                "/d/mingjiao/npc/dizi8" : 2,
	]));  	
        set("outdoors", "明教光明顶");
        set("mj_xl", "tang");
        set("mj_xl2",5);
        set("coor/x",-240);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-240);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

#include "mj_xunluo.h";
