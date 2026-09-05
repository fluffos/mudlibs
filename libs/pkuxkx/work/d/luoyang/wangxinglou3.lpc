//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"望"HIY"星"HIC"楼三层"NOR);
        set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃
喝边作交易。这里也是城里举办喜宴的最佳场所。你站在楼上眺望，只觉
得心旷神怡。西面是一池湖水，碧波荡漾，北面则是崇山峻岭，气势雄浑，
巍峨壮观。
LONG
        );

        set("exits", ([
               "down" : __DIR__"wangxinglou2",    
               "up" : __DIR__"wangxinglou4",          
        ]));
        set("objects", ([

        "/d/city/npc/bookseller":1,
        ]));

        setup();
        replace_program(ROOM);
}

