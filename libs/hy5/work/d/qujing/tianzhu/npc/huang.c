// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_huang_tang");
  set_name("»ÆÌÀ", ({"huang tang", "huang", "tang"}));
  set("shop_id", ({"huangtang", "huang", "tang"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 90000);
  set("age", 38);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/jiuhu",
        "/d/qujing/tianzhu/obj/jiuguan",
        "/d/qujing/tianzhu/obj/jiuzhong",
      }));

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

