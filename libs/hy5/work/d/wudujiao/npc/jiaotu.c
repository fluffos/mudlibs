// jiaotu.c 五毒教徒
// by victori
inherit NPC;

void create()
{
	set_name("五毒教徒", ({"jiao tu","tu"}));
	set("long",
		"一个五毒的基层教徒，看来刚入教不久。\n"	);

	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 25);
	set("shen_type", -1);
	set("str", 20);
	set("int", 30);
	set("con", 25);
	set("dex", 23);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 20);
	set("combat_exp", 13000);
	set("chat_chance", 30);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 70);
        set_skill("wudu-shengong", 80);
        set_skill("dodge", 70);
        set_skill("wudu-yanluobu", 80);
        set_skill("unarmed", 80);
        set_skill("qianzhu-wandushou", 80);
        set_skill("parry", 80);
        set_skill("sword", 70);
        set_skill("wudu-goufa", 90);
        set_skill("poison", 80);
        set_skill("literate", 60);
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
                create_family("五毒教", 15, "弟子");
	setup();
	 carry_object(__DIR__"obj/ganggou")->wield();
	carry_object("/d/city/obj/cloth")->wear();

	setup();
}

