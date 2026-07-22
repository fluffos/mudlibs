// boshi.c 茶博士
// by pishou

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("茶博士", ({ "cha boshi", "boshi" }));
    set("title", "茶馆老板");
    set("nickname", "茶状元");
        set("shen_type", 1);

    set("str", 30);
    set("gender", "男性");
    set("age", 45);
        set("long",
        "他是扬州城里有名的茶博士, 故称茶状元。\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
        "小宝" : "他去京城了。好长时间没有见到他了, 怪想他的。\n",
        "韦小宝" : "他嘴好甜，经常大叔前大叔后的叫我。\n",
        "茶" : "行行出状元。在下也是个状元, 不过不是顾先生顾状元。\n",
        ]));
        
        set("vendor_goods", ({
           (["name":__DIR__"obj/peanut","number":30]),
           (["name":__DIR__"obj/tofu","number":15])
        }));

        setup();
        add_money("coin", 50);
}

void init()
{
        object ob;
        
        ::init();
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
        say("茶博士笑眯眯地说道：这位" + RANK_D->query_respect(ob) +
                        "，快请进来喝杯热茶。\n");
                break;
        case 1 :
        say("茶博士说道：哟！这位" + RANK_D->query_respect(ob) +
                        "您来了啊！本店有刚炸好的五香花生出售。\n");
                break;
        }
}

