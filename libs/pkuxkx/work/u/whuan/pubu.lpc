//桃源瀑布
//by icer
inherit ROOM;

int do_jiejing();

void create()
{
        set("short", "瀑布");        set("long", @LONG
空山寂寂，水声在山谷间激荡回响。只见一道白龙似的大瀑布从对面
双峰之间奔腾而下，声势甚是惊人。瀑布旁有一间草屋。瀑布旁柳树下坐
着一个人，头带斗笠，身披蓑衣。
LONG
);
set("exits", ([
                "southwest" :__DIR__"road3",
]));
set("objects",([

      __DIR__"npc/yu" : 1,
     ]));
set("outdoors", "taoyuan");
setup();
}

void init()
{
        add_action("do_jiejing","jiejing");
}

int do_jiejing()
{
        object me=this_player();
        if (me->query("task_duan1"))
        {
                if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30)
                        return notify_fail("你身上背的东西太多，捷径太窄，进不去。\n");

                me->move(__DIR__"houshan");
                return 1;
        }
        else if(me->query_temp("dali/ask_yideng"))
        {       
                tell_object(me,"你按照镇南王指点的捷径直接上了后山。\n");
                me->move(__DIR__"houshan");
                return 1;                 
        }
        else if(me->query("family/master_id")=="yideng dashi")
        {       
                tell_object(me,"你从捷径直接上了后山。\n");
                me->move(__DIR__"houshan");
                return 1;                 
        }        
        else
        {
                return notify_fail("什麽?\n");
        }
}
