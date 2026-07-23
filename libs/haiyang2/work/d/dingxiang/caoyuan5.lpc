// Room in 碎叶

#include <room.h>
#include <ansi.h>


inherit ROOM;
void create()
{
        set("short", "大草原");
        set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还
真不好走，看来买匹马来代步到是的好主意。
LONG);
        set("exits", ([
            "south" : __DIR__"road1",
            "west" : __DIR__"caoyuan4",
            "east" : __DIR__"caoyuan4",
            "north" : __DIR__"caoyuan4",
        ]));
        set("outdoors", "dingxiang");
        setup();
        replace_program(ROOM);
}
