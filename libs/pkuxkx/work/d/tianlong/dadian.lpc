#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "三元宫");
    set("long", @LONG
三元宫是天龙寺正殿，本因方丈平时就在此处收徒授课。殿内
虽有不少天龙弟子在此，却一点也没有喧哗之声。
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "north" : __DIR__"yuan",
                "south" : __DIR__"changlang",
                ]));
    set("objects", ([
                CLASS_D("tianlong")+"/benyin" : 1,
                __DIR__"npc/shami" : 4 ]) );

    set("no_clean_up", 0);
    set("valid_startroom", 1);
    setup();
    "/clone/board/tls_b"->foo();

}

void init()
{
    add_action("do_nian","nian");
}

int nian(object me)
{
    string * jing=({"佛告须菩提：“于意云何？如来昔在然灯佛所，于法有所得不？”\n","“不也，世尊！如来在然灯佛所，于法实无所得。”\n","“须菩提！于意云何？菩萨庄严佛土不？”\n","“不也，世尊！何以故？庄严佛土者，则非庄严，是名庄严。”\n","“是故须菩提！诸菩萨摩诃萨应如是生清净心，\n","不应住色生心，不应住声香味触法生心，应无所住而生其心。\n","须菩提！譬如有人，身如须弥山王，于意云何？是身为大不？”\n","须菩提言：“甚大，世尊！何以故？佛说非身，是名大身。”\n"});
    if (me->query_temp("tlnewbiejob/newbie/niantimes")>12+random(8))
    {
        me->delete_temp("tlnewbiejob/newbie/niantimes");
        me->delete_temp("天龙念经");
        me->add_temp("tlnewbiejob/newbie/nian",1);
        message_vision(HIG"$N和众僧结束了早课。\n"NOR,me);
        return 1;
    }
    message_vision("$N跟着众僧念道："+jing[random(sizeof(jing))]+"\n",me);
    me->add_temp("tlnewbiejob/newbie/niantimes",1);
    call_out("nian",2+random(2),me);
    return 1;
}

int do_nian()
{
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("天龙念经"))
    {
        tell_object(me,"你已经开始念经了。\n");
        return 1;
    }
    if (me->query("family/family_name")=="天龙寺")
    {
        if (NATURE_D->get_current_day_phase()=="凌晨"&&me->query("combat_exp")<10000)
        {
            me->set_temp("tlnewbiejob/newbie/nian",1);
            me->set_temp("天龙念经",1);
            message_vision("$N开始跟着众僧念起了金刚经。\n",me);
            call_out("nian",1,me);
            return 1;
        }
        message_vision("$N随便念了几句经文，意兴索然。\n",me);
        return 1;
    }
    else
    {
        message_vision("$N开始跟着众僧念起了金刚经，僧人越念越快，你渐渐跟不上了。\n",me);
        return 1;
    }
}

int valid_leave(object me,string dir)
{
    if (me->query_temp("天龙念经"))
    {
        return notify_fail("你还没有做完早课，暂时不许离开。\n");
    }
    return ::valid_leave(me,dir);
}
