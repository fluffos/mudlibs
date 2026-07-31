// gongnv.c
inherit NPC;

void create()
{
	set_name("´óÓñ¶ù", ({ "yu er", "yuer"}) );
	set("gender", "Å®ĞÔ" );
	set("title", "»Êåú" );
	set("age", 14+random(10));
	set("long", "ÕâÊÇ»ÊåúĞ¢×¯,ÈİÃ²ºÜÇåĞã.\n");
	set("shen_type", 1);
	set("combat_exp", 3000);
	set("per", 30);
	set("str", 18);
	set("dex", 18);
	set("con", 18);
	set("int", 19);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

