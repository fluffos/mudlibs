// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("biqiu_kan_duli");
  set_name("¿²¶¼Á¦", ({"kan duli", "duli", "boss"}));
  set("shop_id", ({"kanduli", "duli"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/biqiu/obj/shaoe",
        "/d/qujing/biqiu/obj/zhengya",
        "/d/obj/food/baijiu",
      }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}
