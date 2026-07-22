// /d/city/npc/wenyi

inherit NPC;
 
void create()
{
	set_name("温仪", ({ "wen yi", "wen", "yi" }));
	set("long", 
        "她就是金蛇郎君的妻子温仪。\n"
        "一位三十来岁的女子，容貌清秀，有着一种成熟的韵味。\n");
	set("gender", "女性");
	set("age", 36);
	set("attitude", "friendly");
	set("shen", 1000);

	set("per", 27);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
	 

	set_skill("force", 60);
	set_skill("yijin-jing", 60);
	set_skill("dodge", 60);

	set_skill("shaolin-shenfa", 60);
	set_skill("cuff", 60);
	set_skill("wenjia-daofa", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("wenjia-quan", 60);
	set_skill("literate", 60);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shnfa");
	map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-daofa");
  	map_skill("blade", "wenjia-daofa");
	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
	carry_object(ARMOR_D("flower_shoe"))->wear();
	carry_object(ARMOR_D("pink_cloth"))->wear();
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("温仪对$N淡淡一笑，又转过身去，眉宇间没有丝毫恐惧。”\n", ob);
	message_vision("$N心中忽然觉得：“自己怎麽这麽无耻，对一个手无寸铁的人也要下此毒手？”\n", ob);
}
