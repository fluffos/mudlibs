//Create by jason@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "秘密仓库");
        set("long", @LONG
这里是铁掌帮的秘密仓库，存放着很多物资，
LONG    );
        set("exits", ([ 
        "west": __DIR__"pingdi"
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        set("objects",([
            __DIR__"obj/zhentianlei":(random(2)+1),
        ]));
        setup();
        replace_program(ROOM);
}