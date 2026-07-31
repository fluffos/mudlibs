// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("biqiu_kusi_kusi");
  set_name("库司库司", ({"kusi kusi", "kusi", "boss"}));
  set("shop_id", ({"kusi"}));
  set("shop_title", "库司");
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/biqiu/obj/tangmian",
        "/d/qujing/biqiu/obj/niutang",
     }));

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}
