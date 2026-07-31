// by snowcat 12/8/1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tianzhu_guo_sanniang");
  set_name("¹ùÈýÄï", ({"guo sanniang", "guo", "sanniang", "niang"}));
  set("shop_id", ({"sanniang", "niang"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 5000);
  set("age", 40);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
        "/d/qujing/tianzhu/obj/toujin",
        "/d/qujing/tianzhu/obj/pitan",
        "/d/qujing/tianzhu/obj/huabu",
        "/d/qujing/tianzhu/obj/baibu",
      }));

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/tianzhu/obj/yinjie")->wear();
}

void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

