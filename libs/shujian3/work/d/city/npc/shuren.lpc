// shuren.c 说书人
//Creat by Looklove 2000/9/2

inherit NPC;

void create()
{
        set_name("说书人", ({ "shuoshu ren", "man", "ren" }));
	set("gender", "男性");
        set("age", 42);
        set("long", "他是一个讲述三国志，水浒传，大明英烈传等等英雄故事的说书人。\n");
	
        set("combat_exp", 1300);
        set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
