//zongguan_neizhai.c -- 内宅总管太监
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

inherit NPC;

void create()
{
	set_name("内宅总管太监", ({ "zong guan", "tai jian", "zongguan", "zong" }) );
  set("gender", "无性" );
  set("age", 55);
  set("per", 23);
	set("long", "他是汝阳王府的内宅总管太监，王府内宅杂七杂八的事，他都说了算。\n");
  
  set("shen_type", -1);
  set("shen", 50000);
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
	carry_object(__DIR__"obj/tie_key");			
	carry_object(__DIR__"obj/zongguan-fu")->wear();

}
