// 小山坡
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
void create()
{
	set("short", HIG"小山坡"NOR);
	set("long", @LONG
这是一片小山坡，绿意盎然。几只小山羊在悠闲地啃着草。
LONG
	);
    set("normaldesc", @LONG
这是一片小山坡，绿意盎然。几只小山羊在悠闲地啃着草。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"grass",
        "westdown" : __DIR__"grass7",
        "northdown" : __DIR__"grass1",
        "eastdown" : __DIR__"grass4",
        
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([(__DIR__"npc/rabbit") : 2,
    ]));
	setup();
	::create();
}

