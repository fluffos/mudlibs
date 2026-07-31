// yuanzi.c 小院子
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","小院子");
       set("long", @LONG
这是一所小院子。你一进来这里这闻到一股强烈的花香，只见院子培植长
着许多名贵的花草。西面则是一座厢房。
LONG);    
	set("exits", ([
		"southeast" : __DIR__"longwang",				
		"west" : __DIR__"wxiang",
	]));             
        set("objects",([
		__DIR__"npc/yahuan" : 1,
                __DIR__"npc/xtong" : 1,
	]));   
        set("outdoors", "明教光明顶");
        set("coor/x",-250);
  set("coor/y",270);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",270);
   set("coor/z",120);
   setup();
}
