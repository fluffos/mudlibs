// lgf.c
// By River 98.08.29
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",HIY"练功房"NOR);
    set("long", @LONG
这是古墓内的一间石室。周围的火把将石室照的灯火通明，空旷的一间石
室，没有任何摆设。石壁上留有几个骇人的掌印，入石数分，显见是高手相交
所为。石室中央放着一个石人，供古墓弟子闲来练功所用。
LONG
        );

    set("exits", ([
	"south" : __DIR__"shitou",
    ]));

    set("objects", ([
           __DIR__"npc/shiren" : 1,
    ]));

    setup();
}
