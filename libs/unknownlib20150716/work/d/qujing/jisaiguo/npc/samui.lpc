

inherit F_VENDOR_SALE;

void create()
{
  set_name("萨米儿大叔", ({"uncle samui","samui"}));
  set("shop_id", ({"uncle", "samui"}));

  set("gender", "男性" );
  set("age", 65);
  set("long", "一位光头小胡子，黄发蓝眼睛的老人，很风趣的样子。\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "peaceful");
  set("per", 15);
  set("vendor_goods", ([
        "roubing": "/d/obj/food/roubing",
        "yangtui": "/d/qujing/jisaiguo/obj/yangtui",
        "jiunang": "/d/obj/food/jiunang",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/qujing/jisaiguo/obj/changpao")->wear();
}