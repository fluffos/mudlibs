//write by bright
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
藏经阁二楼是藏经书的重要地方，墙的四周是一排书架，摆满了道教的典籍。
据说九阳神功就藏在这，所以经常有盗贼出没。
LONG
        );

        set("exits", ([
                "down" : __DIR__"cangjingge",
        ]));
        
        set("cost", 0);
        setup();
}

void init()
{
        add_action("do_search", "search");
}

int do_search()
{
        object fighter,me = this_player();
        int search_time;

        if (!me->query_temp("song/job")){
        write(HIW"还是先领任务再来吧。"NOR);
        return 1;
        }

        if ((me->query("family/family_name") == "武当派") && (me->query("combat_exp") > 2000000) ){
                if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

                write("你蹑手蹑脚，挨个书架的寻找盗贼的踪迹。\n", me);

                me->start_busy(1);
                if(random(50)<=3){
                write(HIR"突然间从书架后穿一个人，说道：扰大爷我的好事！”\n"NOR,me);

                fighter=new("/d/wudang/npc/daozei");
                fighter->set("player",me->query("id"));
                fighter->move(environment(me));
                fighter->kill_ob(me);           
                return 1;
           }
        } 
}
