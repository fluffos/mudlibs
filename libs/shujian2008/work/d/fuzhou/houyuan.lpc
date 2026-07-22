// room: houyuan.c
// Lklv 2001.9.10

#include <room.h>

inherit ROOM;
int do_break(string);

void create()
{
        set("short", "老宅后院");
        set("long", @LONG
这里是向阳老宅的后院。满地是发出朽烂霉气的落叶。院子的中央有一口
井，井台上刻着些字。院子北面有一扇门(men)，但已被坍塌的砖瓦挡住了。
LONG
        );

        set("exits", ([
                "down" : __DIR__"well",
        ]));

        set("item_desc", ([
                "men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
        ]));
	setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        int n;
        n = this_player()->query("neili");
        if( !arg || arg!="men" ) {
                write("不要随随便便就砸碎别人的东西！\n"); // by pishou
                return 1;
        }


        message_vision(
        "$N走到后门前，拜出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", this_player());

        if (n>=500) {
        message_vision(
        "$N只听一声轰响，$N把门震开了！\n", this_player());
        set("exits/north", __DIR__"laozhai");
        this_player()->set("neili",n-500);
        remove_call_out("close");
        call_out("close", 5, this_object());
        }
        else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
        }

        return 1;
}

void close(object room)
{
        message("vision","门上的砖头瓦块稀里花拉坍塌下来，又挡住了小门。\n", room);
        room->delete("exits/north");
}
