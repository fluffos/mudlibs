// /d/kunming/wangfu1
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "王府大院" );
        set("long", @LONG
这里便是平西王府的大院，院内钟满了各钟花草，最显眼的却是中间的
一株万年山茶，巨大的树干上开满了无数的山茶花，颜色深浅不一，姹紫嫣
红，十分好看。
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
                "south"    :__DIR__"wangfu",
		"north"   :__DIR__"wangfu2",
		"west"   :__DIR__"xizoulang",
		"east"   :__DIR__"dongzoulang"
                
        ]));
        set("objects",([
		"/d/beijing/npc/qinbing":4,
		]));
        setup();
	replace_program(ROOM);	       
}
	  		