// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("zhuzi_wan_koufu");
  set_name("万口福", ({"wan koufu", "wan"}));
  set("shop_id", ({"wankoufu", "wan", "koufu"}));
  set("gender", "男性");
  set("shop_title", "万口福");
  set("combat_exp", 10000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ({
         "/d/obj/food/dishes/dish01",
        "/d/obj/food/dishes/dish02",
        "/d/obj/food/dishes/dish03",
         "/d/obj/food/dishes/dish04",
        "/d/obj/food/dishes/dish05",
         "/d/obj/food/dishes/dish06",
        "/d/obj/food/dishes/dish07",
        "/d/obj/food/dishes/dish08",
        "/d/obj/food/dishes/dish09",
        "/d/obj/food/dishes/dish10",
        "/d/obj/food/dishes/dish11",
        "/d/obj/food/dishes/dish12",
        "/d/obj/food/dishes/dish13",
        "/d/obj/food/dishes/dish14",
        "/d/obj/food/dishes/dish15",
        "/d/obj/food/dishes/dish16",
        "/d/obj/food/dishes/dish17",
        "/d/obj/food/dishes/dish18",
        "/d/obj/food/dishes/dish19",
        "/d/obj/food/dishes/dish20",
        "/d/obj/food/dishes/dish21",
        "/d/obj/food/dishes/dish22",
     }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
  remove_call_out ("heheing");
  call_out ("heheing",5+random(10),this_object());
}

void heheing (object who)
{
  if (random(2))
    command("hehe");
  else
    command("bow");
}
