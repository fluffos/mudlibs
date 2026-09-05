// luguanji.c 女管家

 inherit NPC;

 void create()
 {
 	set_name("女管家", ({ "guan jia", "guan" }));
 	set("gender", "女性");
 	set("age", 45);
 	set("max_qi", 1000);
 	set("eff_qi", 1000);
 	set("qi", 1000);
 	set("max_neili", 1000);
 	set("neili", 1000);
 	set("jiali", 50);

        set_skill("force", 150);
        set_skill("linji-zhuang", 150);
        set_skill("dodge", 150);
        set_skill("zhutian", 150);
        set_skill("tiangang-zhi", 150);
        set_skill("finger", 150);
        set_skill("jinding-mianzhang",150);
        set_skill("strike",150);
        set_skill("fuliu-jian",150);
        set_skill("sword",150);
        set_skill("yanxing-dao",150);
        set_skill("blade",150);
        set_skill("throwing",150);
        set_skill("pili-dan",150);

        set_skill("parry", 150);
        set_skill("mahayana", 150);
        set_skill("literate", 150);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("finger", "tiangang-zhi");
        map_skill("parry", "fuliu-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("sword", "fuliu-jian");
        map_skill("strike", "jinding-mianzhang");
        map_skill("throwing", "pili-dan");
        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-mianzhang");

 	set("combat_exp", 1070500);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
 	set("shen_type", -1);
 	setup();
 	carry_object(__DIR__"obj/diaopi")->wear();
 	carry_object("/d/city/obj/changjian")->wield();
 	add_money("silver", 10);

 }

void init()
{
	object ob, player;
	ob = this_player();
	if (ob->query("id") == "zhuang yuncheng")
	{
		player = ob->query_leader();
		set_leader(player);
		player->start_busy(2);
		kill_ob(ob);
	}
}