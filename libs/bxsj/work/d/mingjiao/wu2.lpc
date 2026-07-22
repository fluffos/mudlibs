// wu2.c 练武场
// Modify By River@SJ 99.06
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short",CYN"练武场"NOR);
       set("long", @LONG
这里是明教的练武场。地面是坚硬结实的黄土，已有百多年的践踢使得地
面光滑平整。练武场中间竖立着不少用来练暗器的木靶。很多明教教众正在练
习武艺。东面是一条走廊。
LONG);    
	set("exits", ([
                "south" : __DIR__"huoqi",
                "north" : __DIR__"zl6",
		"east" : __DIR__"zl1",
	])); 
	set("objects",([
		__DIR__"npc/m-dizi" : 1,
		__DIR__"npc/f-dizi" : 1,
	]));            
        set("outdoors", "明教光明顶");
        set("coor/x",-250);
  set("coor/y",240);
   set("coor/z",120);
   set("coor/x",-250);
 set("coor/y",240);
   set("coor/z",120);
   setup();
}
