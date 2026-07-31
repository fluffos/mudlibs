// pawnboss.c

inherit NPC;

void create()
{
	set_name("黄富贵", ({ "huang fugui" }) );

        set("gender", "男性" );

	set("title","当铺掌柜");

        set("age", 38);

        set("long", "大同府当铺的大掌柜\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object("/clone/misc/cloth")->wear();
}