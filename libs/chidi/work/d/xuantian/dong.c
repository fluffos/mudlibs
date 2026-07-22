//xuantian/dong
//by pipip
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "石洞");
    set("long", @LONG
这里是一个天然的石洞，到处长满了钟乳石(shi)，
你看着这天然的奇景，不由觉得大自然的魅力之大。
简直无所不在，无所不包。
LONG
    );
    set("exits", ([
        "south" : "d/xuantian/room6",
        "east" : "d/xuantian/room2",
        "west" : "d/xuantian/room4",
    ]));
    set("item_desc", ([
        "shi": "很光滑的钟乳石，你用手一推，竟然可以推动。\n"
    ]) );
    setup();
}
void init()
{
    add_action("do_push", "push");
}
void check_trigger()
{
    object room;
    if( (int)query("left_trigger")==16
        &&  (int)query("right_trigger")==24
    &&  !query("exits/north") ) {
        message("vision", "北边的石壁忽然发出轧轧怪响，缓缓的向旁边移动着，出现了一个黑漆漆的洞穴。\n",
            this_object() );
        set("exits/north", "d/xuantian/room10");
        if( room = find_object("d/xuantian/room10") ) {
            room->set("exits/south", "d/xuantian/dong");
            message("vision", "南边边的石壁忽然发出轧轧怪响，缓缓的向旁边移动着，出现了一个黑漆漆的洞穴。\n",
                room );
        }
        delete("left_trigger");
        delete("right_trigger");
        call_out("close_passage", 30);
    }
}
void close_passage()
{
    object room;
    if( !query("exits/north") ) return;
    message("vision", "喀嚓一声，石壁又关上了，一点出口的痕迹都看不见了。\n",
        this_object() );
    if( room = find_object(__DIR__"room10") ) {
        room->delete("exits/south");
        message("vision", "喀嚓一声，石壁又关上了，一点出口的痕迹都看不见了。\n"
                        HIR "你脑海中闪过一个念头：坏了！出不去了！\n" NOR ,
            room );
    }
    delete("exits/north");
}
int do_push(string arg)
{
    string dir;
    if( !arg || arg=="" ) return 0;
    if( arg=="shi" ) {
        write("你试著推动钟乳石，发现它可以左右推动....\n");
        return 1;
    }
    if( sscanf(arg, "shi %s", dir)==1 ) {
        if( dir=="right" ) {
            message_vision("$N将钟乳石往右推...，忽然轧轧几声钟乳石又移回原位。\n", this_player());
            add("right_trigger", 1);
            check_trigger();
            return 1;
        } else if( dir=="left" ) {
            message_vision("$N将钟乳石往左推...，忽然轧轧几声钟乳石又移回原位。\n", this_player());
            add("left_trigger", 1);
            check_trigger();
            return 1;
        } else {
            write("你要将钟乳石推向那个方向？\n");
            return 1;
        }
    }
}
void reset()
{
    ::reset();
    delete("left_trigger");
    delete("right_trigger");
}

