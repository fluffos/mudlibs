//Edited by fandog, 02/13/2000
inherit NPC;

void create ()
{
	set_name("戚芳", ({"qi fang","qi"}));
	set("long", "一位容色秀丽的少妇，圆圆的脸蛋，一双大眼黑溜溜的，脸上不施脂粉，容色颇为憔悴。\n");
	set("gender", "女性");
	set("age", 20);
	set("combat_exp", 1000000);
	set("str", 20);
	set("int", 28);
	set("dex", 23);
	set("con", 26);
	set("per", 26);
	set("kar", 26);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("feixian-steps", 60);
	set_skill("liancheng-jian", 360);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
  
	setup();
	carry_object("/clone/cloth/female1-cloth")->wear();
}


