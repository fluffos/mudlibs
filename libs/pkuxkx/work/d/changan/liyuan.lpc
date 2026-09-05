
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "梨园");
        set("long", @LONG
在一片梨花中树立着几栋特异的亭台楼榭，园中不时
看见久负盛名的演奏家、诗人、画家，是整个帝国最高水
准的皇家艺术中心。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"taiye-2"
        ]));
        
        set("locate_level",3);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}