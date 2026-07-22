// tingtang.c 厅堂
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"厅堂"NOR);
       set("long", @LONG
这是一个很大厅堂，是明教接待外来宾客之地。厅堂的周围放着几张古木
所造的家具，正前方放着一张大师椅，是教主接待宾客的座位，四周站着几个
小丫环，专为客人送茶水。
LONG);    
	set("exits", ([
       		"east" : __DIR__"xiangfang",
		"west" : __DIR__"tearoom",	
                "north" : __DIR__"muqi",
                "south" : __DIR__"qianting",			
	]));             
	set("objects",([
		__DIR__"npc/yahuan" : 1,
                __DIR__"npc/xtong" : 1,
	]));
        set("coor/x",-290);
  set("coor/y",150);
   set("coor/z",100);
   set("coor/x",-290);
 set("coor/y",150);
   set("coor/z",100);
   setup();
}
