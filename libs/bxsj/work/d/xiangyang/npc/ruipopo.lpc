
inherit NPC;

void create()
{
	set_name("瑞婆婆", ({"rui popo", "popo", "rui"}));
	set("long", "这老妪满头白发，身子矮小，脸阔而短，满是皱纹，白眉下垂，一双眯成一条细缝的小眼中射出凶光
杀气. \n");
	set("gender", "女性");
       set("attitude", "friendly");
	set("age", 60);
	set("shen_type", -1);
	set("score", 400000);
	set("str", 31);
	set("int", 26);
	set("con", 30);
	set("dex", 32);
	set("max_qi", 2200);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiaji", 180);
	set("combat_exp", 800000);

	set_skill("force", 180);
	set_skill("dodge", 185);
	set_skill("unarmed", 100);
	set_skill("staff", 100);
	set_skill("parry", 185);
	set_skill("kunlun-shenfa", 150);
	set_skill("cuff", 100);
	set_skill("wenjia-quan", 100);
	set_skill("fengmo-zhang", 100);
	set_skill("xuantian-wuji", 100);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shnfa");
	map_skill("staff", "fengmo-zhang");
	map_skill("cuff", "wenjia-quan");
	map_skill("parry", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");

	set("chat_chance", 20);
	set("chat_msg", ({
		"瑞夫人说道：小姐嘱咐我们找那个贱人，可到现在还没找到，唉。。\n",
	}) );

	setup();
	add_money("gold", random(3));
	carry_object(BINGQI_D("gangzhang"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
