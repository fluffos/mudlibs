// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/huxianfeng.c

inherit NPC;
void create()
{
	set_name("虎先锋", ({"hu xianfeng", "hu", "xianfeng"}));
	set("gender", "男性" );
	set("age", 43);
	set("per", 112);//no rongmao description.
	set("long", "黄风大王部下的前路先锋，是黄风大王最得力的助手。\n武艺高强，做事干净利落，又善于拍马屁，\n所以这黄风山上他是一人之下万人之上。\n");
	set("class", "yaomo");
	set_level(60);
	set("attitude", "peaceful");
	set_skill("unarmed",600);
	set_skill("cuixin-zhang",600);
	set_skill("dodge",600);
	set_skill("xiaoyaoyou",600);
	set_skill("parry",600);
	set_skill("force",600);  
	set_skill("ningxie-force",600);
	set_skill("literate",600);
	set_skill("spells",600);
	set_skill("dengxian-dafa",600);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill ("parry","cuixin-zhang");

	set("force_factor",600);
	set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

	setup();
	carry_object("/d/qujing/huangfeng/obj/hupi")->wear();
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/huangfeng/obj/hupi");

  message_vision ("$N惨叫声中翻身倒地，轻烟过处，只留下一张老虎皮。\n",me);
  ob->move(where);
  destruct(me);
}
