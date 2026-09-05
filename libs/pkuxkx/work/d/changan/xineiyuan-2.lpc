
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "大安宫");
        set("long", @LONG
这是西内苑内的大安宫，玄武门之变以后相传是高祖李渊修养之所，
城北的龙首渠在西内苑蜿蜒流淌，北面瑶池水波荡漾。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"xineiyuan-3",
                "southdown" : __DIR__"xineiyuan-1"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();   
}