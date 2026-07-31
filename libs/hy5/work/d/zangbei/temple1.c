 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "冲古寺");
        set("long", @LONG
冲古寺位于仙乃日雪峰脚下，隶属贡嘎郎吉岭寺，根戈活佛派有扎巴在此念经
颂佛，小经堂内供有泥塑释迦。寺内终年香火茂盛，据藏经上说，在冲古寺转十五
次经相当于念一亿嘛呢的功德，所以就连附近的山上的土匪也会来这里转山转寺，
赎自己犯下的罪恶。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"tianxin",
                "south":  __DIR__"zhayi",
                "northeast": __DIR__"temple1a",
        ]));
        set("objects", ([
                __DIR__"npc/monk1":     1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}      
