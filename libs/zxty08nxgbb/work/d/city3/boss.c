//boss.c


inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("茶馆老板", ({ "lao ban", "lao", "ban" }));
        set("nickname", "笑咪咪");
        set("shen_type", 1);

        set("str", 30);
        set("gender", "男性");
        set("age", 36);
        set("long",
                "他成天带着笑容，可是心头却灵醒得很。\n"+
                "作为茶馆的老板，成天和一帮没事干的无聊家伙混在一起。\n"+
                "消息很是灵通。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("inquiry", ([
                "温家" : "温家是成都的大户，但是却是外地迁来的，\n"+
                         "听说那家人曾在江湖中大大有名，是为了避仇到成都的。\n",
        ]));
        
        set("vendor_goods", ({
                "/d/city/obj/peanut",
                "/d/city/obj/tofu",
                __DIR__"obj/longhucui",
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("茶馆老板笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，快请进来喝杯热茶。\n");
                break;
        case 1 :
                say("茶馆老板说道：哟！这位" + RANK_D->query_respect(ob) + 
                        "您来了啊！本店有刚炸好的五香花生出售。\n");
                break;
        }
}

