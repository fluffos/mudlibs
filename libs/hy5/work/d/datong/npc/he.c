// he.c

inherit NPC;

void create()
{
	set_name("和全利", ({ "he quanli" }) );
        set("gender", "男性" );

	set("title","钱庄老板");

        set("age", 38);
	set("str",88);
        set("long", "和全利就是大同府和记钱庄的老板。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object("/clone/misc/cloth")->wear();
}