// Room: /d/huashan/v-road-5.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
       set("short", "山涧");
       set("long",@long
山涧到这里就没有路了，你仰头望去，一片绝壁在你的头顶上，根本没有
上去的可能，离你约莫四丈高的地方有一棵万年松(Songshu)正在随风摇摆。
前面就是华山的万丈深渊。
long);
       set("outdoors", "华山");
       set("item_desc",([
       "songshu" : "翠绿的松树枝随风摇摆，有时仅仅离地三丈高，借助绳子或许能攀登上去。\n",
]));
       set("exits",([
       "northwest" : __DIR__"v-road-1",
]));
       set("coor/x",50);
  set("coor/y",70);
   set("coor/z",-10);
   setup();
}

void init()
{
	if (is_wanted(this_player()))
		return;
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_bang",({ "ji", "bang" }));
}

int do_bang(string arg)
{
       object me;
       me = this_player();
       if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
       return notify_fail("你正忙着哪！\n");

       if ( arg=="" || arg!="shengzi"|| !arg) 
       return notify_fail("你要干什么？\n");

       if( me->query_temp("marks/绑") > 0 )
       return notify_fail("你已经在松树上绑了绳子了。\n");

       if( !present("sheng zi", me))
       return notify_fail("你要绑什么？\n");

       if( arg=="shengzi") {
       message_vision("$N使劲全身力气，把手中的绳子搭在松树枝条上，使劲地拽了拽
绳子，看来已经绑结实了。\n", me);
       me->set_temp("marks/绑", 1);
       destruct(present("sheng zi", me));
       return 1; }
}
int do_pa(string arg)
{
        object me;
       me = this_player();
       if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
       return notify_fail("你正忙着哪！\n");

       if ( arg=="" || arg!="up"|| !arg) 
       return notify_fail("你要干什么？\n");

       if( me->query_temp("marks/绑") < 1 )
       return notify_fail("三四丈高的松树，不借助一根绳子，怎么往上爬？\n");

       
       if( arg=="up")  {
       if( me->query_skill("dodge", 1) < 20 ) 
       {
       message_vision("$N借助绳子向峭壁爬了上去，突然$N脚下一滑，摔了下来。\n", me);
       me->unconcious();
       return 1; 
       }
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       {
       message_vision("$N借助绳子向峭壁爬了上去，因为身上负重过多，突然$N脚下一滑，摔了下来。\n", me);
       me->unconcious();
       return 1; 
       }
       message_vision("$N颤颤噤噤地往上爬。\n", me);
       me->move(__DIR__"song");
       return 1;
       }
}
int valid_leave(object me,string dir)
{
       me->delete_temp("marks/绑");
       return ::valid_leave(me, dir);  
}
