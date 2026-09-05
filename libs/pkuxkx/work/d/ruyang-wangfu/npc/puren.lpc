// puren.c -- 王府东院仆人
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

inherit NPC;

void create()
{
	set_name("王府仆人", ({ "pu ren", "puren", "pu" }));
	set("long", "这是一个年纪不大的仆人，随时听候着主人的召唤。\n");
	
	set("gender", "男性");
	set("age", 19);
	set("per", 18);

	set("shen_type", 1);
  set("shen", 10000);
  set("attitude", "peaceful");

	set("combat_exp", 100000);
  		set_skill("unarmed",100);
      set_skill("force", 100);
      set_skill("parry", 100);
      set_skill("dodge", 100);
      set_temp("apply/attack", 100);
      set_temp("apply/defense", 100);
			set_temp("apply/damage",  100);
			
	setup();
	carry_object(__DIR__"obj/puren-fu")->wear();
}