inherit NPC;
void create()
{
	set_name("匡文正", ({ "kuang wenzheng", "kuang", "teacher"}));
       	set("title", "教书先生");
       	set("long","村里的老教书先生，孩子们的扫盲全靠他了．\n");
	set("gender", "男性");
	set_level(17);
	set("age", 66);
	set("int", 30);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("literate",160);
	set_skill("sword", 140);
	set_skill("force",170);	
	set_skill("haoran-zhengqi",170);	
	set_skill("haoran-jian", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("yanxing-steps", 140);
	map_skill("dodge","yanxing-steps");
	map_skill("sword","haoran-jian");
	map_skill("parry","haoran-jian");
	map_skill("force","haoran-zhengqi");	
	set("daoxing", 5000);

	set("inquiry", ([
		"name"  : "老夫姓匡，字文正．阁下是．．．",
		"here"  : "这儿是老夫办的学堂，教孩子们一些知识．",
	]) );
	set("chat_chance", 5);
	set("chat_msg", ({
		"匡文正说道：『小心天下去得，莽撞寸步难行』。你要牢牢记得．\n",
		"匡文正摇头晃脑的念道：子曰：有朋自远方来，不亦乐乎．．无须备饭．\n",
		"匡文正笑盈盈地跟你打招呼：吃了？！\n",
	}) );
	setup();
	carry_object("/d/gao/obj/ruler")->wield();
	carry_object("/d/gao/obj/changpao")->wear();
	add_money("silver", 5);
}