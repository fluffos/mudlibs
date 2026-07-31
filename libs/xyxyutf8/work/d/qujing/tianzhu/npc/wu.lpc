#include <ansi.h>


inherit F_VENDOR_SALE;

void create()
{
  set_name("吴老板", ({ "wu laoban", "wu", "laoban" }) );
  set("shop_id", ({"laoban"}));
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);
  set("vendor_goods", ([
        "zuanjie": "/d/qujing/tianzhu/obj/zuanjie",
        "baijie": "/d/qujing/tianzhu/obj/baijie",
        "jinjie": "/d/qujing/tianzhu/obj/jinjie",
        "baojie": "/d/qujing/tianzhu/obj/baojie",
        "yinjie": "/d/qujing/tianzhu/obj/yinjie",
       "hanyu" : "/d/obj/yelian/hanyu",
      ]) );

  setup();

  carry_object("/d/qujing/tianzhu/obj/piyi")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixue")->wear();
  carry_object("/d/qujing/tianzhu/obj/longguan")->wear();
}
