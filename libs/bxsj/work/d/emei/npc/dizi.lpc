// nan dizi. 女弟子
// Made By jackie

inherit NPC;
void create()
{
        set_name("女弟子", ({ "nv dizi", "dizi" }));
	set("long", "她是峨嵋山的第五代弟子，是在接待香客的。\n");
        set("gender", "女性");
	set("title", "峨嵋派第五代弟子");
        set("age", 30);
	set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 40000);
        set("shen_type", 0);
        set("attitude", "peaceful");
	set("max_qi",800);
        set("max_jing",800);
        set("neili",600);
        set("max_neili",600);
	set("jiali",0);
	set("score", 7000);

        set_skill("sword", 60);
	set_skill("huifeng-jian", 60);
	set_skill("parry",60);
	set_skill("linji-zhuang", 60);
        set_skill("dodge", 60);
	set_skill("force",60);
	set_skill("ding-dodge", 60);


	map_skill("force", "linji-zhuang");
	map_skill("dodge", "ding-dodge");
	map_skill("parry", "huifeng-jian");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();
        carry_object("/d/emei/obj/cloth")->wear();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/changjian")->wear();
}
