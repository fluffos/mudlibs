// by snowcat 12/8/1997

inherit F_VENDOR_SALE;
//inherit F_VENDOR;
//inherit NPC;


void create()
{
  set_name("侯郎中", ({"hou langzhong", "hou", "langzhong"}));
  set("shop_id", ({"langzhong", "hou"}));
  set("shop_title", "老郎中");
  set("gender", "男性");
  set("combat_exp", 50000);
  set("daoxing", 30000);

  set("age", 48);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ([
        "wan": "/d/qujing/tianzhu/obj/wan",
        "fen": "/d/qujing/tianzhu/obj/fen",
        "dan": "/d/qujing/tianzhu/obj/dan",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}