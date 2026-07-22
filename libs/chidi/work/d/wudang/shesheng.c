// Room: shiliang.c 石梁
// arnzh 97/1/24
inherit ROOM;
string look_out();
void create()
{
    set("short", "舍身崖");
    set("long", @LONG
这里是舍身崖，地势险峻，上面似乎连人都站不稳，武当弟子
经常在这里练习轻功。
LONG
    );
    set("exits", ([
        "west" : __DIR__"tyroadct",
    ]));
    set("item_desc",([
        "out"       :   (: look_out :),
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/zhangcui" : 1
       ]));
    setup();
}
void init()
{
    add_action("do_out","out");
}
int do_out(string arg)
{
    object me, killer;
    int i, ging_cost, qi_cost;
    me = this_player();
    i = (int)me->query_skill("dodge", 0) + random(200);
    ging_cost = 600 / (int)me->query_int();
    qi_cost = 500 / (int)me->query_int();
    if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
        i = 0;
    message_vision("$N爬上峭壁，一个纵身，跳了下去。\n", me);
    me->move(__DIR__"shesheng1");
    reset_eval_cost();
    message_vision("只听『砰』地一声$N从崖上跳了下来。\n", me);
    if ( i < 50)
    {
        killer = new(CLASS_D("wudang") + "/zhangcui");
         me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
    }
    else{ if( i < 125)
        me->unconcious();
    else {
        message_vision("$N已稳稳地站在地上。\n", me);
                if (me->query_skill("dodge", 1)<450)
                me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
                else me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/2);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","跳崖摔");
        me->delete_temp("last_damage_from");
    }
   }
    return 1;
}
string look_out()
{
    return  "这里是一个并不高的悬崖，你往下望去有一种想跳下去的感觉.\n";
}

