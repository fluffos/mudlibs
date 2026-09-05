//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "北大街");
        set("long", @LONG
这里是洛阳内城最整洁的一条大路，街道宽敞而干净，汉白玉砌的路
面被雨水冲得光明如镜，大路两侧的瓦房高大而宏伟，分明便是巨富宅院。
双人合抱的杨树十步一株，整齐的排在两边。西边是一家水果店，东边则
是一家花店，专门出售洛阳牡丹。
LONG
        );
        set("item_desc", ([
        ]) );

        set("exits", ([
               "north" : __DIR__"beimen",
               "south" : __DIR__"beidajie1",
               "west" : __DIR__"shuiguodian",
               "east" : __DIR__"huadian",           
        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc3" : 1,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

