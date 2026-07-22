// xiaolu1.c 林间小径
// by shang 97/6

inherit ROOM;
#include <ansi.h>
#include "xiaolu.h"

void create()
{
	set("short", GRN"小径"NOR);
	set("long", @LONG
你走在一条小径上，两旁种满了竹子，修篁森森，绿荫满地，除了竹叶声
和鸟鸣声，听不到别的动静。
LONG
	);
        set("outdoors", "武当");
        set("wdpass", 2);
	set("exits", ([
                "east" : __DIR__"xiaolu3",
                "west" : __DIR__"xiaolu5",
                "south" : __DIR__"xiaolu6",
                "north" : __FILE__,
	]));

        setup();
}
