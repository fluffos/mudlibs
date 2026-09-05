// D:\xkx\d\liuxiu-shanzhuang\xingzilin.c杏子林
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
    set("short", "杏子林");
    set("long", @LONG
一阵风来，正是“风过吹斜阳”的景。杏叶已成片泛黄，整个杏子
林，像是泼洒上一片橙橙的黄墨。你不难想到，如果时逢春风小
渡，杏花醉红，成片成片的杏花海，是怎样的景象，夏日又会是
怎样绿树成荫的繁茂。此时的枯黄，大概正是英雄迟暮的景了。
若是你细心看去，一些杏树下有一些零散的脚印(yin)。
杏林中有一条因马车常年驶过而留下的车辙痕迹，向西延伸通向
扬州。而这些车辙印记则来自于杏子林南边的车马行。
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
        "east" : __DIR__"jizhen-xiaodao1",
        "south" : __DIR__"chemahang",
        ])
     );

    setup();
}

void init()
{
	add_action("show_quest","quest");
}
