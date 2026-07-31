 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "嵩岳寺");
        set("long", @LONG
嵩岳寺建造年代在北魏永平元年至正光元年，原名闲居寺，早先是北魏皇室
的一座离宫，后改建为佛寺。寺中有著名的嵩岳寺塔，为单层密檐式砖塔，由基
台、塔身、密檐和塔刹几部分构成，全塔共雕十六个狮子，有立有卧，正侧各异，
造型雄健，衬以绿树红墙，巍峨壮丽。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"shike",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}         
