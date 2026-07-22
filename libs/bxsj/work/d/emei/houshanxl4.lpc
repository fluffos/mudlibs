// houshanty.c
// 后山小路
inherit ROOM;
#include <ansi.h>

int do_ban(string arg);

void create()
{
        set("short", HIG "后山小路" NOR);
        set("long", @long
这里虽说是小路，但灌木丛生，很难再找到下山的路了。前面一块大石头
(stone)挡住了下山的去路。
long);
        set("outdoors", "峨眉山");
        set("item_desc", ([ 
            "stone" : "    这是一块大石头，看来使点劲可以搬(move)开。\n",
]));
        set("exits",([
            "southup":__DIR__"houshanxl3",
]));
        setup();
}

void init()
{
    add_action("do_ban", "move");
}

int do_ban(string arg)
{
    object me = this_player();
    if(!arg) return 0;
    if(arg != "大石头" && arg != "石头" && arg != "stone" && arg != "shitou" ) return 0;
    if( random((int)me->query_str()) >= 15) {
        message_vision("$N双膀较劲，搬开了大石头。\n", me);
        set("exits",([
            "southup":__DIR__"houshanxl3",
            "northdown":__DIR__"qingyinge",
]));
        
    }
    else {
        message_vision("$N使尽了吃奶的力气，也没搬开大石头。\n", me);
    }
    return 1;
}