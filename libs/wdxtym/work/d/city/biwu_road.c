#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_look(string arg);

void create()
{
    set("short", HIY"演武走廊"NOR);
    set("long", @LONG
这是一个很短的走廊，侧门通向演武休息室，从大门进来直走，
就是著名的演武大厅。
LONG );

    set("no_fight",1);
    set("no_beg",1);
    set("no_steal",1);
    set("biwu_room",1);

    set("exits", ([
        "west"  : __DIR__"biwu_restroom",
        "south" : __DIR__"wudao1",
        "north" : __DIR__"biwu_dating",
    ]));

    set("no_clean_up", 0);
    setup();
}