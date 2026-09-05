// Room: /d/beijing/gulou.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"鼓楼"NOR);
        set("long",
CYN"京城鼓楼每到定更天时分便会开始打鼓，叫做“交更”，
平民百姓听见鼓楼鼓声，便知道时刻了。鼓楼西面就是出名
繁华的鼓楼大街，东边是热闹的东直门大街。\n"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"dianmen",
        "west" : __DIR__"guloudajie_w",
        "north" : __DIR__"zhonglou",
        "east" : __DIR__"guloudajie_e",
        "up" : __DIR__"gulou2",
        ]));

        set("outdoors", "beijing");

        setup();
        replace_program(ROOM);
}
