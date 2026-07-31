// zhaojy.c 老爵爷 

inherit NPC;

 
void consider();

void create()
{
	set_name("赵爵爷", ({ "zhao jueye","zhao","jueye" }) );
	set("gender", "男性" );
	set("age", 67);
	set("long", "满头银发，但面色红润宛如壮年，双目炯炯有神。\n");
	set("attitude", "peaceful");
//      set("nickname", "");
        set("str", 28);
	set("con", 21);
	set("int", 20);
	set("dex", 25);
 

	set("max_qi", 1500);
	set("max_jing", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("shen", 8000);
	set("startroom","/d/city/beidajie3");

	 
	set("combat_exp", 950000);

	set_skill("force", 140); 
	set_skill("cuff", 150);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("yinyun-ziqi", 140);
	set_skill("literate", 120);
	set_skill("taizu-quan", 150); 
	set_skill("tiyunzong", 140);
        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");

	 
    set("chat_chance", 10);
	set("chat_msg", ({
        "赵爵爷深深叹了口气，“狼烟四起，民不聊生，我辈能做些什么呢？”\n",
                 "赵爵爷簇了簇眉，似乎想要寻找什么。\n",
                 (: random_move :)
	}) );

	setup();
        carry_object("/d/city/obj/cloth")->wear();
//        add_money("gold",5);
}
 

