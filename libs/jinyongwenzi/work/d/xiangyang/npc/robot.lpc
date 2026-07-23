#include <ansi.h>
inherit NPC;
string ask_gift();
void create()
{
        set_name("柳随风", ({"robot darken", "darken", "robot"}) );
        set("long", "这个是柳随风做出来发礼物用的机器人。\n");
        set("gender", "男性" );
        set("title", "机器人");
        set("age", 24);
        set("attitude", "peaceful");
        set("str",1);
        set("int",99);
        set("con",99);
        set("dex",99);
        set("per",99);
        set("max_qi", 1000000);
        set("max_jing", 1000000);
        set("neili", 10000000);
        set("max_neili", 1000000);
        set("eff_jingli",1000000);
        set("jiali", 0);
        set("combat_exp", 30000000);
        set("unique", 1);

        set("shen_type", 1);
        set("class", "fighter");

        set("inquiry", ([
                "礼物": (: ask_gift :),
        ]) );

        setup();
}

string ask_gift()
{
        object ob = this_player();
        object gift;
        if (!ob->query("biwu_winner"))
           return RANK_D->query_respect(ob)+"凑什么热闹？\n";
        if (present("biwu gift", ob))
           return RANK_D->query_respect(ob)+"身上不是有了么？\n";

        gift = new("/d/huanghe/obj/"+ob->query("id"));
        gift->move(ob);
        message_vision("$N得到了"+gift->query("name")+"！\n", ob);
        return "小心收好啊，不小心丢了再找我吧。\n";
}

