// MERCHANT JOB ROOM xj_shop
// Create by zeus@刀剑笑 Nov.19.1999

inherit ROOM;

void create()
{
        set("short", "新疆货物集散地");
        set("long", @LONG       
这里是新疆的货物集散地，房子旁边的广场上放的都是这里的货
物，货物真是什么都有。当然也少不了这里的特产。
LONG);

        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("merchant_job",1);
        set("no_set_price",1);

        set("exits", ([
      "out" : "/d/xingxiu/store"
        ]));

        setup();
}

void init()
{
        object me=this_player();
        mapping now_place;
        string *place;

        now_place = me->query_temp("chaomai_buy");
        if ( now_place )
                place = keys(now_place);

        if ( me->query_temp("merchant/chaomai/given") )
        {       
                for (int i=0;i<sizeof(place);i++ )
                        if ( environment(me)->query("short")!=place[i] )
                                me->delete_temp("chaomai_buy/"+place[i]);
        }

}

