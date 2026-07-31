// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("qinfa_sun_xiaoer");
  set_name("ËïÐ¡¶þ", ({"sun xiaoer", "sun", "xiaoer", "xiao", "er"}));
  set("shop_id", ({"xiaoer", "xiao", "er"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
    "/d/obj/cloth/piyi",
    "/d/obj/cloth/bullboots",
    "/d/obj/cloth/beixin",
  }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init ()
{
  ::init();
add_action("do_buy", "buy");add_action("do_list", "list");
}
