//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"潼关"NOR);
        set("long", @LONG
这里是扼守关中门户的潼关了，雄踞晋、豫、秦三省，有“鸡鸣闻三
省，关门扼九州”之说。潼关北临涛涛黄河，南依巍巍秦岭，自古就是关
中的东大门，为兵家必争之地。
LONG
        );

        set("exits", ([
               "northwest" : __DIR__"guandaoe3",
               "east" : __DIR__"guandaoe4",
               //"south" : __DIR__"",

        ]));
        set("changan", 0); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        set("outdoors", "changan");
        setup();
        
}
