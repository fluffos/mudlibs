// D:\xkx\d\liuxiu-shanzhuang\yangui-huayuan.c岩桂花园
// labaz  2012/10/22
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", HIM"岩桂花园"NOR);
    set("long", @LONG
柳秀山庄的岩桂花园可谓一处胜景。园内主要种植了岩桂花。海棠和
茶花也点缀其间，海棠和茶花的味道均淡雅不馥的品类，所以四周全是岩
桂花的香气。各类花开得并不十分繁盛，甚至在春日也不繁茂。但那一段
段断断续续，若有若无的花香却是四时飘散弥漫在整个山庄。
LONG);

    set("indoors","liuxiu-shanzhuang");

    set("exits", ([
        "north" : __DIR__"zhengting",
        "south" : __DIR__"changlang",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest","quest");
}
