// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  set_name("甜妞", ({"tian niu", "tian", "niu"}));
  set("shop_id", ({"tianniu", "tian", "niu"}));
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 17);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "simao": "/d/qujing/tianzhu/obj/simao",
        "fengguan": "/d/qujing/tianzhu/obj/fengguan",
        "longguan": "/d/qujing/tianzhu/obj/longguan",
        "mukui": "/d/qujing/tianzhu/obj/mukui",
        "tiekui": "/d/qujing/tianzhu/obj/tiekui",
      ]) );

  setup();
  carry_object("/d/obj/misc/necklace")->wear();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/fengguan")->wear();
}