// by snowcat oct 15 1997


inherit F_VENDOR_SALE;

void create()
{
  set_name("米老板", ({"mi laoban", "mi", "laoban"}));
  set("shop_id", ({"laoban"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ([
        "yan": "/d/obj/food/salt",
        "youhulu": "/d/obj/food/youhulu",
        "niangao": "/d/obj/food/niangao",
        "fan": "/d/obj/food/rice",
        "mijiu": "/d/obj/food/mijiu",
        "zongzi": "/d/obj/food/zongzi",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}