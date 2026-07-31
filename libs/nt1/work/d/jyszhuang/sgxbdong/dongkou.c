#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIY"上古神兵洞口"NOR);
        set("long", @LONG
这里是上古时代保存一个神秘洞穴入口，据说里面陈列着上古时代遗留下来的
神兵利器，洞中有些黑呀呀的，不知暗伏着什么机关。    
LONG );
        set("indoors", "city");
        set("exits", ([
        "north":   __DIR__"dong1",
        "south":   __DIR__"dong2",
        "west":    __DIR__"dong3",
        "east":    __DIR__"dong4",
        "out":    __DIR__"yongdao",  
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
        replace_program(ROOM);
}

