// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("yuhua_jiu_bao");
  set_name("¾Æ±£", ({"jiu bao", "jiubao", "bao"}));
  set("shop_id", ({"jiubao", "bao"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/yuhua/obj/pig",
        "/d/qujing/yuhua/obj/lamb",
        "/d/obj/food/baijiu",
        "/d/obj/food/jiunang",
      }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}
