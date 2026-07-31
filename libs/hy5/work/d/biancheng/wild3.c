 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "荒原");
        set("long", @LONG
秋风卷起满天黄沙，在无边无际的荒原上咆哮而过。临近小镇，来往的车马多
了，踏出一条三尺宽的车道，板结的地面上满是车辙划过的痕迹。偶尔几匹快马驰
过，奔向前方，马上骑者皆是行色匆匆，风尘仆仆，腰间鼓鼓囊囊，显见都携着兵
刃，密鼓般的蹄声，转瞬即逝。
LONG
        );
        set("exits", ([ 
        "southeast" : __DIR__"wild2",
        "west" : __DIR__"road2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
