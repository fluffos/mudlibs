// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_tao_niangzi");
  set_name("ÌÕÄï×Ó", ({"tao niangzi", "tao", "niangzi"}));
  set("shop_id", ({"niangzi", "tao"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 2000);
  set("age", 40);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/hongqun",
        "/d/qujing/tianzhu/obj/huaqun",
        "/d/qujing/tianzhu/obj/baipao",
        "/d/qujing/tianzhu/obj/huapao",
        "/d/qujing/tianzhu/obj/pifeng",
        "/d/qujing/tianzhu/obj/dachang",
      }));

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/yinjie")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

