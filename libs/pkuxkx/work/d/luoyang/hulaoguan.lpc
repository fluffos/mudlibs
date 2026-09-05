//洛阳，扩展地图
//by kiden
//2006-9-8
//Zine Oct 10 改名
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"虎牢关"NOR);
        set("long", @LONG
这里是洛阳东边门户和重要的关隘，因西周穆王在此牢虎而得名。其南连嵩
岳，北濒黄河，山岭交错，自成天险。大有“一夫当关，万夫莫开”之势，为历
代兵家必争之地。
LONG
        );

        set("exits", ([
               "southeast" : __DIR__"guandao2",
               "west" : __DIR__"guandao3",

        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
