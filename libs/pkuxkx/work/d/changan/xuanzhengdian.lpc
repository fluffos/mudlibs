
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "宣政殿");
        set("long", @LONG
这是皇帝日常办公的场所，左右设有中书省、御史台、门下省、弘文馆、史馆等
常设机构，是皇帝和百官日常讨论国家大事的重要宫殿。北面是内廷紫宸殿。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"hanyuandian",
                "north" : __DIR__"zichendian",
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();
}