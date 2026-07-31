// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("baoxiang_lao_ban");
  set_name("ÀÏ°å", ({"laoban"}));
  set("shop_id", ({"laoban"}));
  set("shop_title", "ÀÏ°å");
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ({
        "/d/qujing/baoxiang/obj/yangtou",
        "/d/qujing/baoxiang/obj/paomo",
        "/d/qujing/baoxiang/obj/zasui",
      }));

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 10);
}
void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

