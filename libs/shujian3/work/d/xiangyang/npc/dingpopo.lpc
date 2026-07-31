
inherit NPC;

void create()
{
	set_name("丁婆婆", ({"ding popo", "popo", "ding"}));
	set("long", "这老妪头发花白，身子又瘦又驼，满是都是皱纹，眯着一双小眼. \n");
	set("gender", "女性");
       set("attitude", "friendly");
	set("age", 60);
	set("shen_type", -1);
	set("score", 650000);
	set("str", 25);
	set("int", 26);
	set("con", 30);
	set("dex", 35);
	set("max_qi", 2000);
	set("max_jing", 2100);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiaji", 30);
	set("combat_exp", 700000);

	set_skill("force", 180);
	set_skill("dodge", 185);
	set_skill("unarmed", 180);
	set_skill("whip", 100);
	set_skill("parry", 180);
	set_skill("kunlun-shenfa", 150);
	set_skill("cuff", 100);
	set_skill("wenjia-quan", 100);
	set_skill("qingxu-bian", 100);
	set_skill("xuantian-wuji", 100);
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "kunlun-shnfa");
	map_skill("whip", "qingxu-bian");
	map_skill("cuff", "wenjia-quan");
	map_skill("parry", "wenjia-quan");
        prepare_skill("cuff", "wenjia-quan");

	set("chat_chance", 20);
	set("chat_msg", ({
		"丁婆婆嘿嘿笑道：这次让我再看见她，非把她杀了不可。\n",
		}) );

	setup();
	add_money("gold", random(1));
	carry_object("/d/dali/npc/obj/ruansuo")->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
