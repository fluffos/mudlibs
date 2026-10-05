#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "山道");
    set("long", @LONG
这是一条曲径悠远的羊肠小道,两边的峭壁象用刀削过一样.
远处还不时的传来野兽的各种叫声.
LONG );

    set("exits", ([
        "west" : __DIR__"shandao1",
        "east" : __DIR__"buliechang1",
    ]));
    setup();
    replace_program(ROOM); 
}
