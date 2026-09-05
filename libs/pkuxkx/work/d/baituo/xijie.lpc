//xijie.c
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "西街");
        set("long",
             "这里是小镇的西街。北边有一家酒店，店门前树立着高高的旗杆，\n"
         "一块青布酒幌子迎风飘扬，上面写着一个朱红色斗大的‘"RED"酒"NOR"’字。\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "west" : __DIR__"bridge",
                "east" : __DIR__"dongjie",
                "north" : __DIR__"jiudian",
        ]));
        set("objects",([
                __DIR__"npc/man" : 1,
                __DIR__"npc/snaker"  :1,
        ]));
        setup();
        replace_program(ROOM);
}
