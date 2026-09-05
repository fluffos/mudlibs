// Room: /shenlongjiao/shanquan.c
// kiden 06/08/25

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG"山泉"NOR);
        set("long", @LONG
你穿过竹门，眼前突然开阔起来。不远处，一股清泉从山间留下，被人用竹管引到一个水池旁边。
池水是如此的清澈，里面还有一些金色的锦鲤游来游去。
LONG
        );
  set("outdoors", "shenlongdao");
  set("resource/water", 1);

        set("exits", ([
                "south" : __DIR__"chufang",        
                "north" : __DIR__"zhuogou",    
        ]));
  create_door("south", "竹门", "north", DOOR_CLOSED);
        setup();
}
void init()
{
add_action("do_drink","drink"); 
add_action("do_climb","climb"); 
}

int do_drink()
{       object me=this_player();
        if ((int)me->query("water")>((int)me->query("str")+10)*10)
        return notify_fail("灌了一肚子水，你也不难受呀？\n");
        
        me->set("water",450);
        message_vision("$N蹲下身掬起一捧泉水喝了下去，清爽之极。\n",me);
        return 1;
}
int do_climb(string arg)
{

        object me=this_player();

        if( !arg || (arg!="down") )
                return notify_fail("你要爬什么？\n");
        if(me->is_busy())
                return notify_fail("你很忙，爬什么呀！\n");

        message_vision("$N探身看了一下悬崖，顺着崖间的长藤向崖下爬去。。。\n", me);
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
            me->move(__DIR__"shengu");
            message_vision("崖上传来一声惨叫，$N晃悠悠的从崖上掉了下来。\n", me);
    }
    else
    {
            message_vision("$N的身影越来越小，终于变成一个小黑点，再也看不见了。\n", me);
            me->move(__DIR__"shengu");
            me->receive_damage("jing", 300);
            me->receive_damage("qi", 390);
            message_vision("$N从上面爬了下来，衣服都烂了，看起来十分狼狈。\n", me);
    }
        return 1;
}
int faila(object me)
{

        tell_object(me, "你手上的长藤“啪”的一声突然断了，你惨叫一声掉了下去。\n");
        tell_room(environment(me),"崖上传来一声惨叫，"+me->name()+"晃悠悠的从崖上掉了下来。\n", ({me, me}));
        me->move(__DIR__"shengu");
        me->unconcious();
        return 1;
}
