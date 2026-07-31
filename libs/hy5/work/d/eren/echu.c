 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "和阗河");
        set("long", @LONG
穿过沙漠，便到了塞北之地。和阗河滚滚的河水，在六月的残阳下发着光。到
了上游，河水双分，西面的一支便是玉龙哈什河，水流处地势更见崎岖险峻，激起
了奔腾的浪花。和阗河的一侧有一个小小的集市，原先只是个驿站，歇脚的人多了，
渐渐就开起了几家店铺。
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"kunlun1",
//        "southeast" : __DIR__"yangguan2",
//        "southwest": "/d/taiping/mroad1",
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
