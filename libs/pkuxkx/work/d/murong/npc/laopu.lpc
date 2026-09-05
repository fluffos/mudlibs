//laopu.c
//by hehe
//2003.3.13

inherit NPC;

void create()
{
	set_name("老仆", ({ "lao pu","pu" }));
	set("gender", "男性");
	set("age", 55);
	set("long", "他是他是姑苏慕容家的老仆，一辈子都没有离开过姑苏慕容家。\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object(__DIR__"obj/shoes1")->wear();
    carry_object(__DIR__"obj/cloth")->wear(); 
}