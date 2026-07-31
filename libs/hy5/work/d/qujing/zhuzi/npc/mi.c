// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("zhuzi_mi_laoban");
  set_name("Ã×ÀÏ°å", ({"mi laoban", "mi", "laoban"}));
  set("shop_id", ({"laoban"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 50);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ({
        "/d/obj/food/salt",
        "/d/obj/food/youhulu",
        "/d/obj/food/niangao",
        "/d/obj/food/rice",
        "/d/obj/food/mijiu",
        "/d/obj/food/zongzi",
      }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
  call_out ("winking",random(10),this_object());
}

void winking (object who)
{
  if (random(2))
    command("wink2");
  else
    command("wink2 "+who->query("id"));
}
