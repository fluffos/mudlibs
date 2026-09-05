// room: baokurukou.c
// Made By:pingpang
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string);
int look_tai(object);

void create()
{
        set("short", YEL"宝库入口"NOR);
        set("long", @LONG
这里通向宝库,里面有一扇门(men)，但已被坍塌的砖瓦挡住
了。
LONG
        );

        set("exits", ([
                "west" : __DIR__"mihun"+random(8),
        ]));

        set("item_desc", ([
                "men" : "这扇门已被挡住无法通行，除非你打破(break)它。\n",
        ]) );
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
                write("不要随便打碎别人的东西！\n");
                return 1;
        }


        message_vision(
        "$N走到门前，深吸一口气，双掌同时发力，一股气流在手掌中流动。\n", this_player());
        
        if (n>=300) {
        message_vision(
        "$N只听一声震响，$N把门震开了！\n", this_player());
        set("exits/south", __DIR__"baoku");
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
        room->delete("exits/south");
}

