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
	 

	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("huagong-dafa", 180);
	set_skill("throwing", 150);
	set_skill("feixing-shu", 180);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 180);
	set_skill("strike", 150);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 150);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 180);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

//	create_family("", 2, "弟子");

   

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/cloth/cloth")->wear();
         add_money("gold", 1);
}

 

 


