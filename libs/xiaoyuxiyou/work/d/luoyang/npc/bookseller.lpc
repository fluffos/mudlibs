
inherit NPC;

void create()
{
  set_name("叶知秋", ({ "ye zhiqiu", "zhiqiu", "ye","bookseller", "seller", "vendor" }) );
  set("shop_id",({"ye zhiqiu", "zhiqiu", "ye","bookseller", "seller", "vendor"}));
  set("gender", "男性" );
  set("age", 37);
  set("title", "才高八斗");
  set("long","这位老板不但才高八斗，而且还曾是当今皇太子的老师。\n");
  set("combat_exp", 40000);
  set("daoxing", 20000);

  set_skill("dodge", 500);
  set_skill("parry", 600);
  set_skill("unarmed", 500);
  set_skill("jinghun-zhang", 500);
  set_skill("literate", 70);
  set("attitude", "friendly");
  map_skill("unarmed", "jinghun-zhang");
  set("str", 1000);
  set("rank_info/respect", "叶知秋");
  set("per",25);
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}