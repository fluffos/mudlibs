
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "含元殿");
        set("long", @LONG
这是高大雄伟的含元殿，为每月朔望两日大朝皇帝会见群臣，
视朝听政的场所，每逢国家大典也在这里举行。北面就是皇帝日常
办公的场所宣政殿。
LONG        );
        
        set("exits", ([
                "north" : __DIR__"xuanzhengdian",
                "southdown" : __DIR__"dfguangchang",
                "southeast" : __DIR__"chaotang-1",
                "southwest" : __DIR__"chaotang-2"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}