inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("卖包子的", ({ "dumpling seller", "seller" }) );
        set("gender", "男性" );
        set("age", 33);
        set("per", 18);
        set("long", "这个卖包子的小贩对你微微一笑，说道：热腾腾的包子，来一笼吧？\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
	}));
//        set("chat_chance", );
        set("chat_msg", ({
                "卖包子的吆喝道：包子！热腾腾的包子！\n",
        }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

