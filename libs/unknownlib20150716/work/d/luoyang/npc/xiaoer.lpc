inherit F_VENDOR_SALE;

void create()
{
  set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
  set("shop_id", ({"xiaoer", "xiao", "er", "waiter","er"}));
  set("gender", "男性");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    		"jiudai": "/d/moon/obj/jiudai",
                "gourou": "/d/ourhome/obj/gourou",
                "jinpai" : "/d/obj/misc/tiaozhanpai",
    ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("silver", 1);
}