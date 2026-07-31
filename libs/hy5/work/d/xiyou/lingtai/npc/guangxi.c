// guang.c

inherit NPC;
inherit F_MASTER;
int borrow_me(object ob);
int borr_me(object ob);
void create()
{
        set_name("广羲子", ({"guang xizi", "guang"}));
        set("title", "经阁总管");
        set("gender", "男性" );
        set("age", 53);
        set("long", "一个看起来慈眉善目的道士，正拿着一本经书读着．\n");
	set("class", "toaist");
        set("combat_exp", 180000);
	set("daoxing", 250000);

        set("attitude", "friendly");
	
        set("per", 30);
	set("str", 25);
        create_family("方寸山三星洞", 2, "弟子");

	set("chat_msg", ({
		"广羲子笑道：我这人最爱吃松果了！\n",
}));
	set("chat_chance", 5);
        setup();
        carry_object("/d/xiyou/lingtai/obj/cloth")->wear();
	carry_object("/d/xiyou/lingtai/obj/daoguan")->wear();
}
