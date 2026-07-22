inherit F_VENDOR_SALE;

void create()
{
  set_name("阿依娜", ({"a yina","yina"}));
  set("shop_id",({"yina"}));
  set("gender", "女性" );
  set("age", 22);
  set("per", 25);
  set("long", "一位大眼睛，长辫子的姑娘。\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
  set("vendor_goods", ([
        "dagger": "/d/qujing/jisaiguo/obj/silverdagger",
        "necklace": "/d/qujing/jisaiguo/obj/silverneck",
        "ring": "/d/qujing/jisaiguo/obj/silverring",
        "wrist": "/d/qujing/jisaiguo/obj/silverwrist",
     "yinkuang" : "/d/obj/yelian/yin",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/qujing/jisaiguo/obj/changpao")->wear();
}