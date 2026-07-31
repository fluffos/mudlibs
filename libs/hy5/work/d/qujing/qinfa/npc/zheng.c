// by snowcat oct 15 1997


inherit NPC;inherit F_DEALER;

void create()
{
  ("qinfa_zheng_guafu");
  set_name("Ö£¹Ñ¸¾", ({"zheng guafu", "zheng", "guafu", "fu"}));
  set("shop_id", ({"guafu", "fu"}));
  set("gender", "Å®ÐÔ");
  set("combat_exp", 50000);
  set("max_qi", 1000);
  set("qi", 1000);
  set("max_jing", 1000);
  set("jing", 1000);
  set("age", 30);
  set("per", 21);
  set("env/wimpy", 90);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ({
    "/d/qujing/qinfa/obj/guo",
    "/d/qujing/qinfa/obj/wan",
    "/d/qujing/qinfa/obj/chong",
 }));
  setup();
  set_temp("no_guo",0);
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init ()
{
  ::init();
         add_action("do_buy", "buy");add_action("do_list", "list");
}

