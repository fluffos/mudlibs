// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("qinfa_li_guafu");
  set_name("Àî¹Ñ¸¾", ({"li guafu", "li", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
    "/d/obj/cloth/choupao",
    "/d/obj/cloth/magua",
    "/d/obj/cloth/ziyi",
    "/d/obj/cloth/hat",
    "/d/obj/cloth/buxie",
  }));
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
add_action("do_buy", "buy");add_action("do_list", "list");
}
