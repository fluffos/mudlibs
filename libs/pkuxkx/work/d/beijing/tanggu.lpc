//Cracked by Roath
// /d/shenlong/tanggu.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;
//inherit HARBOR;

void create()
{
        set("short", "塘沽口");
        set("long", @LONG
这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群海
鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大
船(boat)，船上坐着几个渔夫打扮的人，乘船可渡过大海到达海的另一端。
西面是天津城，东面是一望无际的大海。南侧的角落里面停靠了一些小船，
也许是神龙弟子留下的，神龙弟子也许可以找到(find boat)属于自己的那艘。
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "northwest" : __DIR__"dadao_yongan_s",
        ]));

        set("item_desc", ([
                "boat" : "这是一艘海船，可载人渡海，但是船家在平时也用它来打鱼。\n如果你想靠它来出海也许要问一下船家！\n",
        ]));

        set("objects", ([
        "/d/shenlongdao/npc/chuanfu2" : 1,
        ]));

        set("navigate/locx", 0);
        set("navigate/locy", 0);

        set("cost", 2);

        setup();
}
void init()
{
    add_action("do_find", "find");
    add_action("do_enter", "enter");
}
int do_find(string arg)
{
        object me;
        object *inv;
        int i;
        me = this_player();

        if (arg=="boat" && me->query("family/family_name")=="神龙教")
        {

                inv=all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                                return notify_fail("你负重太大了，小舟恐怕载不动你。\n");
                }
                tell_object(me, "你熟门熟路地找到一条小舟，解开绳子，划了起来。\n");
                me->move("/d/shenlongdao/muchuan");
    call_out("wait3", random(2) , me );
                return 1;
        }
        return 0;
}
int do_enter(string arg)
{
    object me;
    object *inv;
    int i;
    me = this_player () ;

        if(arg!="boat") {       return 0;       }
//        if ( !(this_player()->query_temp("shenlong/去神龙岛")) ) {return 0; }
                inv=all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                                return notify_fail("你负重太大了，小舟恐怕载不动你。\n");
                }
    message_vision("\n$N跃上木船，船夫把木船划向海中。\n\n" ,me );
    message_vision("\n$N只觉得离塘沽口越来越远，不一会儿就再也看不见了。\n\n" ,me );
    me->move("/d/shenlongdao/muchuan") ;
    call_out("wait4", random(30) , me );
    return 1 ;
}
void wait4(object me)
{
				if (!me) return;
        me->move ("/d/shenlongdao/matou") ;
        message_vision("$N感觉过了好长时间，正在昏昏欲睡间，感觉船震了一下，原来是靠岸了。\n",me);      
        message_vision("$N朝船夫挥了挥手便跨上岸去。\n",me);
        me->delete_temp("shenlong/去神龙岛");
}

void wait3(object me)
{
				if (!me) return;
        me->move ("/d/shenlongdao/matou") ;
        message_vision("不一会儿就到了神龙岛，$N纵身跃上码头。\n",me);
}

