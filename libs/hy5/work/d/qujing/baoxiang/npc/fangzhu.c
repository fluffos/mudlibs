//Cracked by Roath
// by snowcat oct 15 1997

inherit NPC;inherit F_DEALER;

void create()
{

  set_name("·»Ö÷", ({"fang zhu","zhu"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 1000);
  set("age", 46);
  set("per", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ({
        "/d/qujing/baoxiang/obj/cspitan",
        "/d/qujing/baoxiang/obj/bpitan",
        "/d/qujing/baoxiang/obj/yizi",
       "/d/qujing/baoxiang/obj/zhuozi",
      "/d/qujing/baoxiang/obj/guatan",
      }));

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 5);
}
void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

