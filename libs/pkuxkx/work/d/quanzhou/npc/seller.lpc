// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("陈小二", ({ "xiao fan", "seller" }));
        set("title", "水果小贩");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "男性");
        set("age", 55);
        set("long",
                "陈阿婆之子，从小在泉州城长大，学了几年打鱼。\n"
                "陈阿婆怕他太辛苦，在泉州城内摆水果摊。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name" : "佤细尚鼎。萡行哋倪。\n",
                "here" : "泉州是个港口，会行船的人很多。\n",
                "陈阿婆" : "伊细佤阿母，伊咯是亏凳。\n",
        ]));
        
        set("vendor_goods", ({
                "/d/quanzhou/obj/lizhi",
                "/d/quanzhou/obj/longyan",
                "/d/quanzhou/obj/nai",
                    }));

        setup();
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
}

void greeting(object ob)
{
        if (!ob || environment(ob) != environment())
                return;
        switch(random(2)) {
        case 0 :
                say("陈小二笑眯眯地说道：人客，没倪娘醉过吧。\n");
                break;
        case 1 :
                say("陈小二说道：人客，诶倪咯？\n");
                break;
        }
}
