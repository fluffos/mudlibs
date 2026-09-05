// menfang.c -- 王府前院门房
//Zone: 汝阳王府
//Describe text by ddid
//2009-6-1

inherit NPC;

void create()
{
	set_name("王府门房", ({ "men fang", "menfang", "men", "fang" }));
	set("long", "一个年轻的小伙子，负责在汝阳王府看门。\n");
	
	set("gender", "男性");
	set("age", random(5) + 20);
	set("per", 18);

	set("shen_type", -1);
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
