// Room: /shenlongjiao/shengu.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create ()
{
        set ("short", "深谷");
        set ("long", @LONG

谷底到处都是枯枝烂叶，发出一股恶心的臭味，这里似乎好久都没有人来过了。
旁白的丛林中似乎传来一些奇怪的声音，你不禁毛骨悚然。

LONG);
        set("exits", ([ /* sizeof() == 3 */
        ]));
        set("outdoors","shenlongdao");
		set("no_newbie_task",1);
        setup();
}


void init()
{
        add_action("do_look", "kan");
        add_action("do_look", "view");
        add_action("do_look", "observe");
        add_action("do_climb", "climb");
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}
int do_climb(string arg)
{

        object me=this_player();

        if( !arg || (arg!="xuanya" && arg!="up" && arg!="cliff") )
                return notify_fail("你要爬什么？\n");
        if(me->is_busy())
                return notify_fail("你很忙，爬什么呀！\n");

        message_vision("$N抬头看了一下悬崖，顺着崖间的长藤向崖上爬去。。。\n", me);
        me->start_busy(20);

        if( (int)me->query("jing") < 400 || (int)me->query("qi") < 400) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 20, me);
        return 1;
}
int success(object me)
{
    if (objectp(me)&&!living(me))
    {
        message_vision("崖上传来一声惨叫，$N晃悠悠的从崖上掉了下来。\n", me);
    }
    else
    {
        message_vision("$N越爬越高，身影越来越小，终于变成一个小黑点，再也看不见了。\n", me);
        me->move(__DIR__"shanquan");
        me->receive_damage("jing", 300);
        me->receive_damage("qi", 390);
        message_vision("$N从下面爬了上来，衣服都烂了，看起来十分狼狈。\n", me);
    }
        return 1;
}
int faila(object me)
{

        tell_object(me, "你手上的长藤“啪”的一声突然断了，你惨叫一声掉了下去。\n");
        tell_room(environment(me),"崖上传来一声惨叫，"+me->name()+"晃悠悠的从崖上掉了下来。\n", ({me, me}));
   
        me->unconcious();
        return 1;
}


int do_look(string arg)
{
        object me = this_player();
        
        if(!arg || arg=="around" ) return notify_fail("\n你仔细看了看四周，发现这里几乎没有任何足迹。西面是一片悬崖，荆棘遍布，藤条丛生。而其他三个方向都是一篇高高的灌木丛。\n");
        if ( arg=="north" )  return notify_fail("\n北面是一片高高的灌木丛！\n"); 
        if (arg=="east")     return notify_fail("\n东面是一片高高的灌木丛！\n");
        if (arg=="south")    return notify_fail("\n南面是一片高高的灌木丛！\n");
        if (arg=="west")     return notify_fail("\n东面是一面悬崖，荆棘遍布，山腰似乎有个洞(hole)。\n");
        if (arg=="hole") 
        {
            tell_object(me,"\n那个洞黑乎乎的，不知道有什么。\n");
            me->set_temp("shenlong/看洞",1);
            return 1;
        }
}
int do_enter(string arg)
{
	     object me = this_player();
             if(!arg || arg!="hole") return notify_fail("没搞清楚，瞎钻什么？\n");
	     if(arg=="hole")
	     	{
	     		tell_object(me,"你蹑手蹑脚钻了进去。\n");
	     		me->move(__DIR__"shandong");
	     		return 1;
	     	}
}

