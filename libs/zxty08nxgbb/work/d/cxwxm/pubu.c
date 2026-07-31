// pubu.c 
// marry 99 .8
inherit ROOM;

#include <ansi.h>
void create()
{
        set("short", "瀑布");
        set("long", @LONG
你穿过玉米地猛听得水声响亮，轰轰隆隆，抬头一看，只见一条大瀑布，从高崖上直泻
下来，令你不由的想起“飞流直下三千尺，疑是银河落九天”的诗句来。
LONG );
       set("exits", ([
               "east" : __DIR__"yumi1",
       ]));
        set("outdoors", "cxwxm" );
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       int n;
        object me = this_player();

    if(arg)  
   {
    write("你是兔子呀，这么喜欢乱跳？\n");
         return 1;
}

    message_vision(
    "$N双眼一闭，默念：“太上老君，急急如律令。”想猛的向下跳去。\n", this_player());
    n = (int)me->query("combat_exp");
    if (n >=400000)
        {
          me->move(__DIR__"shandong");
          me->set_temp("jihao",1);
        }
    else
        {
         message_vision(
         "结果$N看着这无底深渊，还没跳就吓晕了！\n", this_player());
         this_player()->unconcious();
    }

    return 1;
}

