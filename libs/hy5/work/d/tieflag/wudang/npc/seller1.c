 // waiter.c
inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("驼背老人", ({ "oldman", "man" }) );
        set("gender", "男性" );
        set("age", 52);
        set("long",
                "这位驼背老人望著炉火呆呆的出神。\n");
        set("combat_exp", 5);
	set("vendor_goods", ({
                __DIR__"obj/liandao.c",
                __DIR__"obj/axe.c",
                __DIR__"obj/dingpa.c",
                __DIR__"obj/basket.c",
                __DIR__"obj/hammer.c",
                __DIR__"obj/chutou.c",
	}));
        setup();
} 
void init()
{       
        object ob; 
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
  
