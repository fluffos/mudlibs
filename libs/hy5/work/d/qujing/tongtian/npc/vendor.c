// by snowcat dec 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("tongtian_chen_sanxian");
  set_name("陈三鲜", ({"chen sanxian","chen"}));
  set("title", "水鲜贩子");
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ({
        "/d/qujing/tongtian/obj/zhengxie",
        "/d/qujing/tongtian/obj/shaoxia",
        "/d/qujing/tongtian/obj/xunyu",
        "/d/qujing/tongtian/obj/zuiluo",
      }));

  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
  add_money("silver", 5);
}
void init()
{
  ::init();
  add_action("do_buy", "buy");add_action("do_list", "list");
}

