// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("baoxiang_xi_jiang");
  set_name("Îý½³", ({"xi jiang","jiang"}));
  set("shop_id", ({"xijiang"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 1000);
  set("age", 35);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ({
        "/d/qujing/baoxiang/obj/xihu",
        "/d/qujing/baoxiang/obj/xiwan",
        "/d/qujing/baoxiang/obj/xipen",
      }));

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 15);
}
void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

