// by snowcat 12/8/1997

inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_doctor_tianzhu");
  set_name("ºîÀÉÖÐ", ({"hou langzhong", "hou", "langzhong"}));
  set("shop_id", ({"langzhong", "hou"}));
  set("shop_title", "ÀÏÀÉÖÐ");
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 50000);
  set("combat_exp", 30000);

  set("age", 48);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/wan",
        "/d/qujing/tianzhu/obj/fen",
        "/d/qujing/tianzhu/obj/dan",
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

ÿ
