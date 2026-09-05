
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "含光殿");
        set("long", @LONG
这是皇族平日里提马球的场所，平日里不时看见一些皇族子弟
在这里练习马球，有时候皇帝也会过来踢几下马球，东边有一个小
门通往大明宫。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"yintaimen-2",
                "south" : __DIR__"xineiyuan-3"
        ]));
        
        set("locate_level",3);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}