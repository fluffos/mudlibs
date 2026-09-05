// File         : waiter_jiuguan.c
// Created By   : iszt@pkuxkx, 2007-05-03

#include <ansi.h>
#include "setdizi.h"

inherit F_DEALER;

void create()
{
        setcreate(20);
        set_name("酒保", ({ "jiu bao", "jiubao", "bao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这是一个身穿长衫的酒保，正在柜台后面筛酒。\n");
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ({
                __DIR__"obj/wine",
                "/clone/food/peanut",
        }));
        add("inquiry", ([
                "name" : "不敢不敢，您就叫我酒保吧。",
                "here" : "来啦！",
                "rumors" : "莫谈国事，莫谈国事。",
                "武功" : "大侠您可千万别搞错了，小的不会武功。",
                "剑法" : "大侠您可千万别搞错了，小的不会武功。",
                "雪山剑法" : "大侠您可千万别搞错了，小的不会武功。",
                "酒" : "来啦！您要点啥(list)？",
        ]));
        setup();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id"))
        {
                tell_object(who, "酒保一哈腰，说道：「多谢您赏钱，欢迎下次再来。」\n");
                return 1;
        }

        return 0;
}
