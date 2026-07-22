inherit F_VENDOR_SALE;

void create()
{
  set_name("柳妙手", ({"liu miaoshou","liu"}));
  set("shop_id", ({"doctor"}));
  set("shop_title", "妙手回春");
  set("gender", "男性" );
  set("age", 62);
  set("per", 18);
  set("long", "一位老大夫，好象很有学问的样子。\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("vendor_goods", ([
        "wan": "/d/obj/drug/dieda",
        "dan": "/d/obj/drug/hunyuandan",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/changpao")->wear();
}