// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("biqiu_binu_muyi");
  set_name("±ÌÅ«Ä½ÒÁ", ({"binu muyi", "muyi", "boss"}));
  set("shop_id", ({"muyi"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/obj/misc/hualan",
        "/d/obj/misc/vase",
      }));

  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}
