#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "暗河");
        set("long", @LONG
暗河曲曲弯弯地向前去，你身不由主，随着水势向下漂流，幸好水位
不高，挣扎着还能探出头换口气。不知过了多久，水势缓了下来，勉强可
以站稳。高处似乎有些亮光晃动，依稀照出前方有几个挪动的黑影。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"river1",
                "east" : __DIR__"river2",
        ]));
        set("objects", ([
                __DIR__"npc/cor" : 2,
                __DIR__"npc/kingcor" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{
        add_action("do_climb", "climb");
} 
int do_climb(string arg)
{
        object obj;
        object me, room;
        me= this_player();
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "up")
        {
        message_vision(YEL"$N双手并用向上爬去。\n"NOR,me);
        call_out("climb_up",6,me);
        me->start_busy(4);
        return 1;
        }
        else
        {
                write("你不可以这么爬。");
                return 1;
        }
}  
int climb_up (object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room=find_object(__DIR__"yongdao7");
        if(!objectp(room)) 
                room = load_object(__DIR__"yongdao7"); 
        me->move(room);
        message_vision(HIG"$N湿淋淋地从暗河里爬上岸来。\n"NOR,me);
        return 1;
}    
