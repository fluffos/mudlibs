// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_wei_dasao");
  set_name("Îº´óÉ©", ({"wei dasao", "wei", "dasao", "sao"}));
  set("shop_id", ({"dasao", "sao", "wei"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 30);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/xiancai",
         "/d/qujing/tianzhu/obj/douya",
         "/d/qujing/tianzhu/obj/huacai",
         "/d/qujing/tianzhu/obj/shansun",
         "/d/qujing/tianzhu/obj/mogu",
         "/d/qujing/tianzhu/obj/muer",
      }));

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

