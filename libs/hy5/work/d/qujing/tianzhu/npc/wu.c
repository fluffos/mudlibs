#include <ansi.h>


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_wu_laoban");
  set_name("ÎâÀÏ°å", ({ "wu laoban", "wu", "laoban" }) );
  set("shop_id", ({"laoban"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_qi", 200);
  set("max_jing", 200);
  set("neili", 200);
  set("max_neili", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/zuanjie",
         "/d/qujing/tianzhu/obj/baijie",
        "/d/qujing/tianzhu/obj/jinjie",
        "/d/qujing/tianzhu/obj/baojie",
         "/d/qujing/tianzhu/obj/yinjie",
      }));

  setup();

  carry_object("/d/qujing/tianzhu/obj/piyi")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixue")->wear();
  carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

