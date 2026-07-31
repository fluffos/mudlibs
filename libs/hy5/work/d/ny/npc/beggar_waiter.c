
// beggar_waiter.c

inherit NPC;

void create()
{
	set_name("丐帮八袋弟子", ({ "beggar waiter", "waiter" }) );
	set("gender", "男性" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
乞丐驼着背站在那儿,满脸笑容!
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"乞丐说道：此乃丐帮总舵,岂是好惹的!\n",
		"乞丐说道：你小子不要命了,敢来丐帮总舵撒野！\n",
		"乞丐招数出到一半又收回，似乎有些疑虑。\n",
		"乞丐说道：趁我还不想杀你,赶快逃命去吧。\n"
	}) );
	set("inquiry", ([
		"总舵": "这里就是丐帮总舵，施主有何贵干?",
	]) );

        set("atman", 500);
        set("max_atman", 500);

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 0);

        set("mana", 500);
        set("max_mana", 500);

        set("combat_exp", 30000);
        set("score", 4000);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("parry", 60);


	
	setup();
	
	carry_object("/clone/misc/cloth.c")->wear();
	carry_object(__DIR__"obj/stick.c")->wield();
}

