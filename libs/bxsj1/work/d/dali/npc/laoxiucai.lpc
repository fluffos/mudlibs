// 老秀才
// Modify By River 98/12
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("老秀才", ({ "lao xiucai", "xiucai","lao" }));
	set("str", 18);
	set("gender", "男性");
	set("age", 60);
        set("unique", 1);
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("vendor_goods", ({
        (["name":__DIR__"obj/jianjie","number":5]),
       	}));

	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
