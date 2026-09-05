// Room: /hangzhou/td_dilao1.c
// hubo 2008/4/19
 
inherit "/d/hangzhou/song_room";
#include <ansi.h>
int do_break(string);

void create()
{
        set("short", "地牢大门");
        set("long", @LONG
这是提督府的地牢大门口，里边关着朝廷的重犯，一个大门（men）上着锁。
LONG);

        set("exits", ([
                "south" : __DIR__"td_xiaodao2",
        ]));
        set("no_dbr_stage",1);
		set("hsz_no_task",1);
        set("no_task",1);		
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
    "$N走到后门前，摆出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "$N只听一声轰响，$N把门震开了！\n", this_player());
        set("exits/enter", __DIR__"td_dilao2");
        this_player()->set("neili",n-1000);
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
    message("vision","大门很神奇的自动关上了。\n", room);
    room->delete("exits/enter");
}

