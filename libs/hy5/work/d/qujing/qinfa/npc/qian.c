// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;
#include "/d/migong/romnpc2.c"
void create()
{
  ("qinfa_qian_guafu");
  set_name("Ç®¹Ñ¸¾", ({"qian guafu", "qian", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
    "/d/obj/misc/kuang",
    "/d/obj/misc/shaoba",
    "/d/obj/misc/bag",
    "/d/qujing/qinfa/obj/jingang",
  }));
  setup();
  initlvl((600+random(700)),54);
  carry_object("/d/qujing/qinfa/obj/dao");
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
add_action("do_buy", "buy");add_action("do_list", "list");
}
