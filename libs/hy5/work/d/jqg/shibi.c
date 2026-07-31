// shibi.c 石壁
// By River 99.5.25
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
       set("short","石壁");
       set("long",@LONG
你约莫爬了六七十丈，仗着轻功卓绝，一路化险为夷，但爬到离洞穴七八
丈时，石壁不但光滑异常，再无可容手足之处，而且向内倾斜，除非是壁虎、
苍蝇，方能附壁不落。
LONG
);
       set("no_sleep_room", 1);
       set("no_fight", 1);
       setup();
}

void init()
{
       add_action("do_shuai","shuai");
       add_action("do_pa",({"pa", "climb"}));
}

int do_shuai(string arg)
{
       object ob1,me;
       me=this_player();
       if ( !arg || arg !="shugan") return 0;
       if ( me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着呢\n");
       if (me->query_temp("jqg/shuai"))
            return notify_fail("你已经把树干摔出洞穴了。\n");
       if (!ob1=(present("zao shugan",me)))
            return notify_fail("你用什么东西摔啊？\n");
       if (!me->query_temp("jqg/fu") || !ob1->query("jqg/fu"))
            return notify_fail("你就这样把树干摔上去有何用？\n");
       me->start_busy(2);
       destruct(ob1);
       me->set_temp("jqg/shuai", 1);
       message_vision("$N双足使出千斤坠功夫，牢牢踏在石壁之上，双臂运劲，将树干摔出洞穴。\n",me);
       tell_object(me,"这一下劲力使得恰到好处，树干落下时正好横架在洞穴口上。\n");
       return 1;
}

int do_pa(string arg)
{
       object me,*ob;
       int i;
       me=this_player();
       if ( !arg || (arg != "down" && arg != "up")) return 0;
       if ( me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢\n");
       if ( arg =="up"){
       if (!me->query_temp("jqg/shuai"))
             return notify_fail("石壁光滑异常，无可容手足之处，除非是壁虎、苍蝇，方能附壁不落。\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
             return notify_fail("你身上背负一个人，无法轻松爬上去。\n");
       message_vision("$N双手抓着绳索，交互上升，上升得更快了，不一会儿已然爬出洞穴。\n",me);
       me->delete_temp("jqg");
       me->move(__DIR__"shanlu6");
       tell_room(environment(me), me->name() + "从下面的"HIW"石窟"NOR"攀爬上来。\n",me);
       return 1;
       }
       if ( arg == "down"){
       if (me->query_temp("jqg/shuai"))
             return notify_fail("你已经把树干都摔出去了，还不快点爬上去？\n");
       ob = deep_inventory(me);
       i = sizeof(ob);
       while (i--)
       if (ob[i]->is_character())
             return notify_fail("你身上背负一个人，无法轻松爬下去。\n");
       message_vision("$N察看周遭形势，头顶洞穴径长丈许，足可出入而有余，又爬回石窟之底。\n",me);
       me->move(__DIR__"shiyao");
       tell_room(environment(me), me->name() + "从上面的石壁攀爬下来。\n",me);
       return 1;
       }
}
