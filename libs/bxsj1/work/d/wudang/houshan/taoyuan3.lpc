// /u/dubei/wudang/taoyuan3

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","山顶");
        set("long", @LONG
这里是山峰顶部东侧的一个小坡，坡上也是杂草密布，在杂草之中隐约有
一些炯异的植物。南边有一排枝繁叶茂的树林。树林后面好象有一间茅屋。
LONG                           
        );
        set("xionghuang_count",500);

        set("outdoors","武当");        

        set("exits", ([               
                 "west" : __DIR__"taoyuan1",
        ]));
        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));
        add_action("do_zuan", ({"zuan","zuan"}));       
}
 
int do_wa(string arg)
{ 
        object xionghuang;
        object me;
        me = this_player();

        if (!( present("yao chu", this_player())))
             return notify_fail("你伸出两手，胡乱在地上乱刨！\n");

        if ( !arg || arg != "caoyao" )
             return notify_fail("你挖什麽？\n");

        if (!(int)me->query_temp("mark/wd_mission"))
             return notify_fail("你要做什麽？\n");

        if ( (int)me->query("jingli")<80) 
             return notify_fail("你太累了！\n");

        if(random(5)!=3) {
           me->add("jingli",-30);
           return notify_fail("你轮起药锄，向地上刨去,只挖出了一些野草。\n"); 
        }

        if (query("xionghuang_count") > 0){
          message_vision("$N轮起药锄，忽然间挖到了一株雄黄。\n",me);
          add("xionghuang_count", -1);
          xionghuang = new(MEDICINE_D("wudang/xionghuang"));
          xionghuang->move(me);
          me->add("jingli", -50);
        }
        else  message_vision("$N费了半天劲，只挖到一些野草。\n", me);
        return 1;
}

int do_zuan(string arg)
{
        object me;
        me = this_player(); 
        if ( arg != "shulin" ) return 0;
        if ( !arg ) return 0;

        if (!me->query_temp("marks/taohua"))
            return notify_fail("你打听清楚再钻吧！\n");
          
        message_vision("$N拨开树枝，一弯腰，钻了进去。\n", me);
        me->move(__DIR__"maowu");
        tell_room(environment(me), me->name() + "从树林中钻了进来。\n", ({ me }));
        me->delete_temp("marks/taohua");
        return 1;
}
