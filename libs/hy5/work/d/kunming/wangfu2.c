// /d/kunming/wangfu1
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "王府正厅" );
        set("long", @LONG
这里是王府正厅，正中两把太师椅，墙上挂着一幅字画，布置的
简单，清洁。这里空荡荡的没有一个人，看来平西王平时极少来这里
，只有几个下人不时来打扫一下。
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
                "south"    :__DIR__"wangfu1",         
                
        ]));
        set("objects",([
		"/d/beijing/npc/qinbing":4,
		]));
        setup();
	replace_program(ROOM);	       
}
	  		