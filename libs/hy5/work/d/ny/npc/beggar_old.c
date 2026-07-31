
// beggar_old.c

inherit NPC;

void create()
{
	set_name("丐帮九袋长老", ({ "beggar old","old", }) );
	set("gender", "男性" );
	set("age", 50);
	set("str", 35);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
长老坐在床边，手中握着几页信筏，双眉紧皱，面露凝重之色!
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

        set("atman", 800);
        set("max_atman", 800);

        set("force", 1500);
        set("max_force",1500);
        set("force_factor", 0 );

        set("mana", 800);
        set("max_mana", 800);

        set("combat_exp", 55000);
        set("score", 10000);

        set_skill("staff", 70);
        set_skill("unarmed", 70);
        set_skill("force", 60);
        set_skill("dodge", 70);
        set_skill("parry", 60);


	
	setup();
	
	carry_object("/clone/misc/cloth.c")->wear();
	carry_object(__DIR__"obj/stick.c")->wield();
}
