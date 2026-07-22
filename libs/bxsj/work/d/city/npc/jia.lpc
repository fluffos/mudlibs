// jia.c 贾老六
// by pishou

inherit NPC;

void create()
{
    set_name("贾老六", ({ "jia laolu", "jia" }));
	set("gender", "男性");
    set("age", 35);
    set("long", "他是天地会的贾老六。\n");
	
    set("combat_exp", 10000);
    set("shen_type", 1);
	set("attitude", "peaceful");
	
    set_skill("strike", 60);
	set_skill("dodge", 40);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
