// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("虎力大仙", ({"huli daxian", "huli", "daxian" }));
  set("title","国师");
  set_level(750);
  set("long","车迟国的三大道士之一，善于求水祈雨，被尊为国师。\n");
  set("gender", "男性");
  set("rank_info/respect", "国师");
  set("age", 40);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("force_factor", 80);
  set("mana_factor", 40);

  set_skill("unarmed", 750);
  set_skill("dodge", 750);
  set_skill("parry", 750);
  set_skill("spells", 750);
  set_skill("force", 750);
  set_skill("wuxiangforce", 750);
  set_skill("dao", 750);
  set_skill("jindouyun", 750);
  set_skill("puti-zhi", 750);
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("spells", "dao");
  set("eff_dx",-160000);
  set("nkgain",240);
  
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
  
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/chechi/obj/hupi");

  message_vision ("$N软软地倒下，留下一张黄色虎皮。\n",me);
  ob->move(where);
  destruct(me);
}