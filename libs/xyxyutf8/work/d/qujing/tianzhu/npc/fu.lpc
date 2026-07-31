// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  set_name("福嫂", ({"fu sao", "sao", "fu"}));
  set("shop_id", ({"fusao", "sao", "fu"}));
  set("shop_title", "阿福嫂");
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 30);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "guazi": "/d/qujing/tianzhu/obj/guazi",
        "chaodou": "/d/qujing/tianzhu/obj/chaodou",
        "dangao": "/d/qujing/tianzhu/obj/dangao",
        "jiansu": "/d/qujing/tianzhu/obj/jiansu",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/yunxue")->wear();
}