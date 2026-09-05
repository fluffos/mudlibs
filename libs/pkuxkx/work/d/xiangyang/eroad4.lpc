#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long",
	CYN"走着走着，两旁的树木突然多起来，都是北方常见的榆树，杨树之类。
   越往前走越密，渐渐高大的松柏多起来，阳光显得弱了，山风吹来，松涛滚滚
   忽然一声长啸，一股腥风迎面扑来，你机灵灵打了个冷战。\n" + RED"      有老虎!"NOR + "\n"

    	);
       	set("objects", ([
		__DIR__"npc/tiger" : 1,
        ]));
	set("exits", ([
		"eastdown" : __DIR__"eroad5",
		"westdown" : __DIR__"eroad3"          
	]));
	setup();
}

