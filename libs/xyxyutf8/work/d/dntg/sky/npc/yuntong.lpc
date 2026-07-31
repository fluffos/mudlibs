//sgzl

inherit NPC;

void create()
{
	set_name("云童",({"yun tong","yun shen","tong"}));
	set("gender", "男性");
	set("age", 15);
	set_level(100+random(50));
	set("long", "    \n天宫中负责起云的天神，他虽看上去年纪轻轻，却掌管着天上所有的云彩。\n");
	set("attitude", "heroism");
	set("class", "xian");
	set("daoxing", 800000);
	set("force_factor", 20);
	set("mana_factor", 30);
	set_skill("dodge", 980);
	set_skill("jindouyun", 950);
	set_skill("unarmed", 970);
	set_skill("puti-zhi", 970);
	set_skill("spells", 990);
	set_skill("parry", 990);
	set_skill("force", 990);
	map_skill("dodge", "jindouyun");
	map_skill("unarmed", "puti-zhi");
	set("inquiry", ([
  		"起云"   : "有张灵符可以起云，但我不能给你。",
  		"cloud"   : "有张灵符可以起云，但我不能给你。",
  		"name"   : "我是云神。",
  		"here"   : "这里就是天宫。",
	]));
	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/dntg/sky/obj/yunlingfu");
}

