// jiaochang2.c 小校场
// seagate@pkuxkx 2010/10/22
#define __ZF_ROOM__

inherit ROOM;
void create()
{
        set("short", "小校场");
        set("long",
"这是大石板铺地的广场一角，是武当弟子学习武功和演习\n"
"阵法(zhenfa)的地点，不时有刚入门的弟子演习三才四象之类\n"
"粗浅的阵法，偶尔还能看见武当七侠演练著名的真武七截阵。\n"
        );
        set("outdoors", "wudang");
        set("exits", ([
          "east" : __DIR__"guangchang",
          "north" : __DIR__"jiaochang1",
          "south" : __DIR__"jiaochang3"
        ]));
        setup();
}

#include "/newbiequest/wudang/quest_zhenfa.h"