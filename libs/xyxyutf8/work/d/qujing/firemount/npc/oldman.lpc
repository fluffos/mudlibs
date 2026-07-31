// rewritten by snowcat on 4/12/1997

inherit NPC;

void create()
{
  set_name("老者", ({"oldman","man"}));
  set("gender", "男性");
  set("age", 60);
  set("long","这是一位常住此地的老人。白眉白须，铜面碧眼，极为和蔼。\n"); 
  set("attitude", "friendly");
  set_level(1);
  set("per", 25);
  set_skill("dodge", 10);
  setup();

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);
}

int accept_fight(object me)
{
  say("老者颤危危地说道："+RANK_D->query_respect(me)+"饶了我这点老命吧。\n");
  return 0;
}
