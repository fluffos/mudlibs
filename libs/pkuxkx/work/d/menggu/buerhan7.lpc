inherit ROOM; 
#include <ansi.h>

string look_song();
void create() 
{ 
        set("short", HIG"巨松"NOR);
        set("long", @LONG
这里是一棵巨松(song)，几乎把前行的路完全挡出了。
LONG
        );
	    set("item_desc", ([
		"song" : (:look_song:), ]));
        set("exits", ([ "northeast" : __DIR__"buerhan8",
                        "southup": __DIR__"buerhan5",
]));
        set("outdoors", "menggu_e");
		setup();
}

void init()
{
    add_action("do_climb","climb");
}

int valid_leave(object me,string dir)
{
    if (dir=="northeast")
    {
        return notify_fail("巨松挡住了你的去路。\n");
    }
    return ::valid_leave(me,dir);
}

string look_song()
{
    object me=this_player();
    string msg="巨松之后，其实道路分成两股，你可以小心点爬过去(climb northeast/climb northwest)。\n";
    return msg;
}

int do_climb(string arg)
{
    object room,me=this_player();
    if (arg=="northeast"||arg=="ne")
    {
        room=load_object(__DIR__"buerhan8");
        tell_object(me,"你小心翼翼地向东北方向爬了过去。\n");
        me->move(room);
        tell_room(room,me->name()+"小心翼翼地爬了过来。\n");
    }
    else if (arg=="northwest"||arg=="nw")
    {
        room=load_object(__DIR__"buerhan9");
        tell_object(me,"你小心翼翼地向西北方向爬了过去。\n");
        me->move(room);
        tell_room(room,me->name()+"小心翼翼地爬了过来。\n");
    }
    else
    {
        tell_object(me,"你四脚着地，学着山间的土狗爬了起来！\n");
    }
    return 1;
}