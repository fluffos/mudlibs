// muqi.c  巨木旗
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIG"巨木旗"NOR);
       set("long", @LONG
这里是巨木旗的所在地。这里放着各种各样的砍伐工具和一根根的大树木，
在南面有几条竖起的木大木桩，上面有许多被掌击过的痕迹，为旗中弟子平时
练功之用。旗中不但有许多力大如牛的武林高手，更有许多能工巧匠。光明顶
的宏大的建筑就是出自本旗之手。因为光明顶处在高出，所以这里是光明顶的
第一道防线，当真有一夫当关万夫莫开之势。两面是一片阴森的大树林。
LONG);    
	set("exits", ([
		"west" : __DIR__"didao/shuling1",
		"east" : __DIR__"didao/shuling2",
                "northup" : __DIR__"gmd",
                "south" : __DIR__"tingtang",
	]));             
	set("objects", ([
		__DIR__"npc/dizi1" : 3,
                CLASS_D("mingjiao") + "/wen" : 1,
	]));

        set("coor/x",-290);
  set("coor/y",160);
   set("coor/z",100);
   set("coor/x",-290);
 set("coor/y",160);
   set("coor/z",100);
   setup();
}
