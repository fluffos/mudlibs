//Cracked by Roath
// bear-monster.c 黑熊怪□
// By Dream Dec. 20, 1996

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黑熊怪", ({ "bear monster", "bear", "monster" }));
	set("title", "南海观音之徒");   
	set("long", @LONG
黑熊怪本是山间野兽，不知从哪里学到一身好本领。
后遇见南海观音，被南海观音收为徒弟。
LONG);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "heroism");
	set("per", 9);
	set("rank_info/self", "黑熊");
	set("rank_info/rude", "熊怪");
	set("max_kee", 850);
	set("max_gin", 800);
	set("max_sen", 850);
	set("force", 400);
	set("max_force", 500);
	set("force_factor", 50);
	set("max_mana", 250);
	set("mana", 300);
	set("mana_factor", 20);
	set("combat_exp", 30000);
	set("daoxing", 50000);

	set_skill("literate", 60);

        create_family("南海普陀山", 2, "弟子");

	setup();
//	carry_object("/obj/cloth")->wear();
	carry_object("/d/xiyou/nanhai/obj/jingu3");
//	carry_object("/d/xiyou/nanhai/obj/jingu3");
}

