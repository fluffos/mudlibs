// Room: shanya.c
#include <ansi.h>
inherit ROOM;
int do_open(string arg);

void create()
{
        set("short","山崖");
        set("long",
"映照在阳光白云之间的，是一座巍峨之极的大城。只见城墙
高逾三丈，墙头墙垣雪白一片，尽是冰雪。城墙上隐隐有人头晃
动，城头树着一面在罡风中招展的大旗，上面写着三个大字："HIW"
                      凌霄城"NOR"
城门前有一张厚厚的吊桥（bridge），正紧紧关闭着。如果想要
进入的话，必须要请人开（open）才行。\n");
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"cityout",
            "west"  : __DIR__"cityout1",
            "down"  : __DIR__"bingti",
        ]));
        if(random(6)>3)
        set("objects", ([
                "/quest/skills2/wakuang/kuang/kuangmai" : 2,
        ])); 

        set("item_desc", ([
        "diaoqiao": "一张极大的吊桥,是凌霄城守城的一道防线。\n"
        ]) );
        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me=this_player();

        if( !arg || arg != "bridge" ) {
                return notify_fail("你乱叫什么？\n");
        }

       message_vision("$N运足力气,大叫一声:'开门呀'，\n",this_player());
       message_vision("只听得城上有人说道:'有人来了,放吊桥吧'。只听得轧轧声响，吊桥缓缓放下,露出一个方方正正的城门来。\n", this_player());
        set("exits/north", __DIR__"gate");
        remove_call_out("close");
        call_out("close", 10, this_object());

        return 1;
}

void close(object room)
{
        message("vision","吊桥又'嘎嘎'地升了起来,把城门挡住了。\n", room);
        room->delete("exits/north");
}

