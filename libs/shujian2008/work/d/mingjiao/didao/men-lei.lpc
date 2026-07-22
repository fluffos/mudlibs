// men-lei.c 雷字门
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIW"雷字门"NOR);
       set("long", @LONG
这是紫杉林外的雷字门，插在正中央巨大的土坪上的是一面“雷”字大旗。
几十名雷字门西域番邦教众正在埋头苦干，四周堆满了各式武器装备，雷字门
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
                "/d/mingjiao/npc/dizi9" : 2,
	]));  	
        set("outdoors", "明教光明顶");
        set("mj_xl", "zhuang");
        set("mj_xl2",6);
        set("coor/x",-260);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-260);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}

#include "mj_xunluo.h";
