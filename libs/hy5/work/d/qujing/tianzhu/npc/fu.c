// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_fu_sao");
  set_name("¸£É©", ({"fu sao", "sao", "fu"}));
  set("shop_id", ({"fusao", "sao", "fu"}));
  set("shop_title", "°¢¸£É©");
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 30);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/guazi",
        "/d/qujing/tianzhu/obj/chaodou",
        "/d/qujing/tianzhu/obj/dangao",
        "/d/qujing/tianzhu/obj/jiansu",
      }));

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/yunxue")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

