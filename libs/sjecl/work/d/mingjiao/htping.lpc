// htping.c  黄土坪
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",YEL"黄土坪"NOR);
       set("long", @LONG
这是一片较大的黄土坪。周围只有几株已干枯的古树和黄沙。可以看出这
里以前曾是绿洲，东边是一个个小沙丘。
LONG);    
	set("exits", ([
		"southeast" : __DIR__"shaqiu4",
		"east" : __DIR__"shaqiu"+(random(3)+1),
		"west" : __DIR__"dashaqiu",
                "south" : __DIR__"shaqiu"+(random(3)+1),
	]));             
	set("objects",([
                CLASS_D("mingjiao") + "/wufu" : 1,
                __DIR__"npc/m-dizi" : 1,
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-320);
  set("coor/y",90);
   set("coor/z",0);
   set("coor/x",-320);
 set("coor/y",90);
   set("coor/z",0);
   setup();
}
