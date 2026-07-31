// created by angell 1/1/2001
// room: /d/qujing/huangfeng/npc/yaoboss.c

inherit NPC;inherit F_DEALER;

void create()
{
  ("huangfeng_doctor_huangfeng");
  set_name("王老板", ({"wang laoban", "wang", "laoban"}));
  set("shop_id", ({"laoban", "wang","wang laoban" }));
  set("shop_title", "郎中");
  set("gender", "男性");
  set("combat_exp", 50000);
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

