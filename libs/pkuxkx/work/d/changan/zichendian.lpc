
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "紫宸殿");
        set("long", @LONG
这是内廷便殿紫宸殿，北面紧邻皇帝和宫妃生活的场所太液池畔宫殿
群，只有皇帝亲信阁僚才有资格在紫宸殿入阁觐见。东西两边通往东内苑
和西内苑，东北面是皇帝寝宫蓬莱殿，西北面是皇帝举行宴会的场所麟德
殿。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"xuanzhengdian",
                "northeast" : __DIR__"penglaidian",
                "northwest" : __DIR__"lindedian",
                "west" : __DIR__"yintaimen-2",
                "east" : __DIR__"yintaimen-1",
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}