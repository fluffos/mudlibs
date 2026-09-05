//by kiden
//2006.8.27
#include <ansi.h>
//#include <room.h>
inherit ROOM;

void create()
{
    set("short", BLU"码头"NOR);
    set("long", @LONG
这里是神龙岛的码头，一条木板搭成的小桥通向深水区。不远处，还停留了几艘船(boat)，
看样子要离开神龙岛得靠它了。北边是一片白色的沙滩，细细的沙子映着太阳，感觉好明亮。
不远处，一个船夫树下乘凉。
LONG);
   set("outdoors", "shenlongdao");
    set("exits", ([
  "north" : __DIR__"haitan",
    ]));
        set("objects",([
              __DIR__"npc/dizi" : 2,
              __DIR__"npc/chuanfu" : 1,
        ]));
        set("couldfish",1);
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
//        if ( !(this_player()->query_temp("shenlong/出海")) ) {return 0; }

                inv=all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (userp(inv[i]))
                                return notify_fail("你负重太大了，小舟恐怕载不动你。\n");
                }
    message_vision("\n$N跃上木船，船夫把木船划向海中。\n\n" ,me );
    message_vision("\n$N只觉得离神龙岛越来越远，不一会儿就再也看不见了。\n\n" ,me );
    me->move("/d/shenlongdao/muchuan") ;
    call_out("wait4", random(30) , me );
    return 1 ;
}

void wait4(object me)
{
        me->move ("/d/beijing/tanggu") ;
        message_vision("$N感觉过了好长时间，正在昏昏欲睡间，感觉船震了一下，原来是靠岸了。\n",me);      
        message_vision("$N朝船夫挥了挥手便跨上岸去。\n",me);
        me->delete_temp("shenlong/出海");
}

void wait3(object me)
{
        me->move ("/d/beijing/tanggu") ;
        message_vision("不一会儿就到了天津塘沽口，$N走上码头。\n",me);
}
