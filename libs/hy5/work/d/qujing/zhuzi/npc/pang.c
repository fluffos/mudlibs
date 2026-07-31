// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("zhuzi_pang_dianzhu");
  set_name("ÅÖµêÖ÷", ({"pang dianzhu", "dianzhu"}));
  set("shop_id", ({"dianzhu"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set("vendor_goods", ({
        "/d/obj/misc/kuang",
        "/d/obj/cloth/shoupi",
       "/d/obj/weapon/fork/fork",
        "/d/obj/misc/lou",
      }));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
  remove_call_out ("messaging");
  call_out ("messaging",1+random(5),this_object());
}

void messaging (object who)
{
  if (random(2))
    command("hug shou dianniang");
  else
    command("sleepy shou dianniang");
}
