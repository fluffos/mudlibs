// zhen.c 甄老板 
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
        set_name("甄有道", ({ "zhen youdao", "zhen" }));
        set("title", "杂货铺老板");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "甄老板是土生土长的大理人，做了几十年的小买卖。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                __DIR__"obj/mandao",
                __DIR__"obj/kandao",
                __DIR__"obj/maotan",
                __DIR__"obj/shoes",
                __DIR__"obj/puercha",
        }));
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
