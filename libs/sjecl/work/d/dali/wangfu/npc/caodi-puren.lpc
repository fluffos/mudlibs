// Modify By River 98/12 
inherit NPC;

void create()
{
	set_name("扫地仆人", ({ "saodi puren","puren" }) );
	set("gender", "男性");
	set("age", 34);
	set("long","镇南王府的一个扫地仆人。\n");
	set("title", "镇南王府仆人");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry", ([
	     "name" :"人人都叫我阿木，你就叫我阿木好了。",
	]));

	set("apply/attack", 50);
	set("apply/defense", 50);

	set_skill("unarmed", 50);
	set_skill("cuff", 50);
	set_skill("parry", 50);
	set_skill("dodge", 56);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}       

