//Zine 25 Nov 2010
// zine Dec 10 2010,燕青拳quest
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河入海口"NOR);
        set("long", @LONG
这里是黄河南岸，滚滚黄河一刻不停地奔腾东去。
LONG
        );
        set("exits", ([
             "southwest" : __DIR__"hhn2",
        ]));
       

        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}

void init()
{
    add_action("do_han", ({ "han","dahan","喊" }));
}

int do_han(string arg)
{
    object me=this_player();
    object yq,lss;
    if (!arg)
    {
        message_vision("$N对着黄河大喊一声：啊～啊～啊～\n",me);
        return 1;
    }
    if (me->query("yanqing"))
    {
        tell_object(me,"你想起燕大哥的吩咐，不敢再用俗世的事物烦扰他了。\n");
        return 1;
    }
    if (!me->query_temp("yq"))
    {
        message_vision("$N对着黄河大喊一声："+arg+"！\n",me);
        return 1;
    }
    if (arg=="燕青"||arg=="浪子燕青"||arg=="燕大哥"||arg=="yanqing"||arg=="yan qing")
    {
        message_vision("$N鼓足力气，中气十足的大喊一声：“燕大哥，你在哪里？”\n",me);
        if (me->query("combat_exp")-me->query("yqexp")>5000000)
        {
            me->set("yqexp",me->query("combat_exp"));
            if (random(me->query("kar"))>35 && random(1000)>950||wizardp(me))
            {
                tell_object(me,"一对神仙眷侣般的人物走了出来。\n");
                yq=new(__DIR__"npc/yq");
                lss=new(__DIR__"npc/lss");
                yq->move(environment(me));
                lss->move(environment(me));
                me->set("yanqing",1);
                return 1;
            }
            else
            {
                tell_object(me,"半响，并无人回应，看来燕青已经出海了……\n");
                return 1;
            }
        }
        else
        {
            tell_object(me,"半响，并无人回应，看来燕青已经出海了……\n");
            return 1;
        }
        
    }
    else
    {
        message_vision("$N对着黄河大喊一声："+arg+"！\n",me);
        return 1;
    }
}




