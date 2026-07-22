// jianjie

inherit NPC;
void create()
{
      set_name("简捷", ({ "jian jie", "jian" }));
	set("nickname", "圣手迦蓝");
	set("long", 
        "三十来岁的样子，一双眼睛微微眯缝。\n"
        "据说一身功夫很是了得。\n");
	set("gender", "男性");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -10000);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 800000);
	 

    set_skill("force", 110);
    set_skill("huagong-dafa", 110);
    set_skill("dodge", 110);

    set_skill("zhaixingshu", 110);
    set_skill("cuff", 110);
    set_skill("wudang-quan", 110);
    set_skill("parry", 110);
    set_skill("staff", 110);
    set_skill("tianshan-zhang", 110);
	set_skill("literate", 110);

	map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixingshu");
    map_skill("cuff", "wudang-quan");
  	map_skill("parry", "wudang-quan");
  	map_skill("staff", "tianshan-zhang");
    prepare_skill("cuff", "wudang-quan");

//	create_family("", 2, "弟子");

   

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/armor/cloth")->wear();
         add_money("gold", 2);
}

 

 


