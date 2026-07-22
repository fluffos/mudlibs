// Room: /d/huashan/shentan.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "山涧");
        set("long", @LONG
这是华山里的一个山涧，旁边是由于上面的山泉常年累月冲击形成的一个
很深的水潭。这里周围长满了灌木，东北的方向似乎能走过去。
LONG    );
        set("exits", ([ 
        "northeast" :   __DIR__"v-road-1"
        ]));
        set("outdoors", "华山");
        set("coor/x",30);
  set("coor/y",70);
   set("coor/z",-10);
   setup();
}

//int init()
//{
//        add_action("do_jump","jump");
//}


int do_jump(string arg)
{
        object me = this_player();
        int add_neili = me->query("neili");
        if ( arg != "up") return 0;
        if ( add_neili < 300 )
        {
                write("你深深的吸了一口气，运起内力尽力往上一跃，但就在快到达上面的时候又掉了下来。\n");
                add_neili = 0 - add_neili;
                me->add("neili",  add_neili);
                return 1;
        }
        me->add("neili", -300);
        tell_object(me, "你深深的吸了一口气，运起内力尽力往上一跃，成功的跳了上来。\n");
        message("vision", "只见" + me->query("name") + "尽力往上一跃，仿佛飞了上去。\n", environment(me), me);
        me->move(__DIR__"pubu");
        return 1;
}
