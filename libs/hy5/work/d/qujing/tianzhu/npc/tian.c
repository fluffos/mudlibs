// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_tian_niu");
  set_name("Ìðæ¤", ({"tian niu", "tian", "niu"}));
  set("shop_id", ({"tianniu", "tian", "niu"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 17);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/simao",
         "/d/qujing/tianzhu/obj/fengguan",
        "/d/qujing/tianzhu/obj/longguan",
        "/d/qujing/tianzhu/obj/mukui",
        "/d/qujing/tianzhu/obj/tiekui",
     }));

  setup();
  carry_object("/d/obj/misc/necklace")->wear();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/fengguan")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

