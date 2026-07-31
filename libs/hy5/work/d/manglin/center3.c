 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "莽林之中");
        set("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出
昼夜。四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼
嚎随着腥风飘至耳际。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"groupe3",
  "west" : __DIR__"groupw3",
  "north" : __DIR__"groupn3",
  "south" : __DIR__"groups3", 
]));
        set("coor/x",50);
        set("coor/y",-400);
        set("coor/z",-50);
        setup();
}
void init()
{
        add_action("climbing", "climb");
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                return 0;
        }
        if( arg == "tree" || arg == "古树" || arg == "树")
        {
        me = this_player();
        message_vision("$N抓着突出的树枝，慢慢地顺着树杆爬了上去。\n", me);
        me->start_busy(3);
        call_out("fliping",3,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        if(!interactive(me) || environment(me) != this_object()){
                return 1;
        }
        if(objectp(me) && !me->is_ghost()){
        me->move(__DIR__"top3");
        message_vision("$N顺着树杆爬了上来。\n", me);
        }
        return 1;
}      
