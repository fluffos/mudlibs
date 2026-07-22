// Room: gudi.c 谷底
// Created by Numa 1999-12-04

#include <ansi.h>
inherit ROOM;

string do_zb1();

void create()
{
        set("short", HIW"谷底"NOR);
        set("long", @LONG
谷内怪石嶙峋，竟没有一点出路可寻。此处的严寒非寻常地方可比，
各个方向似乎都不断的有寒风吹来，寒冷异常。
LONG);
        set("item_desc",([
                "怪石": (: do_zb1 :),
                "石":   (: do_zb1 :),
                "stone":(: do_zb1 :),
        ]));
        set("outdoors", "嵩山");
        setup();
}

string do_zb1()
{
        object me = this_player();
        
        if (!me->query_temp("ss/zsb_4"))
                return "你所见之处皆是怪石，毫无次序的堆在谷中。\n";
        me->delete_temp("ss/zsb_4");
        me->set_temp("ss/zsb_end",1);
        return "你所见之处皆是怪石，毫无次序的堆在谷中。在其中一堆石头中似乎有东西在闪烁。\n";
}



void init()
{
        object ob = this_player();
        if (userp(ob))
        {
                if (ob->query_skill("hanbing-zhenqi",1) < 200)
                {
                        message_vision(HIW"$N初下谷，冷的全身发麻，慌张的顺着绳子爬了回去。\n"NOR,ob);
                        ob->move(__DIR__"dtlxia");
                        message_vision(BLU"$N脸色发青，冷的浑身直哆嗦。\n"NOR,ob);
                        return;
                }
                else if (ob->query_skill("hanbing-zhenqi",1) > 220)
                        message_vision(HIW"$N顺着绳子爬了下来，并没有什么异样的感觉。\n"NOR,ob);
                else
                {
                        ob->set_temp("ss/get_cold",1);
                        message_vision(HIW"$N初下谷，只感觉这里和外界温差极大，不由得打了个冷颤。\n"NOR,ob);
                }
        }
        add_action("do_back",({"climb","pa"}));
        add_action("do_resist",({"resist","diyu","kangheng"}));
        add_action("do_move",({"fan","move"}));
}

int do_back(string arg)
{
        object me = this_player();
        
        if (!arg)
                return notify_fail("什么？\n");
        if (arg != "up" && arg != "back")
                return notify_fail("你要往哪里爬？\n");

        if(me->query_encumbrance() * 100 / me->query_max_encumbrance() > 20)
                return notify_fail("你背那么多东西，不怕掉下来吗？\n");
        
        message_vision("$N撮了撮手，一提气，顺着山壁爬了上去。\n",me);
        me->add("jingli",100);
        me->add("neili",200);
        me->delete_temp("ss");
        me->move(__DIR__"dtlxia");
        tell_room(environment(me),me->name(1)+"从谷底爬了上来，累的气喘吁吁。\n",({me}));
        return 1;
}

int do_move(string arg)
{
        object me = this_player();
        object ob, *clone;
        int i, j;
        
        if (!arg)
                return 0;
        if (arg != "stone" && arg != "石头" && arg != "怪石")
                return 0;
        if (!me->query_temp("ss/zsb_end"))
                return notify_fail("没事别乱搬石头，吃饱了撑的？\n");

        if (me->query("neili") < 2000)
        {
                message_vision("$N用尽全力想要搬开石头，没想到一不留神，石头砸在了自己脚上。\n",me);
                me->unconcious();
                return 1;
        }
        me->add("neili",-1000);
        message_vision("$N用尽全力，大喝一声将石头搬了开来。\n",me);

        ob = unew(__DIR__"obj/ice");
        if(!clonep(ob))
                return notify_fail("你发现下面什么都没有。\n");
        i = ob->query("unique");
        clone = filter_array(children(base_name(ob)), (: clonep :));
        j = sizeof(clone);
        while (j--)
                if (!clone[j]->query("clone_by_wizard"))
                        i--; 
        if(clonep(ob) && i < 0)
        {
                destruct(ob);
                return notify_fail("你发现下面什么都没有。\n");
        }

        tell_object(me,"你发现石头中居然有一块玄冰，中间似乎冻有什么东西。\n");
        ob->set_temp("find_by",me->query("id"));
        ob->move(this_object());
        me->delete_temp("ss/zsb_end");
        me->set_temp("ss/zsb_get",1);
        return 1;
}
        
int do_resist(string arg)
{
        object me = this_player();
        object ob = this_object();
        
        if (!arg)
                return 0;
        if (arg == "hanfeng" || arg == "cold" || arg == "hanleng")
        {
                if (!me->query("ss/hb_improve"))
                        return 0;
                if (!me->query_temp("ss/get_cold"))
                        return notify_fail("你要做什么？\n");
        
                if (me->query_skill("hanbing-zhenqi",1) < 200
                ||  me->query("max_neili") < 3000)
                        return notify_fail("你的内功修为如此之差，强行与寒风相抗衡恐怕会有生命危险。\n");

                if (me->is_busy() || me->is_fighting())
                        return notify_fail("你正忙着呢！\n");
        
                if (me->query("jingli")<50)
                        return notify_fail("你现在太累了，还是休息一下吧！\n");

                if (me->query("neili")<100)
                        return notify_fail("你现在太累了，还是休息一下吧！\n");

                if (me->query("jing")<50)
                        return notify_fail("你现在太累了，还是休息一下吧！\n");
                
//              me->delete_temp("ss/get_cold");
                tell_object(me,BLU"你静静盘腿而坐，运用体内寒冰真气和外界的寒风相抗衡。\n"NOR);
                tell_room(ob,HIW + me->name(1) + "盘腿而坐，周身被一股白气笼罩着。\n"NOR,({me}));
                me->start_busy(5);
                remove_call_out("hb_improving");
                call_out("hb_improving",4,me);
                return 1;
        }
        else
                return notify_fail("你要和什么相抗衡？\n");
}

int hb_improving(object me)
{
        int i;
/*      
        if (!me)
        {
                remove_call_out("hb_improving");
                return 1;
        }
*/      
        if (!me->query("songshan_point"))
                i = 100;
        else
                i = me->query("songshan_point")/3;
        if (i<100)
                i = 100;
        if (i>600)
                i = 600;
        
        me->receive_damage("jingli",30);
        me->receive_damage("neili",50);
        if (random(5)>3)
        {
                tell_object(me,"突然一阵强风吹来，你也不由得打了个冷颤。\n");
                me->receive_damage("jing",30);
        }
        i += (400 - me->query_skill("hanbing-zhenqi",1))*2;
        if (i>800)
                i = 800;
  me->improve_skill("hanbing-zhenqi", i*2/3 + random(i));
        tell_object(me,"你在与寒风的抗衡当中寒冰真气的修为也大大提升。\n");
        return 1;
}
