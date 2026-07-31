// shanlu2.c  山间小路
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","山间小路");
       set("long", @LONG
这是一条曲曲折折的山间小路。地势较为平坦。但林木高耸云间，又别有
一番阴森可怕。两边的林木笔直的生长着，很有规律，树梢间积着十分厚的积
雪，其景十分壮观。东面就是明教著名的碧水寒潭了。
LONG);    
	set("exits", ([
		"east" : __DIR__"bishui",	
		"westup" : __DIR__"shanlu1",				
	]));             
	set("objects",([
		__DIR__"npc/dizi4" :  2,
	]));
        set("outdoors", "明教光明顶");
        set("coor/x",-250);
  set("coor/y",190);
   set("coor/z",100);
   set("coor/x",-250);
 set("coor/y",190);
   set("coor/z",100);
   setup();
}

