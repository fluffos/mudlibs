// changlang2.c
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "后院");
    set("long", @LONG
这里是天龙寺的后院，天干木燥的季节，这里堆放了许多大水缸(gang)，以
备走水。
LONG
       );
    set("outdoors", "dali");
    set("item_desc",(["gang":"排列得整整齐齐的一排水缸。\n"]));
    set("exits", ([
               
                "south" : __DIR__"changlang2",
               
                ]));

    set("lingwu_family", "天龙寺");   
    set("no_clean_up", 0);
    set("least_msg",1);
    set("no_sick_spread",1);
    setup();
    
}

void init()
{
    object me=this_player();
    object tong;
    if ((NATURE_D->get_current_day_phase()=="下午"||NATURE_D->get_current_day_phase()=="正午")&&me->query("combat_exp")<10000&&me->query("family/family_name")=="天龙寺")
    {
        if (!present("zhangmu tong",me))
        {
            tong=new(__DIR__"obj/tong");
            tong->move(me);
            message_vision(HIG+"$N捡起一个"+tong->query("name")+"。\n"NOR,me);
        }
    }
    return;
}