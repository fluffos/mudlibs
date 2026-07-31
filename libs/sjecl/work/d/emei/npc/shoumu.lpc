// /kungfu/class/emei/shoumu.c
// Make by jackie 98.2

inherit NPC;

void create()
{
        set_name("守墓弟子", ({ "shoumu dizi", "dizi"  }));
        set("long","这是个专门守墓的峨嵋派女弟子，她一见你来挖墓，立刻上前阻止你。\n");
	
        set("gender", "女性");
        set("attitude", "aggressive");
        set("class", "bonze");

        set("age", 30);
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1500);
        set("max_jing", 1500);
	set("eff_jingli", 1500);
	set("jing", 1500);
	set("jingli", 1500);
	set("eff_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 600000);
        set("score", 100);

	set_skill("dacheng-fofa", 120);
	set_skill("linji-zhuang", 150);
	set_skill("huifeng-jian", 135);
	set_skill("sword", 135);
	set_skill("parry", 135);
	set_skill("dodge", 135);
	set_skill("force", 135);
	set_skill("anying-fuxiang", 135);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("峨嵋派", 4, "弟子");

        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}
