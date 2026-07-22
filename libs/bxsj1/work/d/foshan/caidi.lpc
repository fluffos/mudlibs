// Room: caidi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "菜地");
        set("long", @LONG
这块菜地位于凤天南的豪宅旁，站在这里，凤府的巍阁雕墙，举目可
见。菜地中萝卜白菜长得甚为肥美，菜畦旁丢着一顶小孩帽子，一个粗陶
娃娃。西边是一扇木门(door)。
LONG
        );
        set("outdoors","佛山");
        set("exits", ([
            "west" :  __DIR__"zhongjia",
        ]));

        set("item_desc", ([
            "door" : "这是一扇破旧的木门。\n",
]));

        create_door("west", "木门", "east", DOOR_CLOSED);
        set("coor/x",20);
  set("coor/y",-570);
   set("coor/z",0);
   setup();
}
