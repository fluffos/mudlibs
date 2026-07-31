// bing.c 官兵

inherit NPC;

void create()
{
	set_name("驿兵", ({ "yi bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long","他就是管这个马站的兵士。虽然不打战，脾气好，也不能随便招惹哦。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 100100);
	set("shen_type", 1);

	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("blade", 140);
	set_skill("force", 140);
	set_temp("apply/attack", 140);
	set_temp("apply/defense", 140);
	set_temp("apply/damage", 210);
	set_temp("apply/armor", 140);

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}
