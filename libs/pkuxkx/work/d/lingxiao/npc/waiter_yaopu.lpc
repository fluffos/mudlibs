// waiter_yaopu.c

#include "setdizi.h"

inherit F_DEALER;

void create()
{
        setcreate(30);
        set_name("药铺伙计", ({ "yaopu huoji", "huoji", }) );
        set("gender", "男性" );
        set("age", 20);
        set("long", "这是一个干净利落的小伙计，不多说不少道，看上去挺斯文。\n");

        set("rank_info/respect", "先生");
        set("vendor_goods", ({
                "/d/city/npc/obj/renshen",
                "/clone/drug/gaoyao",
                __DIR__"obj/tangtou",
        }));
        add("inquiry", ([
                "name" : "我可担当不起，您就叫我小伙计吧。",
                "rumors" : "掌柜的从山下进了一批千年人参，听说功效神奇。",
                "here" : "这是凌霄城中唯一的药铺，有病有灾的都要来这里抓药。",
        ]) );

        setup();
        setequip();
}

void init()
{
        ::init();

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int accept_object(object me, object ob)
{
        if(ob->query("id") == "xue lian")
        {
                command("nod");
                MONEY_D->pay_player(me, 10000);
                return 1;
        }
        if(ob->query("id") == "xue mei")
        {
                command("nod");
                MONEY_D->pay_player(me, 8000);
                return 1;
        }
        return 0;
}
