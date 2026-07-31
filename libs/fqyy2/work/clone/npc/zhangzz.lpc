// zhangzz.c 张召重

inherit NPC;

 
void consider();

void create()
{
	set_name("张召重", ({ "zhang zhaozhong","zhang","zhaozhong" }) );
	set("gender", "男性" );
	set("age", 37);
	set("long", "一副凶险奸诈的样子，让人看了就讨厌。\n");
	set("attitude", "peaceful");
//      set("nickname", "");
        set("str", 28);
	set("con", 21);
	set("int", 20);
	set("dex", 25);
 

	set("max_qi", 1000);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("shen", -4000);
	set("startroom","/d/wudang/xiaolu1");

	 
	set("combat_exp", 400000);

	set_skill("force", 90); 
	set_skill("cuff", 90);
	set_skill("sword", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("yinyun-ziqi", 90);
	set_skill("literate", 50);
	set_skill("taiji-quan", 90); 
	set_skill("taiji-jian", 90);
	set_skill("tiyunzong", 90);
        

	map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
        map_skill("sword","taiji-jian");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

	create_family("武当", 4, "弟子");

	set("chat_chance", 20);
	set("chat_msg", ({
		"张召重嘿嘿奸笑几声。\n",
                 "张召重撇了撇嘴，眼角眯缝的看着你。\n",
                 (: random_move :)
	}) );

	setup();
        carry_object("/d/city/obj/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
         
}
 

