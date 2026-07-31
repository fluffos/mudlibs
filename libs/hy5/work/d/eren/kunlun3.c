 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "昆仑山区");
        set("long", @LONG
再往前走，道路愈为荒凉，行人愈渐稀少起来。偶尔还能见到倒毙的驮马，更
增添了几分肃杀之气。海拔也由二千米急骤上升到四千多米，气温、气压随之降低。
一时间，似乎从酷夏突然进入到严冬。远远望去，玉龙峰笼罩在云雾之中。
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"yuzhu",
        "east" : __DIR__"kunlun2",
        ]));
        set("objects", ([
                __DIR__"obj/mache": 1,
        ]) );
        set("outdoors", "eren");
        set("coor/x",-1010);
        set("coor/y",140);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
