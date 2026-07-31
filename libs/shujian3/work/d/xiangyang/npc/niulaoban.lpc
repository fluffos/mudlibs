// niulaoban.c 牛老板

inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("牛老板", ({ "niu laoban", "laoban", "niu" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 56);
        set("long", "牛老板正盯着你看，不知道打些什么主意。\n");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_temp("apply/damage", 100);

        set("combat_exp", 140000);
        set("attitude", "friendly");
        set("vendor_goods", ({
		(["name": "/clone/misc/denglong","number":5]),
		(["name": "/clone/misc/paper","number": 5]),
		(["name": "/clone/misc/fire","number":5])
        }));

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 2);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
