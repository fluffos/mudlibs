// /d/kunming/xizoulang.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "西走廊" );
        set("long", @LONG
一条干净的走廊，从两面看去，可以欣赏到花园里的风景，只见
各种假山怪石，奇花异草，足见王府之气派。
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
		"west"   :__DIR__"shufan",
		"east"   :__DIR__"xizoulang"
                
        ]));

        set("objects",([
		__DIR__"npc/qinbing":4,
		__DIR__"npc/feng":1,
		]));
        setup();
	//replace_program(ROOM);	       
}
int valid_leave(object me, string dir)
{
	if ( dir == "west" && objectp(present("qin bing", environment(me))))
	   return notify_fail("亲兵拦住你说道：王府大院，闲杂人等一律回避。\n");
		
	if ( dir == "west" && objectp(present("feng xifan", environment(me))))
	   return notify_fail("冯锡范拦住你说道：王府大院，闲杂人等一律回避。\n");
		
        return ::valid_leave(me, dir);
}
	  		