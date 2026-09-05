
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "甘露殿");
        set("long", @LONG
这是皇帝读书和日常寝居的宫殿，西面是嫔妃居住的宫殿淑景殿，东面是
凌烟阁，里面放置着对大唐有功的大臣图像，以褒奖他们对大唐作出的贡献。
北面是太后的住所承香殿。
LONG    );
        
        set("exits", ([
                "north" : __DIR__"yanjiadian",
                "southup" : __DIR__"liangyidian",
                "west" : __DIR__"shujingdian",
                "east" : __DIR__"lingyange"
        ]));
        
        set("locate_level",2);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}