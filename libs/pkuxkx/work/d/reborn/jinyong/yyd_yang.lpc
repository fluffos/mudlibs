#include <ansi.h>
inherit ROOM;
int do_put(string arg);
void create()
{
        set("short", HIM"侧室"NOR);
        set("long", @LONG
这是沙漠中的一个土房间,里面都没有。仔细一看，房间的的中央有一块大石，好象不是天然
生成的，石头中间是一个孔（hole）。
LONG
        );
        set("exits", ([
            "west" : __DIR__"yyd_yuanyang" ,
                  ]));
  set("item_desc",([
            "hole": "这个孔似乎可以放下一把刀。\n",
                  ]));
        setup();
}
void init()
{        
        add_action("do_put", "put");
        add_action("do_put", "insert");
}

int do_put(string arg)
{ 
        object me=this_player(); 
        object blade;
        blade=present("yang dao", me);
        if( !arg || arg=="" ) return 0;
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢！");
        if( arg=="yang dao" )
        {
            if (!blade) 
                return notify_fail("你身上有这样东西么？");
            else
            {
                message_vision("$N将$n放进石头的孔中。\n",me,blade);
                blade->set("no_get",1);
                blade->move(environment(me));
                set("yangdao",1);
            }
        }
            else {return 0;} 
        return 1;
}
