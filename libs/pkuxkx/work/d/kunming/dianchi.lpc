// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "滇池");
        set("long", "这里是滇池边，走到这里，眼前豁然开朗，五百里滇池碧波荡漾，阳光洒在\n水波上，仿佛哪位神仙姐姐给湖里撒下了无数的小宝石。湖边小坡长了一些鸡血\n藤(teng)。\n");
        set("exits", ([
               //"northeast" : __DIR__"xunyanglou",
               "north" : __DIR__"dianchib2",
               //"up" : __DIR__"yueyang2",
               "west" : __DIR__"dianchib1",
               
                
        ]));
        set("item_desc", ([
		"teng" : "鸡血藤可以入药，一般生长在高原浅坡。你可以摘(zhai)下来。\n", 
	    ]));
        set("couldfish",1);
        set("outdoors", "kunming");
        setup();
   
}
void init()
{ 
	add_action("do_zhai","zhai"); 
}

int do_zhai()
{
    object me=this_player();
    object gc;
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("鸡血藤"))
    {
        return notify_fail("鸡血藤已经被摘完了。\n");
    }
    me->set_temp("鸡血藤",1);
    gc=new("/d/taishan/obj/jixueteng");
    gc->move(me);
    message_vision("$N拣起了一颗鸡血藤。\n",me);
    return 1;
}