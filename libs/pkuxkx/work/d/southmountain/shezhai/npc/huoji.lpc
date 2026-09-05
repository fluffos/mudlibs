inherit NPC;
inherit F_DEALER;

void create()
{
    int i=random(100);
	set_name("酒馆老板", ({ "jiuguan laoban", "lao ban","laoban","boss" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 38);
	set("long", "他是畲寨酒馆的主人，经营这家小店很多年了。\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
    set("vendor_goods", ({
	
                __DIR__"obj/hongqu",
                __DIR__"obj/shefood",
    }));
    set("shen_type",1);set("score",200);setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
