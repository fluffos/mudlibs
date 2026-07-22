// Room: /d/fuoshan/xijie2.c 
 
inherit ROOM; 
#include <wanted.h>
 
void create() 
{ 
	set("short", "佛山西街");
	set("long", @LONG
你走在青石板的街道上，这里显得比较安静，东面隐约传来阵阵喧哗
的声音，西面就是佛山的西门了。北面是一座建构宏伟的大神祠，正上方
挂着一块破旧的木牌，上书“北帝庙”。
LONG
	);
        set("outdoors","佛山");
	set("exits", ([
  "east" : __DIR__"xijie",
  "west" : __DIR__"ximen",
  "north" : __DIR__"beidimiao",
]));
	set("no_clean_up", 0);

	set("coor/x",-20);
  set("coor/y",-530);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
