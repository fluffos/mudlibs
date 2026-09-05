//zongguan_qianyuan.c -- 前院总管太监
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

inherit NPC;

void create()
{
	set_name("前院总管太监", ({ "zong guan", "tai jian", "zongguan", "zong" }) );
  set("gender", "无性" );
  set("age", 45);
  set("per", 13);
  set("long", "他是汝阳王府回事处的总管太监，在王府，迎来送往的人多了，难免有些矫情。\n");

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
	carry_object(__DIR__"obj/zongguan-fu")->wear();
}

