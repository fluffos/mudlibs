// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("zhuzi_hefa_laotong");
  set_name("º×·¢ÀÏÍ¯", ({"hefa laotong", "laotong"}));
  set("shop_id", ({"laotong"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 60);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ({
        "/d/qujing/zhuzi/obj/yao",
        "/d/qujing/zhuzi/obj/yaozhan",
      }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  add_money("silver", 10);
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

