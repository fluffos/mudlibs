// /d/mingjiao/jingqi.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIY"锐金旗"NOR);
       set("long", @LONG
这里是锐金旗所在地，明教的机关武器，都出自锐金旗之手。旗下弟子不
但武功卓越，更是一等一的暗器高手，屋内堆满各类兵器防具，正中央一只巨
大火炉，奇热难当，几个大汉正自滴汗挥锤。东西各有一条长廊。
LONG);    
	set("exits", ([
                "south" : __DIR__"zl7",
                "southeast" : __DIR__"rukou",
		"west" : __DIR__"shiwang",
		"east" : __DIR__"didao/senlin-6",
	]));             
	set("objects",([
		__DIR__"npc/dizi5"  :        3,
                CLASS_D("mingjiao") + "/zhuang" : 1,
	]));
        set("coor/x",-270);
  set("coor/y",220);
   set("coor/z",120);
   set("coor/x",-270);
 set("coor/y",220);
   set("coor/z",120);
   setup();
}
