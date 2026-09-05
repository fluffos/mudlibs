
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "两仪门");
        set("long", @LONG
这是前朝和内廷的分界点两仪门，后面就是皇帝和后妃生活的宫殿。
南面是大臣办公和皇帝面见群臣的地方。
LONG        );
        
        set("exits", ([
                "northup" : __DIR__"liangyidian",
                "southup" : __DIR__"taijidian"
        ]));
        
        set("locate_level",2);
        
        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}