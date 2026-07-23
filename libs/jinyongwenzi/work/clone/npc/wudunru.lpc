// wudunru.c武敦儒

inherit NPC;

 
void consider();

void create()
{
	set_name("武敦儒", ({ "wu dunru","wu","dunru" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long", "身材健壮，浓浓的眉毛，一副精神饱满的样子。\n");
	set("attitude", "peaceful");
//      set("nickname", "");
        set("str", 30);
	set("con", 30);
	set("int", 20);
	set("dex", 30);
 

	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("shen", 5000);
	set("startroom","/d/xiangyang/outsroad1");

	 
	set("combat_exp", 500000);

	set_skill("force", 100); 
	set_skill("hand", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("huntian-qigong", 100);
	set_skill("literate", 100);
	set_skill("suohou-shou", 100); 
	set_skill("liuhe-daofa", 100);
	set_skill("xiaoyaoyou", 100);
        

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("blade","liuhe-daofa");
        map_skill("hand", "suohou-shou");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("hand", "suohou-shou");

	create_family("丐帮", 19, "挂名弟子");

	set("chat_chance", 20);
	set("chat_msg", ({
		"武敦儒说到：“打狗棒的精髓太难领悟了...哎\n",
		"武敦儒说到：“郭芙是喜欢我呢，还是喜欢....？\n",
                 (: random_move :)
	}) );

	setup();
        carry_object("/d/city/bqp_obj/blade")->wield();
        carry_object("/d/city/obj/cloth")->wear();
         
}
 

