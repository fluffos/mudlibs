#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "山阁");
        set("long", @LONG
小阁顶有八角，外观如亭，只是四面门窗紧闭。雕花窗棂间，蒙有淡黄色
的绡纱，八角飞檐下，挂有黄金的响铃，随风而动，与飞瀑流泉争鸣。蔓草、
青松、飞瀑、藤萝间，建筑这座精致玲珑，黄金为顶，白玉为阶的小小楼阁，
望之当真有如天上。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"sriver",
  "south" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/feiyu" : 1,
        __DIR__"npc/s_wushi" : 2,
                        ]) ); 
        set("outdoors","palace");
        create_door("south", "黄金门", "north", DOOR_CLOSED);
        set("coor/x",250);
        set("coor/y",-70);
        set("coor/z",10);
        setup();
}        
