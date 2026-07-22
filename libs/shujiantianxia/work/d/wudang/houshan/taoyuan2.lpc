// Room : /d/wudang/taoyuan2 桃园
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","山顶");
        set("long", @LONG
这里是山顶的西侧，遍地野果。草深齐肩，间或开放着的白花，迎风摇曳，
一切都沉沁在自然的怀抱里，是那么的自然、野性和洒脱。下面是一条深不见
底的峡谷，山藤密集，藤粗似臂，又如瀑布一泻而下，煞是壮观。
LONG                           
        );
        set("mahuang_count",500);

        set("outdoors","武当");

        set("exits", ([               
                 "east" : __DIR__"taoyuan1",
        ]));

        setup();
}

void init()
{
            add_action("do_wa", ({"wa","dig","挖"}));
            add_action("do_hold", "hold");
            add_action("do_jump", ({"jump","tiao"}));        
}
 
int do_wa(string arg)
{ 
        object mahuang;
        object me;
        me = this_player();

        if (!( present("yao chu", this_player())))
             return notify_fail("你伸出两手，胡乱在地上乱刨！\n");

        if ( !arg || arg != "caoyao" )
             return notify_fail("你挖什麽？\n");

        if (!(int)me->query_temp("mark/wd_mission"))
             return notify_fail("你要做什麽？\n");

        if( me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着呢。\n");

        if ((int)me->query("jingli") < 80) 
             return notify_fail("你太累了！\n");

        if(random(5)!=3) {
           me->add("jingli",-30);
           return notify_fail("你轮起药锄，向地上刨去,只挖出了一些野草。\n"); 
         }
        if (query("mahuang_count") > 0 && random(10) > 1){
          message_vision("$N轮起药锄，忽然间挖到了一株麻黄。\n",me);
          add("mahuang_count", -1);
          me->start_busy(1);
          mahuang=new(MEDICINE_D("wudang/mahuang"));
          mahuang->move(me);
          me->add("jingli", -50);      
        }
        else message_vision("$N费了半天劲，只挖到一些野草。\n", me);
        return 1;
}

int do_hold(string arg)
{
        object me;
        me=this_player();

        if (me->is_busy())
           return notify_fail ("你现在很忙！\n");

        if (me->is_fighting())
           return notify_fail ("你还是专心战斗吧。！\n");        

        if ( arg != "teng" && arg != "山藤" )
           return notify_fail("你想抓住什么？\n");

        if ( me->query_temp("hold_teng"))
           return notify_fail ("你正抓住山藤呢。\n");

        write(HIY"你伸出双手，牢牢地抓住了山藤。\n"NOR);
        message("vision",me->name() + "突然伸出双手，牢牢地抓住山藤。\n", environment(me), ({me}) );
        me->set_temp("hold_teng",1);
        return 1;
}

int do_jump(string arg)
{
        object me = this_player();

        if (me->is_busy())
           return notify_fail ("你现在很忙！\n");

        if (me->is_fighting())
           return notify_fail ("你还是专心战斗吧。！\n");

        if ( arg != "down" )
           return notify_fail ("你要往哪里跳？？\n");

        if ( !me->query_temp("hold_teng"))
           return notify_fail ("你找死呀！！？？\n");

        message("vision", me->name() + "足点岩石，双手紧握山藤，慢慢向下荡去。\n", environment(me), ({me}));
        if ( me->query_skill("dodge",1) > 100 
          && me->query_skill("hand",1) > 80 ){
            write(HIY"\n你双脚交替轻触岩石，借势下滑，宛若大鸟般，稳稳的落在了谷底。\n"NOR); 
            me->move(__DIR__"gudi");
            me->delete_temp("hold_teng");
            return 1;
        }
        else {
            write(WHT"\n你脚蹬山岩，手握长藤，慢慢向谷底滑去。\n"NOR);
            write(HIR"\n你突然腿一软，双手再也不能把持山藤，重重地摔了下去。\n"NOR);
            me->move(__DIR__"gudi");
            me->delete_temp("hold_teng");
            me->receive_damage("qi", me->query("max_qi")/2);
            me->receive_wound("qi", me->query("max_qi") / 2);
            me->unconcious();
            message("vision", me->name() + "从上面摔了下来，“嘭”的一声重重地跌在了地上。\n", environment(me), ({me}));
            return 1;
        }
}
