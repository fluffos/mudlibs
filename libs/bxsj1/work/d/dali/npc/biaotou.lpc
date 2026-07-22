//  biaotou.c
inherit NPC;

void create()
{
	set_name("大理镖头", ({ "dali biaotou","biaotou" }) );
        set("title","龙威镖局");
	set("gender", "男性");
	set("age", 44);
	set("long","这是一个镖头，走南闯北多年。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	setup();

	set("apply/attack", 30);
	set("apply/defense", 30);

	set_skill("unarmed", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("dodge", 66);
	setup();

	carry_object("/clone/armor/beixin")->wear();
	add_money("silver", 40);
}       

