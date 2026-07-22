inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "墙上");
        set("long", @LONG
你爬上墙头，四周黑蒙蒙的，忽然一个人影出现在你面前。
LONG
        );
        set("outdoors", "xuantian");

        set("exits", ([ 
   "east" : __DIR__"work",
]));
        set("objects", ([
        ]));
    

        setup();
}

void init()
  {
       add_action("do_climb","climb");
  }
int do_climb(string arg)
{
       
        object me=this_player();
        object ob; 
        if( (!arg) ||!((arg == "wall") || (arg == "down")))
                return 0;
                message_vision("$N顺着房粱滑了下去。\n\n",me);
        ob = load_object(__DIR__"midao");
        ob = find_object(__DIR__"midao");
        message("vision", me->query("name")+"顺着房粱滑了下来。\n", ob);
        me->move(__DIR__"midao");
        return 1;
}

