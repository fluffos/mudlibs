// gongnv.c
inherit NPC;

void create()
{
	set_name("海兰珠", ({ "huang hou", "hou"}) );
	set("gender", "女性" );
	set("title", "皇后" );
	set("age", 14+random(10));
	set("long", "这是皇后孝端,容貌很清秀.\n");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("per", 36);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

