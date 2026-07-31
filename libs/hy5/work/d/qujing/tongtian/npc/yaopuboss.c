inherit NPC;inherit F_DEALER;

void create()
{
  ("tongtian_doctor");
  set_name("³ÂÉ½Ò©", ({"chen shanyao", "chen", "shanyao"}));
  set("shop_id", ({"shanyao", "chen"}));
  set("shop_title", "Ò©Å©");
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 50000);
  set("combat_exp", 30000);

  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ({
        "/d/obj/drug/jinchuang",
         "/d/obj/drug/hunyuandan",
        }));

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}
