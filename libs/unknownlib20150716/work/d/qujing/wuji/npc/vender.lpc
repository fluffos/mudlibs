

inherit F_VENDOR_SALE;

void create()
{
  set_name("叶大嫂", ({"ye dasao", "ye", "dasao", "fruit vendor"}));
  set("shop_id", ({"dasao"}));
  set("shop_title", "水果店大嫂");
  set("gender", "女性");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 20);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    "grape": "/d/obj/food/grape",
    "pear": "/d/obj/food/xueli",
    "strawberry": "/d/obj/food/strawberry",
    "apple": "/d/obj/food/apple",
    "mellon": "/d/obj/food/mellon",
   ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  add_money("silver", 1);
}